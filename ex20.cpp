#include <iostream>
#include <iomanip>
using namespace std;

class AAA{
private:
	int val;
public:
	AAA(int n=0){
		cout<<"AAA(int n) 호출"<<this<<endl;
		this->val = n;
	}
	AAA(AAA& r){ //복사생성자 - 같은 자료형의 객체를 인자로 받을 수 있는 생성자
		cout<<"AAA(AAA& r) 호출"<<this<<endl;
		this->val = r.val;
	}
	~AAA(){
		cout<<"소멸자 실행"<<this<<endl;
	}
	void showData(){
		cout<<this->val<<endl;
	}
};

void ex1(){
	AAA a(10); //a.AAA(10);
	a.showData();
	AAA b = a; //객체복사. AAA b(a); -> b.AAA(a);
	b.showData();
	cout<<"a = "<<&a<<", b = "<<&b<<endl;
}


void test2(AAA b){  //AAA b = a; 또는 AAA b(a); 따라서 b.AAA(a) 동작
	cout<<"b = "<<&b<<endl;
	b.showData();
}
void ex2(){
	AAA a(30);  //a.AAA(30);
	cout<<"a = "<<&a<<endl;
	test2(a);
}

//함수를 작동시키고 그 결과값을 변수에 저장하고자 할 때 임시변수라는 것이 만들어진다.
//임시변수가 만들어지고 함수의 결과(리턴)값을 저장한 뒤에 변수에 저장한다는 말이다.
//수명은 1줄 수명

double plus(double a, double b){
	return a+b;
}
void plusTest(){
	double c;
	c = plus(1.2, 2.5);  //대입연산자의 규칙은 사실 변수명=데이터값; 이므로 이 줄과같은 방식은 작동할 수 없다.
	cout<<c<<endl;	//하지만 임시변수가 존재함으로서 사용가능한 코드이다.
}
//c = plus(1.2, 2.5)의 진행과정은 사실 아래와 같다. 
//double 임시변수 = 함수 연산결과인 3.7;		=> 임시변수를 만들고 함수의 연산결과를 저장한다.
//c = 임시변수;		=> 해당 임시변수의 값을 c에 대입한다.

//따라서 결과자료형 = 리턴값의 자료형 = 임시변수의 자료형 이라고도 볼 수 있다.
//void는 임시변수를 만들지 말라는 말

//이렇게 함수의 리턴값이 존재할 때 컴퓨터는 그 값을 임시변수에 잠시 저장해둔다.



AAA test2(){
	AAA b(10);  //b.AAA(10);
	cout<<"b = "<<&b<<endl;
	return b;
}
void ex3(){
	AAA a;  //a.AAA();
	cout<<"a = "<<&a<<endl;
	a = test2();  //AAA imsi = b; => AAA imsi(b); => imsi.AAA(b); 라는 코드가 내부적으로 작동(임시클래스변수 생성). 이후 a = imsi; 라는 코드 작동
	//임시변수가 a에 값을 전달해준 뒤에는 자체적 소멸자 작동한다. imsi.~AAA();
	a.showData();
}
//그나저나 이미 만든 a클래스변수(객체)에 다른 객체값을 = 대입연산자를 통해서 멤버변수 값이 같게 만들 수 있나보네? (자바는 참조형변수로 가리키게 될 뿐)
//만약에 클래스 내부에 참조형변수가 있고, 그 참조형변수가 heap공간을 가리키게 만들었었다면, =통해 대입한경우 두 객체는 같은 heap공간을 가리키게 되려나?
//=> 그럴 것 같다. 값만 똑같이 대입하는 방식일테니 주소값만 복사될 듯. 그리고 같은 클래스타입끼리만 대입이 가능할 듯?

//객체자체를 동적할당으로 만들고 그걸 복사한다거나.. 복사할 때 클래스 내부에서 참조형변수가 가리키는 공간이 같지 않게(얕은복사가 안되게) 한다거나..
//=> 역시나 객체 자체를 동적할당으로 만들고 그냥 대입연산자로 (대입방식으로서)복사하면 이는 멤버변수 값 자체만 복사될 것이다.(얕은 복사)
//=> 객체끼리 대입연산자쓰는건 결국 값만 복사시키는 것일뿐.. 얕은복사만 가능한거 아닐까

//만약에 ex3()에서 AAA a = Test2(); 를 했다면 복사생성자가 두번 작동했겠지?. 그러면 AAA a(Test2()); 라고 써도 되는건가



class Person{
	char* name;
	char* phone;
	int age;
public:
	Person(char* a, char* b, int c){
		name = new char[strlen(a)+1];
		strcpy(name, a);

		phone = new char[strlen(b)+1];
		strcpy(phone, b);

		age = c;
	}
	/*
	Person(Person& r){     //디폴트 복사생성자의 모양
		name=r.name;
		phone=r.phone;
		age=r.age;
	}
	//얕은 복사로서 같은 공간을 가리키게 됨(주소값이 복사됨)
	*/
	Person(Person& r){
		name = new char[strlen(r.name)+1];
		strcpy(name, r.name);

		phone = new char[strlen(r.phone)+1];
		strcpy(phone, r.phone);

		age = r.age;
	} //깊은 복사를 위해 직접 정의한 복사생성자

	~Person(){
		delete[] name;
		delete[] phone;
	}

	void showData(){
		cout<<name<<endl;
		cout<<phone<<endl;
		cout<<age<<endl;
	}
};
void ex4(){
	Person p1("홍길동", "010-1234-5678", 25);
	Person p2=p1; //Person p2(p1);
	p1.showData();
	p2.showData();
	//p2.~Person();
	//p1.~Person();
}
/*
만약 
Person p2;
p2=p1;
이라고 썼으면 그냥 얕은복사였을 것
*/


void main(){
	ex1();
	ex2();
	ex3();
	ex4();
}


//복사생성자를 만들어주는 것(생성자오버로딩이라고 봐도 될 듯)은 클래스 멤버변수가 포인터변수이고 동적할당을 쓰는 경우 주로 만들어준다.
//소멸자는 오버라이딩 개념인가