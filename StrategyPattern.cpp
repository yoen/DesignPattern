/*
@header StrategyPattern.cpp
@abstract 策略模式
@discussion
定义了算法家族，分别封装起来，让他们之间可以互相替换，此模式让算法的变化不会影响到使用算法的客户。
@copyright 181471112 at qq dot com
*/



class FruitContext{

private:

	Fruit* f=0;

public:

	void FruitContext(std::string fruit_type){
		switch(){
			case "apple":f= new Apple;
			case "pear": f= new Pear;
		}
	}

	int GetPrice(){
		return f->Price();
	}
};



class Fruit{
public:
	virtual int Price()=0;

protected:
	double _price;
};


class Apple:public Fruit{
public: 
	int Price(){return 5;}
}



class Pear:public Fruit{
public: 
	int Price(){return 3;}
}

int main(int argc,char* argv[]){
  FruitContext* fc = new FruitContext("apple");
  fc->GetPrice();
}
