#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->model1->hide();
    QRegExp regx("[0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->amount );
    QValidator *validator1 = new QRegExpValidator(regx, ui->balance );
    ui->balance->setValidator(validator1);
    ui->amount->setValidator( validator );
    QValidator *validator2 = new QRegExpValidator(regx, ui->cardNumber );
    ui->cardNumber->setValidator(validator2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
        ui->model1->show();
        ui->bankName->setEnabled(true);
        ui->searchButton->setEnabled(false);
        ui->balance->setEnabled(true);
        ui->confirmButton->setEnabled(true);
        ui->resetButton->setEnabled(true);
        ui->addButton->setEnabled(false);
        ui->model1->setText("添加卡模式");
        ui->model1->show();
}

void MainWindow::on_quitButton_clicked()
{
    this->close();
}

void MainWindow::on_searchButton_clicked()
{
    string cardNumber=ui->cardNumber->text().toStdString();
    extern UserMessage* getLSmessage();
    l_it=MAP.find(cardNumber);
    if(l_it==MAP.end()||ui->passWord->text().toStdString()!=l_it->second.getPassWord())
        QMessageBox::about(nullptr,"失败","密码错误或卡号不存在！");
    else{
        ui->bankName->setText(QString::fromStdString(l_it->second.getBankName()));
        ui->balance->setText(QString::number(l_it->second.getBalance()));
        enterTrainModel();
    }
}

void MainWindow::getUser(UserMessage *a){
    uesr = a;
    MAP=uesr->getMap();  
    ui->welCome->setText(QString("欢迎 %1 用户").arg(QString::fromStdString(uesr->getUserName())));
}

void MainWindow::on_confirmButton_clicked()
{
    string cardNumber=ui->cardNumber->text().toStdString();
    string passWord=ui->passWord->text().toStdString();
    string bankName=ui->bankName->text().toStdString();
    double balance=ui->balance->text().toDouble();

    map<string , CardMessage>::iterator l_it;
    l_it=MAP.find(cardNumber);
    if(l_it==MAP.end())
    {
        MAP[cardNumber]=CardMessage(passWord,2,bankName,balance);
        enterTrainModel();
    }else if(ui->confirmButton->text()=="交易"){
        Histroy *a=nullptr;
        double b;
        if(ui->amount->text().length()==0)
        {
            QMessageBox::about(nullptr,"金额为空","金额为空！");
            return;
        }
        if(ui->radioButton->isChecked())
        {
            b=MAP[cardNumber].getBalance()+(ui->amount->text()).toDouble();
            MAP[cardNumber].setBalance(b);
            a=new Histroy(MAP[cardNumber].setI(),ui->amount->text().toDouble(),
                          QDateTime::currentDateTime(),"收入",ui->remarks->text().toStdString());
        }else{
            b=MAP[cardNumber].getBalance()-(ui->amount->text()).toDouble();
            if(b<0)
            {
                QMessageBox::about(nullptr,"失败","余额不足！");
                return;
            }
            MAP[cardNumber].setBalance(b);
            a=new Histroy(MAP[cardNumber].setI(),ui->amount->text().toDouble(),
                          QDateTime::currentDateTime(),"支出",ui->remarks->text().toStdString());
        }
        MAP[cardNumber].addHistroy(a);
        ui->balance->setText(QString::number(b));
        ui->amount->clear();
        ui->remarks->clear();
        QMessageBox::about(nullptr,"成功","交易成功！");
    }else if(!ui->cardNumber->isEnabled()){
        MAP[cardNumber].setPassWord(passWord);
        MAP[cardNumber].setBankName(bankName);
        enterTrainModel();
        QMessageBox::about(nullptr,"成功","修改成功！");
    }
    else{
        QMessageBox::about(nullptr,"失败","卡号已存在！");
        ui->passWord->clear();
        ui->bankName->clear();
        ui->passWord->clear();
        ui->bankName->clear();
}
}

void MainWindow::on_resetButton_clicked()
{
    l_it=MAP.begin();
    ui->cardNumber->clear();
    ui->cardNumber->setEnabled(true);
    ui->passWord->clear();
    ui->passWord->setEnabled(true);
    ui->bankName->clear();
    ui->bankName->setEnabled(false);
    ui->bankName->clear();
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
    ui->radioButton->setChecked(false);
    ui->radioButton_2->setChecked(false);
    ui->amount->setEnabled(false);
    ui->amount->clear();
    ui->remarks->setEnabled(false);
    ui->remarks->clear();
    ui->balance->setEnabled(false);
    ui->balance->clear();
    ui->addButton->setEnabled(true);
    ui->modifyButton->setEnabled(false);
    ui->manageButton->setEnabled(false);
    ui->confirmButton->setText("确定");
    ui->model1->hide();
    ui->confirmButton->setEnabled(false);
}


void MainWindow::enterTrainModel(){
    ui->addButton->setEnabled(false);
    ui->radioButton->setChecked(true);
    ui->confirmButton->setText("交易");
    ui->confirmButton->setEnabled(true);
    ui->cardNumber->setEnabled(false);
    ui->passWord->setEnabled(false);
    ui->bankName->setEnabled(false);
    ui->radioButton_2->setEnabled(true);
    ui->radioButton->setEnabled(true);
    ui->remarks->setEnabled(true);
    ui->amount->setEnabled(true);
    ui->balance->setEnabled(false);
    ui->model1->show();
    ui->model1->setText("交易模式");
    ui->manageButton->setEnabled(true);
    ui->modifyButton->setEnabled(true);
    ui->searchButton->setEnabled(true);
    QMessageBox::about(nullptr,"成功","进入交易模式");
}

void MainWindow::on_modifyButton_clicked()
{
    ui->amount->setEnabled(false);
    ui->remarks->setEnabled(false);
    ui->passWord->setEnabled(true);
    ui->bankName->setEnabled(true);
    ui->confirmButton->setText("确定");
    ui->addButton->setEnabled(false);
    ui->manageButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
    ui->radioButton->setEnabled(false);
    ui->model1->setText("修改卡");
}

void MainWindow::on_manageButton_clicked()
{
    TrainMessage *a=new TrainMessage();
    a->show();
    connect(this,SIGNAL(sendData(pair <string,CardMessage>)),a,SLOT(getId(pair <string,CardMessage>)));
    pair <string,CardMessage> pr (ui->cardNumber->text().toStdString(),MAP[ui->cardNumber->text().toStdString()]);
    sendData(pr);
}
