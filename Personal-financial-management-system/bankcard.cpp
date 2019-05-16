#include "bankcard.h"
#include "ui_bankcard.h"

BankCard::BankCard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BankCard)
{
    ui->setupUi(this);
}

BankCard::~BankCard()
{
    delete ui;
}
