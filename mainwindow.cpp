#include "mainwindow.h"
#include "ui_mainwindow.h"

mainWindow::mainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    //ui->treeWidget->se
}

mainWindow::~mainWindow()
{
    delete ui;
}
