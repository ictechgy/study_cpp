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
	Cstring& operator=(Cstring& r){    //�����ص� ������ ������ �ʴ´�. 
		strcpy(buf, r.buf);				//�������� ��� buf = r.buf �ڵ尡 �۵��� �� <- ���������ϸ� buf�� r.buf�� �迭�� �����ּ�(0��° �� �ּ�)�̹Ƿ� �̷� ���´� �ƴ� ��
		return *this;				//����Ʈ�� �� ��� ��Ʈ������ ���� �����ϹǷ� ����Ʈ��������ڸ� ���� �� ó�� ū ������ �߻����� �ʴ´�. - �Ϲݹ迭�� ��������
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
	MyString s1="Hello World";  // MyString s1("Hello World"); - C++ ��Ÿ�� �ʱ�ȭ
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
		cout<<"�Ű����� ���� ������"<<endl;
		str=new char[30];
	}
	Copycon(char* s){
		cout<<"�Ű����� �ִ� ������"<<endl;
		str = new char[strlen(s)+1];
		strcpy(str, s);
	}
	Copycon(Copycon& s){
		cout<<"���� ������"<<endl;
		str = new char[strlen(s.str)+1];
		strcpy(str, s.str);
	}
	~Copycon(){
		delete[] str;
	}
	Copycon& operator=(Copycon& ob){
		cout<<"���� ������"<<endl;
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
	Copycon r2 = r1; //��ü�� ��ü�� �ʱ�ȭ �� �� ��������� ȣ�� - Copycon r2(r1);
	Copycon r3;
	r3 = r1;		//��ü�� ���� ���� ������ ��ü�� ��ü ���Խ� ���� ������ �Լ� ȣ�� - r3.operator=(r1);

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