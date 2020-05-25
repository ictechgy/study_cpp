#include <iostream>
#include <iomanip>
using namespace std;

bool isBig(int a, int b){
	if(a > b){
		return 1;  
	}else{
		return 0;  
	}
	//return 값으로 숫자를 반환함에도 불구하고 bool형으로 반환가능. char도 가능하고 short 및 int 가능
	//단, 0을 char형으로 반환시키는경우 cout에서는 null로 인식?
}
//1과 0 대신 true 및 false로 써도 꼭 bool 자료형반환타입으로 둘 필요는 없을 것

void main(){
	cout<<isBig(10, 20)<<endl; //0이 출력

	bool b;
	b = 100;
	cout<<b<<endl; //1 출력된다. C와 C++에서는 0이 아닌 모든 수는 참으로 인식하며 결국 1로 인식됨
}