#include "cardmessage.h"

int CardMessage::getUserId() const
{
    return userId;
}

string CardMessage::getPassWord() const
{
    return passWord;
}

string CardMessage::getBankName() const
{
    return bankName;
}

double CardMessage::getBalance()
{
    return balance;
}

void CardMessage::setBalance(double value)
{
    balance = value;
}

void CardMessage::setPassWord(const string &value)
{
    passWord = value;
}

void CardMessage::setBankName(const string &value)
{
    bankName = value;
}

int CardMessage::getI()
{
    return i;
}

int CardMessage::setI()
{
    return ++i;
}

CardMessage::CardMessage(string passWord,int userId,string bankName,double balance)
{
    this->passWord=passWord;
    this->userId=userId;
    this->bankName=bankName;
    this->balance=balance;
}

void CardMessage::addHistroy(Histroy *b){
    a.push_back(*b);
}

vector<Histroy> CardMessage::getHistroy(){
    return a;
}
