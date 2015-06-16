// AbstractFactoryPattern.cpp : Defines the entry point for the console application.
//
/*
 @header     AbstractFactoryPattern.cpp
 @abstract   抽象工厂模式
 @discussion 
	多个抽象产品类，每个抽象产品类可以派生出多个具体产品类。   
	一个抽象工厂类，可以派生出多个具体工厂类。   
	每个具体工厂类可以创建多个具体产品类的实例，也就是创建的是一个产品线下的多个产品。 
	每个具体工厂类只能创建一个具体产品类的实例。
	用了抽象工厂模式，你只要换家工厂，就可以同时替换CPU和RAM一套。如果你要的产品有几十个，当然用抽象工厂模式一次替换全部最方便（这个工厂会替你用相应的工厂方法）
 @copyright  181471112 at qq dot com
*/
#include <iostream>
using namespace std;
class CPU{
public:
	virtual void product_name()=0;
};
class ACPU:public CPU{
public:
	virtual void product_name(){
		cout<<"a-cpu" <<endl;

	}
};
class BCPU:public CPU{
public:
	virtual void product_name(){
		cout<<"b-cpu" <<endl;

	}

};
class RAM{
public:
	virtual void product_name()=0;
};

class ARAM:public RAM{
public:
	virtual void product_name(){
		cout<<"a-ram" <<endl;

	}
};
class BRAM:public RAM{
public:
	virtual void product_name(){
		cout<<"b-ram" <<endl;

	}
};

class Factory{
public:
	virtual CPU* product_cpu()=0;
	virtual RAM* product_ram()=0;
};
class AFactory:public Factory{
public:
	virtual CPU* product_cpu(){return new ACPU();}
	virtual RAM* product_ram(){return new ARAM();}
};
class BFactory:public Factory{
public:
	virtual CPU* product_cpu(){return new BCPU();}
	virtual RAM* product_ram(){return new BRAM();}
};
int main()
{
	Factory* pFactory = new AFactory();
	CPU*  pCPU = pFactory->product_cpu();
	pCPU->product_name();
	RAM*  pRAM = pFactory->product_ram();
	pRAM->product_name();

	Factory* pFactoryB = new BFactory();
	CPU*  pCPUB = pFactoryB->product_cpu();
	pCPUB->product_name();
	RAM*  pRAMB = pFactoryB->product_ram();
	pRAMB->product_name();
	return 0;
}

