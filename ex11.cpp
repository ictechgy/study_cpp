#include <iostream>
#include <iomanip>
using namespace std;

class AAA{
private:
	int a;
	char c;
	double d;
public:
	void setA(int a){
		a=a; //지역(매개)변수 우선
		this->a=a;
	}
	void set(){   //void set(AAA* this)
		cout<<this<<endl;
		cout<<"정수 : ";
		cin>>this->a;
		
		cout<<"문자 : ";
		cin>>this->c;
		
		cout<<"실수 : ";
		cin>>this->d;
	}
	void getData(){  //void getData(AAA* this)
		cout<<this<<endl;
		cout<<this->a<<" "<<this->c<<" "<<this->d<<" "<<endl;
	}
};

void ex1(){
	AAA aa, bb, cc;
	cout<<"aa = "<<&aa<<", bb = "<<&bb<<", cc = "<<&cc<<endl;

	aa.set();  //aa.set(&aa)
	bb.set();  //bb.set(&bb)
	cc.set();  //bb.set(&bb)

	aa.getData(); //aa.getData(&aa)
	bb.getData(); //bb.getData(&bb)
	cc.getData(); //cc.getData(&cc)
}

void main(){
	ex1();
}