#ifndef USERMESSAGE_H
#define USERMESSAGE_H
#include <string>
#include "cardmessage.h"
#include <map>

/*
 * 用户信息
 */

using namespace std;

class UserMessage
{
private:
    string userName;
    string passWord;
    map<string,CardMessage> MAP;   //以卡号为键，以卡的信息为值
    static UserMessage *zs;  //用户实例对象zs
    static UserMessage *ls;  //用户实例对象ls
    UserMessage(string userName,string passWord);  //单例构造函数

public:
    static UserMessage* getZSmessage1();   //获取用户zs
    static UserMessage* getLSmessage1();   //获取用户ls
    string getUserName() const;
    string getPassWord() const;
    map<string,CardMessage> getMap();
};

#endif // USERMESSAGE_H
