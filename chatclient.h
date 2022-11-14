#ifndef CHATCLIENT_H
#define CHATCLIENT_H

#include <QWidget>
#include <QListView>
#include <QAction>

namespace Ui {
class chatClient;
}

class chatClient : public QWidget
{
    Q_OBJECT

public:
    explicit chatClient(QWidget *parent = nullptr);
    ~chatClient();

private:
    Ui::chatClient *ui;
    QAction *a;
};

#endif // CHATCLIENT_H
