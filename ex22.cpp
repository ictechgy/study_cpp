#include <iostream>
#include <iomanip>
using namespace std;

class Test{
private:
	int a;
	const int b;
	static int c;
	static const int d = 5;   //선언과 동시에 초기화가 가능한 유일한 항목
	
public:
	Test():b(10){  //const는 선언과 동시에 초기화가 불가능하며 콜론의 초기화에서만 초기화가 가능하다.
		a = 10;  //일반멤버변수는 생성자에서는 어떠한 방식으로든 초기화가 가능하다. 콜론의 초기화도 가능하다.
		c = 10;  //static 멤버변수는 객체가 생성될때마다 리셋이 되겠다만 생성자 내부에서 값 대입은 가능하다.
	}
	void method(){
		c = 10;  //static 멤버변수에 함수를 통한 값 대입 가능
		func(); //일반 멤버함수에서는 static멤버함수를 호출할 수 있다.
	}
	void static func(){
		cout<<"hello"<<endl;
		cout<<c<<d<<endl; //static멤버함수에서는 static멤버만 사용 가능하다.
	}
};

int Test::c; //이 구문은 반드시 존재해야하며 없을경우 컴파일에러
//static 멤버변수에 대한 별도의 선언구문으로서 필수작성해야하며 여기서 초기화도 가능하다.


void main(){
	Test t1;
	Test t2;
	t1.method();
}