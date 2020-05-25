#include <iostream>
#include <iomanip>
using namespace std;

class AAA{	//base 클래스
public:
	AAA(){  //기본적으로 호출될 부모클래스의 디폴트 생성자
		cout<<"AAA() call"<<endl;
	}
	AAA(int i){  //부모클래스에서 매개변수가 있는 생성자는 직접 호출해주어야 한다.
		cout<<"AAA(int i) call" <<endl;
	}
};

class BBB : public AAA{ //derived 클래스
public:
	BBB(){  // : AAA() 가 호출되어진다. 매개변수가 없는 부모생성자는 기본적으로 호출되며 생략이 가능하다.
		cout<<"BBB() call"<<endl;
	}
	BBB(int j){ // : AAA() 호출
		cout<<"BBB(int j) call"<<endl;
	}
};
//이렇게 자식클래스 부모클래스 다 멤버변수는 없지만 자식클래스로 객체생성하면 1byte로 기본공간만 생성된다. 왠지 부모클래스부분도 있어야 해서 2byte일거같았는데..
//그리고 다중상속은??

void ex1(){
	cout<<"객체 1 생성"<<endl;
	BBB bbb1;  //bbb1.BBB();

	cout<<"객체 2 생성"<<endl;
	BBB bbb2(10);  //bbb2.BBB(10);
}


class Person{
private:
	int age;
	char name[20];
public:
	Person(int a, char* n){
		age = a;
		strcpy(name, n);
	}
	int getAge() const{
		return age;
	}
	const char* getName() const{
		return name;
	}
};

class Student : public Person{
	char major[20];
public:
	Student(int a, char* n, char* m) : Person(a, n){  //부모클래스의 생성자 호출
		strcpy(major, m);
	}
	const char* getMajor() const{
		return major;
	}
	void showData() const{
		cout<<"이름 : "<<getName()<<endl;
		cout<<"나이 : "<<getAge()<<endl;
		cout<<"전송 : "<<getMajor()<<endl;
	}
};

void ex2(){
	Student bbb(25, "홍길동", "컴퓨터");
	bbb.showData();
}

void main(){
	ex1();
	ex2();
}