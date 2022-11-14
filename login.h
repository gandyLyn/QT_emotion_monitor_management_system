#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "data_define.h"
#include "mainwindow.h"
#include "stuwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QWidget
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_btn_login_clicked();

private:
    Ui::login *ui;
    QSqlDatabase db;
    QString account,password;
    mainWindow *win;
    StuWindow *stuWin;

    void accessToDB(int opt);
};
#endif // LOGIN_H
