#include "usermessage.h"

UserMessage* UserMessage::zs=nullptr;
UserMessage* UserMessage::ls=nullptr;

string UserMessage::getPassWord() const
{
    return passWord;
}

string UserMessage::getUserName() const
{
    return userName;
}

UserMessage::UserMessage(string userName,string passWord)
{
    this->userName=userName;
    this->passWord=passWord;
    MAP["333"]=*new CardMessage();
}

UserMessage* UserMessage::getZSmessage1(){
    if(zs==nullptr){
        zs=new UserMessage("zs","123");
        //ls=new UserMessage("ls","1234");
    }
    return zs;
}

UserMessage* UserMessage::getLSmessage1(){
    if(ls==nullptr){
        ls=new UserMessage("ls","1234");
        }
    return ls;
}

map<string,CardMessage> UserMessage::getMap(){
    return MAP;
}

UserMessage* getMessage(string a){
    if(a=="zs")
        return UserMessage::getZSmessage1();
    else if(a=="ls")
        return UserMessage::getLSmessage1();
    else
        return nullptr;
};
