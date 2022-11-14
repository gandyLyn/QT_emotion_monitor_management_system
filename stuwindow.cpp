#include "stuwindow.h"
#include "ui_stuwindow.h"
#include <QDebug>

StuWindow::StuWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StuWindow)
{
    ui->setupUi(this);
}

StuWindow::~StuWindow()
{
    delete ui;
}



void StuWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    qDebug()<<item->text(column)<<column;
    QString opt = item->text(column);
    if("群聊功能" == opt)
    {
        qDebug()<<"OK";
        if(NULL == client) //切记在类定义里把client初始化为NULL，否则程序会崩溃
            client = new chatClient();

        client->show();
    }
}

void StuWindow::on_btn_exit_clicked()
{
    this->close();
}
