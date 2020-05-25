#include <iostream>
#include <iomanip>
using namespace std;

int ex1(int a=10); //함수의 선언

void main(){
	cout<<ex1()<<endl;
	cout<<ex1(10)<<endl;
}

int ex1(int a){  //함수의 정의
	return a+100;
}
//디폴트 매개변수가 존재하는 함수를 작성할 때 함수의 선언을 위에 두고 함수의 정의를 아래에 두는경우,
//디폴드값은 선언부에서만 주어야 한다.