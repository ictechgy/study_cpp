#include <iostream>
#include <iomanip>
using namespace std;

void ex1(){
	int a;
	int &r=a;

	a=5;
	cout<<a<<endl;
	cout<<r<<endl;

	r=7;
	cout<<a<<endl;
	cout<<r<<endl;
}

void ex2(int &r){  //int &r = a;
	r=7;
}

void ex2(int* r){  //int* r = &a;
	*r=10;
}
//오버로딩 가능

void ex2(int r){
	cout<<r<< endl;
}

void main(){
	int a;
	ex2(a);	//함수를 찾을때 먼저 ex2(int ~) 로 되어있는 일반적인 함수를 찾는다. 없으면 그 다음으로 ex2(int &~)로 되어있는 함수를 찾는다.
	cout<<a<<endl;
	
	ex2(&a);
	cout<<a<<endl;
}

//단순한 매개변수로 만든 함수는 다른 지역에 있는 변수의 값을 직접적으로 바꿀 수 없다.(전역변수의 값을 바꾸는 것은 가능하지만..)
//함수의 매개변수로 이제는 일반변수, 포인터변수, 레퍼런스변수를 둘 수 있다.