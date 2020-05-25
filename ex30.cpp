#include <iostream>
#include <iomanip>
using namespace std;

class Cstring{
	char buf[255];
public:
	Cstring(char* s = ""){
		strcpy(buf, s);
	}
	char* getStr(){
		return buf;
	}
	Cstring& operator=(Cstring& r){    //생략해도 문제는 생기지 않는다. 
		strcpy(buf, r.buf);				//생략했을 경우 buf = r.buf 코드가 작동할 것 <- 엄격히말하면 buf와 r.buf는 배열의 시작주소(0번째 방 주소)이므로 이런 형태는 아닐 것
		return *this;				//디폴트를 쓸 경우 비트단위로 값을 대입하므로 디폴트복사생성자를 썼을 때 처럼 큰 문제는 발생하지 않는다. - 일반배열도 문제없음
	}
};

void ex1(){
	Cstring str1("I like you.");
	Cstring str2;
	str2=str1;  // str2.operator=(str1);
	cout<<str1.getStr()<<endl;
	cout<<str2.getStr()<<endl;
}


class MyString{
	char* pStr;
public:
	MyString();
	MyString(char* p);
	~MyString();
	MyString& operator=(MyString& rhs);
	void StringShow() const;
};
MyString::MyString(){
	pStr=NULL;
}
MyString::MyString(char* p){
	pStr = new char[strlen(p)+1];
	strcpy(pStr, p);
}
MyString::~MyString(){
	delete[] pStr;
}
MyString& MyString::operator=(MyString& rhs){   // (MyString* this, MyString& rhs )
	pStr = new char[strlen(rhs.pStr)+1];
	strcpy(pStr, rhs.pStr);
	return *this;
}
void MyString::StringShow() const{
	if(pStr!=NULL){
		cout<<pStr<<endl;
	}
}
void ex2(){
	MyString s1="Hello World";  // MyString s1("Hello World"); - C++ 스타일 초기화
	MyString s2;
	s2=s1;					// s2.operator=(s1);
	s1.StringShow();
	s2.StringShow();
	//s2.~MyString();
	//s1.~MyString();
}


class Copycon{
	char* str;
public:
	Copycon(){
		cout<<"매개변수 없는 생성자"<<endl;
		str=new char[30];
	}
	Copycon(char* s){
		cout<<"매개변수 있는 생성자"<<endl;
		str = new char[strlen(s)+1];
		strcpy(str, s);
	}
	Copycon(Copycon& s){
		cout<<"복사 생성자"<<endl;
		str = new char[strlen(s.str)+1];
		strcpy(str, s.str);
	}
	~Copycon(){
		delete[] str;
	}
	Copycon& operator=(Copycon& ob){
		cout<<"대입 연산자"<<endl;
		delete[] str;
		str = new char[strlen(ob.str)+1];
		strcpy(str, ob.str);
		return *this;
	}
	void showData(){
		cout<<str<<endl;
	}
};

void ex3(){
	Copycon r1("Always Happy!");
	Copycon r2 = r1; //객체로 객체를 초기화 할 때 복사생성자 호출 - Copycon r2(r1);
	Copycon r3;
	r3 = r1;		//객체를 먼저 만든 다음에 객체에 객체 대입시 대입 연산자 함수 호출 - r3.operator=(r1);

	r1.showData();
	r2.showData();
	r3.showData();
	//r3.~Copycon();
	//r2.~Copycon();
	//r1.~Copycon();
}

void main(){
	ex1();
	ex2();
	ex3();
}