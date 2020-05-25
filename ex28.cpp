#include <iostream>
#include <iomanip>
using namespace std;

class AAA{
	int a, b;
public:
	void set(int _a, int _b){
		a = _a;
		b = _b;
	}
	void getData(){
		cout<<"a = "<<a<<", b = "<<b<<endl;
	}
	friend void add(AAA &r);  //친구선언
};
void add(AAA& r){  //전역함수인 동시에 AAA클래스의 친구함수이다. 만약 AAA의 멤버변수였다면 클래스접근연산자 AAA::가 필요했을 것이다. 
	r.a+=100;
	r.b+=200;
} //캡슐화에 의거하여 이 함수정의를 클래스 내의 friend 함수 선언문에 넣을 수도 있다. (외부 전역함수지만 친구집에 놀러가기)
//클래스 안에 넣었을 때 friend 키워드가 없었다면 멤버함수형태가 되며, friend키워드를 넣음으로서 마치 static 함수처럼 작동되게 된다.

//객체가 만약 동적할당된다면? add함수의 매개변수부분이 포인터변수가 되야하거나.. 만약 기존의 포인터함수를 레퍼런스변수로 별명지어주기가 가능하다면
//매개변수부는 그대로 두고 코드부만 -> 로 바뀌어야겠지

void ex1(){
	AAA aa;
	aa.set(10, 20);
	add(aa);
	aa.getData();
}


class Test{
private:
	int a;
	char c;
public:
	Test(int _a, char _c){
		a = _a;
		c = _c;
	}
	void output(){
		cout<<a<<" "<<c<<endl;
	}
	void set(int _a, char _c){
		a = _a;
		c = _c;
	}
	int add(int x){
		return a + x;
	}

	//연산자의 오버로딩 - 연산자함수, operator 함수
	int operator+(int x){  
		return a + x;
	}
	friend int operator+(int x, Test& r){
		return x + r.a;
	}
};

void ex2(){
	/*
	클래스멤버변수가 public으로 되어있다면 구조체처럼 사용이 가능하다.
	Test 클래스의 a, c 멤버변수가 public이었다면 아래와 같은 코드사용이 가능하다.
	
																	멤버변수가 private가 된다면?
	Test t = {5, 'A'};			- 객체를 만들면서 초기화				생성자함수로 초기화
	cout<<t.a<<" "<<t.c<<endl;	- 객체의 멤버변수 출력					get함수 또는 출력함수로 출력
	t.a=7;						- 객체의 멤버변수 값 변경				set함수로 값 세팅
	t.c='B';
	cout<<t.a<<" "<<t.c<<endl;	- 멤버변수 값 출력
	cout<<t.a + 100<<endl;	
	*/

	Test t(5, 'A'); 
	t.output(); 
	t.set(7,'B');
	t.output(); 
	cout<<t.add(100)<<endl;

	//t.a+100 을 했던 것에서 a라는 멤버변수가 private화가 되었다보니 같은 결과가 나오게 하기 위해서 별도의 함수를 만들었다.(add멤버함수)
	//그런데 이렇게 별도의 함수를 만드는게 아니라 기존에 썼던 +연산자를 이용해서 비슷한 코드형태로 같은 결과가 나오게 하고싶었던 것이다.(t+100)
	//그래서 만들어진 것이 연산자의 오버로딩이다.(기존 연산자의 기능도 살려두되 경우에 따라 다른 방식으로 다른 함수가 작동되게 하는 오버로딩)

	cout<<t.operator+(100)<<endl;  //이렇게 쓸 수도 있지만... 함수의 이름 생략이 가능하다..

	cout<<t+100<<endl;  //객체와 연산자가 만나면 이제 단순 연산이 아니라 operatior 함수 호출식이다.
	// t.operator+(100)  ,  operator+(t, 100) 둘 중 하나가 호출됨


	cout<<100+t<<endl;  //교환법칙에 의거하여 이렇게도 쓸 수 있어야 한다. 그런데 100은 객체명이 아니므로 어떤 함수를 어떻게 호출할 것인지 명확하지 않다.
	//따라서 operator 함수를 전역함수로 만든 뒤 필요한 경우 friend선언을 거쳐 operator+(100,t)가 작동될 수 있도록 만든다.
	/*
	왜 위와같은 형태에 friend형태로 만들어야 하는가?
	operator를 멤버함수로 만들면 이는 필연적으로 객체가 만들어져야 쓸 수 있음을 의미하게 된다.
	그러면 이 함수를 쓰려면 먼저 객체를 통해 접근해야 하므로 객체명.함수명(인자) 형태로 써야 한다는게 되고 결국 객체명이 먼저 와야만 한다.
	오버로딩된 오퍼레이터 규칙에 따라 '객체 + 인자'같은 식에만 작동될 수 밖에 없다는 것이다.
	따라서 위와 같은 인자(값) + 객체 같은 형태는 클래스 내부(객체)를 통해 실현되어서는 안된다.
	객체 생성과는 상관없이 객체명을 통한 접근이 아닌 전역함수 형태를 만들어야 한다는 것이고, 클래스의 private에 접근해야 하므로 friend선언이 되어있어야 한다.
	따라서 friend선언이 된 operator 전역함수 형태로 구현하도록 하자
	*/
}

void main(){
	ex1();
	ex2();
}