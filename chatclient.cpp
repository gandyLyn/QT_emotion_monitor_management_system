#include "chatclient.h"
#include "ui_chatclient.h"
#include <QAction>

chatClient::chatClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chatClient)
{
    ui->setupUi(this);
    a = new QAction("haha");
    ui->listView->addAction(a);
    ui->listView->show();
}

chatClient::~chatClient()
{
    delete ui;
}
