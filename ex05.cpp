#include <iostream>
#include <iomanip>
using namespace std;

void main(){
	int a=10;
	int b(20);
	cout<<a<<endl;
	cout<<b<<endl;

	b(30); //함수의 호출로 인식함.
	//따라서 괄호를 이용한 값의 대입은 선언과 동시에 초기화할 때에만 가능함
}