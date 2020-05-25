#include <iostream>
#include <iomanip>
using namespace std;

void ex1(){
	int stNum;
	cout<<"�л� �� �Է� : ";
	cin>>stNum;

	int* jumsu = new int[stNum];
	double sum = 0;

	for(int i=0; i<stNum; i++){
		cout<<i+1<<"��° ���� �Է� : ";
		cin>>jumsu[i];
		sum+=jumsu[i];
	}

	cout<<endl;
	cout<<stNum<<"�л��� ��� ������ "<<sum/stNum<<"�Դϴ�.\n";

	delete[] jumsu;
}

struct Student{
	char name[20];
	int kor, eng, math, sum;
};
void input(Student* p, int _in){
	for(int i=0; i<_in; i++){
		system("cls");
		cout<<"\n["<<i+1<<"��° �Է�]\n";
		cout<<"�̸� : "; cin>>p[i].name;
		cout<<"�������� : "; cin>>p[i].kor;
		cout<<"�������� : "; cin>>p[i].eng;
		cout<<"�������� : "; cin>>p[i].math;
		p[i].sum = p[i].kor + p[i].eng + p[i].math;
	}

void output(Student* p, int _in){
	system("cls");
	cout<<"**** ���� ��� ****\n\n";
	cout<<setw(6)<<"��ȣ"<<setw(15)<<"�̸�"<<setw(7)<<"����"<<setw(7)<<"����"<<setw(7)<<"����"<<setw(7)<<"����"<<endl;
	for(int i=0; i<_in; i++){
		cout<<setw(6)<<i+1<<setw(15)<<p[i].name<<setw(7)<<p[i].kor<<setw(7)<<p[i].eng<<setw(7)<<p[i].math<<setw(7)<<p[i].sum<<endl;
	}
}

void ex2(){
	int in;
	cout<<"�л� �� �Է� : ";
	cin>>in;

	Student* pSt;
	pSt = new Student[in];
	
	input(pSt, in);
	output(pSt, in);

	delete[] pSt;
}

void main(){
	ex1();
	ex2();
}