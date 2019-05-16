#include "histroy.h"

int Histroy::getId() const
{
    return id;
}

double Histroy::getTradeNumber() const
{
    return tradeNumber;
}

string Histroy::getType()
{
    return type;
}

string Histroy::getRemark()
{
    return remark;
}

QDateTime Histroy::getTime() const
{
    return time;
}

Histroy::Histroy(int a,double b,QDateTime t,string d,string e)
{
    id=a;
    tradeNumber=b;
    time=t;
    type=d;
    remark=e;
}
