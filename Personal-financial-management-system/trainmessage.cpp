#include "trainmessage.h"
#include "ui_trainmessage.h"

TrainMessage::TrainMessage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TrainMessage)
{
    ui->setupUi(this);
}

TrainMessage::~TrainMessage()
{
    delete ui;
}

void TrainMessage::on_pushButton_5_clicked()
{
    this->close();
}

void TrainMessage::getId(pair <string,CardMessage> a){
    ui->cardNumber->setText(QString::fromStdString(a.first));
    this->a = a.second.getHistroy();
    if(this->a.size()==0){
        ui->next->setEnabled(false);
        ui->last->setEnabled(false);
        ui->firstButton->setEnabled(false);
        ui->previous->setEnabled(false);
        ui->label_9->setText(QString::number(0));
        return ;
    }
    it=this->a.begin();
    ui->label_9->setText(QString::number(this->a.size()));
    setText();
}

void TrainMessage::on_previous_clicked()
{
    if(it==a.begin()){
        QMessageBox::about(nullptr,"注意","已是第一条！");
    }
    else {
        it--;
        setText();
    }
}

void TrainMessage::setText(){
    ui->id->setText(QString::number(it->getId()));
    ui->amount->setText(QString::number(it->getTradeNumber()));
    ui->model->setText(QString::fromStdString(it->getType()));
    ui->remarks->setText(QString::fromStdString(it->getRemark()));
    ui->time->setText(it->getTime().toString("yyyy.MM.dd hh:mm:ss"));
}

void TrainMessage::on_next_clicked()
{
    {
        if(it==a.end()-1){
            QMessageBox::about(nullptr,"注意","已是最后一条！");
        }
        else {
            it++;
            setText();
        }
    }
}

void TrainMessage::on_last_clicked()
{
    it=this->a.end()-1;
    setText();
}

void TrainMessage::on_firstButton_clicked()
{
    it=this->a.begin();
    setText();
}
