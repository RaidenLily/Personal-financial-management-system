#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <string>
#include <usermessage.h>
#include <mainwindow.h>
#include <QMessageBox>

/*
 * 登录界面
 */

using namespace std;

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    string getUser();
    ~Login();

private slots:

    void on_cancelButton_clicked();

    void on_loginButton_clicked();

signals:
    void  sendData(UserMessage *);

private:
    Ui::Login *ui;

    UserMessage *zs;
    UserMessage *ls;
};

#endif // LOGIN_H
