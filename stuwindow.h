#ifndef STUWINDOW_H
#define STUWINDOW_H

#include <QWidget>
#include <QTreeWidget>
#include "chatclient.h"

namespace Ui {
class StuWindow;
}

class StuWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StuWindow(QWidget *parent = nullptr);
    ~StuWindow();

private slots:

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_btn_exit_clicked();

private:
    Ui::StuWindow *ui;
    chatClient  *client = NULL;
};

#endif // STUWINDOW_H
