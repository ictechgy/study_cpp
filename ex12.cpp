#include <iostream>
#include <iomanip>
using namespace std;

class Test{
public:
	int a;
	char c;
};  //����ü�� ���
void ex1(){
	Test t = {5, 'A'};  //��������� public�ΰ�� ����üó�� ������ �� �ʱ�ȭ�� �����ϴ�.  
	cout<<t.a<<" "<<t.c<<endl;
	t.a=7;
	t.c='B';
	cout<<t.a<<" "<<t.c<<endl;
}

class Test2{
private:			//private�� �Ǽ� ��ü������ �ٷ� �ʱ�ȭ�� �� �� ����. ���� �����ڸ� ����.
	int a;
	char c;			//���� ���� �����Ҷ����� set�Լ�, ������� ������ get�Լ��� ����.
public:
	Test2(){
		a=0;
		c='\0';
	}
	Test2(int x, char y){
		a=x;
		c=y;
	}

	void set(int x, char y){
		a = x;
		c = y;
	}

	void output(){
		cout<<a<<" "<<c<<endl;
	}
};

void ex2(){
	Test2 t(5,'a');  //t.Test() �����ڸ� �ڵ����� ȣ���Ͽ� ���� �ʱ�ȭ��
	t.output();
	t.set(7, 'b');
	t.output();
}

void main(){
	ex1();
	ex2();


	Test2* p = new Test2(5,'a');  //�ڹ�ó�� �����ϳ� ����
	//��������� public �϶� {}�� ����üó�� ����ÿ� �ʱ�ȭ�ϴ°� �����Ҵ翡���� �����ұ�
	Test* t = new Test{5, 'a'}; //�ȵǳ�
}