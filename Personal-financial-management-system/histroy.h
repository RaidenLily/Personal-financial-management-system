#ifndef HISTROY_H
#define HISTROY_H
#include <string>
#include <QDateTime>

/*
 * 历史交易信息
 */

using namespace std;

class Histroy
{
private:
    int id;
    double tradeNumber;
    //string dateTime;
    string type;
    string remark;
    QDateTime time;

public:
    Histroy(int,double,QDateTime,string,string);
    int getId() const;
    double getTradeNumber() const;
    string getType();
    string getRemark();
    QDateTime getTime() const;
};

#endif // HISTROY_H
