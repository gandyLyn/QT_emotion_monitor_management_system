#include "login.h"
#include "ui_login.h"
#include <QDebug>


login::login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}


void login::on_btn_login_clicked()
{
    QString type = ui->cob_identity->currentText();
    int opt = ui->cob_identity->currentIndex(); //获取身份
    account = ui->le_account->text();
    password = ui->le_password->text();

    if(account.isEmpty() || password.isEmpty())
    {
        QMessageBox::warning(this,"信息不全!","账号或密码不能为空！");
        return;
    }
    qDebug()<<type<<opt<<account<<password;

    accessToDB(opt);//根据身份选择对应的数据库表，并查找相应的账号密码
}

void login::accessToDB(int opt)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("emotion_monitor");
    db.setUserName("root");
    db.setPassword("324");

    if(!db.open())
    {
        QMessageBox::warning(this,"错误","数据库打开失败，请重试");
        return;
    }

    QSqlQuery query(db);
    QString sql;
    switch(opt)
    {
    case 0: //管理员数据库表

    case 1: //教师数据库表
        sql = QString("select * from teacher where "
                      "id=%1 and password='%2' ").arg(account).arg(password);
        if(query.exec(sql))
        {
            win = new mainWindow();
            win->show();
            this->hide();
        }
        break;
    case 2: // 学生数据库表
        sql = QString("select * from student where "
                      "id=%1 and password='%2' ").arg(account).arg(password);
        if(query.exec(sql))
        {
            stuWin = new StuWindow();
            stuWin->show();
            this->hide();
        }
        break;
    default:
        QMessageBox::warning(this,"登陆出错","账号密码错误！");
    }

    return;
}
