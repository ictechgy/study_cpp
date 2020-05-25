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
		cout<<"�̸� : "<<name<<endl;
		cout<<"���� : "<<accId<<endl;
		cout<<"�ܰ� : "<<balance<<endl;
		cout<<"���� : "<<iyul<<endl;
	}
	static void set_iyul(double i){
		iyul=i;
	}
};
double Bank::iyul=0;
void ex1(){
	Bank::set_iyul(2.0);
	Bank hong("ȫ�浿", "1234", 1000);	//2000�⵵
	Bank::set_iyul(4.5);
	Bank go("��浿", "2345", 2000);	//2005�⵵
	Bank::set_iyul(6.5);
	Bank kim("��浿", "3456", 3000);	//2016�⵵

	hong.output();
	go.output();
	kim.output();
}

void main(){
	ex1();
}