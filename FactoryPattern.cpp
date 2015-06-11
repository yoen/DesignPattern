// FactoryPattern.cpp

/*工厂方法模式：
	一个抽象产品类，可以派生出多个具体产品类。   
	一个抽象工厂类，可以派生出多个具体工厂类。   
	每个具体工厂类只能创建一个具体产品类的实例。

*/
#include <iostream>
#include <memory>
using namespace std;

class Sender{
public:
	virtual void send(){};
};

class MailSender:public Sender{
public:
	virtual void send(){
		std::cout<< "mail sender send" << std::endl;
	};
};

class SMSSender:public Sender{
public:
	virtual void send(){
		std::cout<< "sms sender send" << std::endl;
	};

};
typedef shared_ptr<Sender> Sender_Ptr;

class Factory{
public:
	virtual Sender_Ptr product(){return NULL;};
};

class MailFactory:public Factory{
public:
	virtual Sender_Ptr product(){return make_shared<MailSender>();}

};
class SMSFactory:public Factory{
public:
	virtual Sender_Ptr product(){return make_shared<SMSSender>();}
};

typedef shared_ptr<Factory> Factor_Ptr;

int main(int argc, _TCHAR* argv[])
{
	Factor_Ptr fator = make_shared<SMSFactory>();
	Sender_Ptr sender = fator->product();
	sender->send();
	getchar();
	return 0;
}

