#include <iostream>
#include <iomanip>
using namespace std;

void ex1(){
	int a;
	int &r=a;

	a=5;
	cout<<a<<endl;
	cout<<r<<endl;

	r=7;
	cout<<a<<endl;
	cout<<r<<endl;
}

void ex2(int &r){  //int &r = a;
	r=7;
}

void ex2(int* r){  //int* r = &a;
	*r=10;
}
//�����ε� ����

void ex2(int r){
	cout<<r<< endl;
}

void main(){
	int a;
	ex2(a);	//�Լ��� ã���� ���� ex2(int ~) �� �Ǿ��ִ� �Ϲ����� �Լ��� ã�´�. ������ �� �������� ex2(int &~)�� �Ǿ��ִ� �Լ��� ã�´�.
	cout<<a<<endl;
	
	ex2(&a);
	cout<<a<<endl;
}

//�ܼ��� �Ű������� ���� �Լ��� �ٸ� ������ �ִ� ������ ���� ���������� �ٲ� �� ����.(���������� ���� �ٲٴ� ���� ����������..)
//�Լ��� �Ű������� ������ �Ϲݺ���, �����ͺ���, ���۷��������� �� �� �ִ�.