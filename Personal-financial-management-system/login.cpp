#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->textWarning->hide();
}

Login::~Login()
{
    delete ui;
}

void Login::on_cancelButton_clicked()
{
        this->close();
}

void Login::on_loginButton_clicked()
{
    string userName=ui->userName->text().toStdString();
    string passWord=ui->passWord->text().toStdString();
    extern UserMessage* getMessage(string);
    UserMessage *a=getMessage(userName);
    if(a!=nullptr && passWord==a->getPassWord())   //首先对比用户名，若存在则返回该用户信息实例并且对比其密码信息
    {
        MainWindow *a=new MainWindow ();
        connect(this,SIGNAL(sendData(UserMessage *)),a,SLOT(getUser(UserMessage *)));
        extern UserMessage* getMessage(string);
        sendData(getMessage(userName));
        ui->textWarning->hide();
        QMessageBox::about(nullptr,"成功！","登录成功！");
        a->show();
        this->close();
    }else{
        ui->textWarning->show();
        ui->passWord->clear();
    }
}
