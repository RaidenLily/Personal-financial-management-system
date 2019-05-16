#ifndef CARDMESSAGE_H
#define CARDMESSAGE_H
#include <string>
#include <histroy.h>
#include <vector>

/*
 * 信用卡信息
 */

using namespace std;

class CardMessage
{
private:
    string passWord;//交易密码
    int userId;//所属用户号
    string bankName;//银行名称
    double balance;//余额
    vector<Histroy> a;//交易历史记录
    int i=0;

public:
    CardMessage(string passWord="123",int userId=1,string bankName="中国银行",double balance=100); //默认初始化

    string getPassWord() const;
    int getUserId() const;
    string getBankName() const;
    double getBalance();
    void setBalance(double value);
    void setPassWord(const string &value);
    void setBankName(const string &value);
    void addHistroy(Histroy *);
    vector<Histroy> getHistroy();
    int getI() ;
    int setI();
};

#endif // CARDMESSAGE_H
