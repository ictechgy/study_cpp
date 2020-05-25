#include <iostream>
#include <iomanip>
using namespace std;

class Bank{
private:
	char name[20];
	char accId[20]; 
	int balance;
	//double iyul;
	static double iyul;
public:
	Bank(char* pn, char* pa, int b){
		strcpy(name, pn);
		strcpy(accId, pa);
		balance=b;
	}
	void output(){
		cout<<"이름 : "<<name<<endl;
		cout<<"계좌 : "<<accId<<endl;
		cout<<"잔고 : "<<balance<<endl;
		cout<<"이율 : "<<iyul<<endl;
	}
	static void set_iyul(double i){
		iyul=i;
	}
};
double Bank::iyul=0;
void ex1(){
	Bank::set_iyul(2.0);
	Bank hong("홍길동", "1234", 1000);	//2000년도
	Bank::set_iyul(4.5);
	Bank go("고길동", "2345", 2000);	//2005년도
	Bank::set_iyul(6.5);
	Bank kim("김길동", "3456", 3000);	//2016년도

	hong.output();
	go.output();
	kim.output();
}

void main(){
	ex1();
}