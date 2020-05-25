#include <iostream>
#include <iomanip>
using namespace std;

class Test{
public:
	int a;
	char c;
};  //구조체와 흡사
void ex1(){
	Test t = {5, 'A'};  //멤버변수가 public인경우 구조체처럼 선언할 때 초기화가 가능하다.  
	cout<<t.a<<" "<<t.c<<endl;
	t.a=7;
	t.c='B';
	cout<<t.a<<" "<<t.c<<endl;
}

class Test2{
private:			//private가 되서 객체생성시 바로 초기화를 할 수 없다. 따라서 생성자를 쓴다.
	int a;
	char c;			//이후 값을 세팅할때에는 set함수, 끄집어올 때에는 get함수를 쓴다.
public:
	Test2(){
		a=0;
		c='\0';
	}
	Test2(int x, char y){
		a=x;
		c=y;
	}

	void set(int x, char y){
		a = x;
		c = y;
	}

	void output(){
		cout<<a<<" "<<c<<endl;
	}
};

void ex2(){
	Test2 t(5,'a');  //t.Test() 생성자를 자동으로 호출하여 값을 초기화함
	t.output();
	t.set(7, 'b');
	t.output();
}

void main(){
	ex1();
	ex2();


	Test2* p = new Test2(5,'a');  //자바처럼 가능하네 역시
	//멤버변수가 public 일때 {}로 구조체처럼 선언시에 초기화하는거 동적할당에서는 어찌할까
	Test* t = new Test{5, 'a'}; //안되네
}