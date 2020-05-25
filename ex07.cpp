#include <iostream>
#include <iomanip>
using namespace std;

void ex1(){
	int stNum;
	cout<<"학생 수 입력 : ";
	cin>>stNum;

	int* jumsu = new int[stNum];
	double sum = 0;

	for(int i=0; i<stNum; i++){
		cout<<i+1<<"번째 점수 입력 : ";
		cin>>jumsu[i];
		sum+=jumsu[i];
	}

	cout<<endl;
	cout<<stNum<<"학생의 평균 점수는 "<<sum/stNum<<"입니다.\n";

	delete[] jumsu;
}

struct Student{
	char name[20];
	int kor, eng, math, sum;
};
void input(Student* p, int _in){
	for(int i=0; i<_in; i++){
		system("cls");
		cout<<"\n["<<i+1<<"번째 입력]\n";
		cout<<"이름 : "; cin>>p[i].name;
		cout<<"국어점수 : "; cin>>p[i].kor;
		cout<<"영어점수 : "; cin>>p[i].eng;
		cout<<"수학점수 : "; cin>>p[i].math;
		p[i].sum = p[i].kor + p[i].eng + p[i].math;
	}

void output(Student* p, int _in){
	system("cls");
	cout<<"**** 점수 출력 ****\n\n";
	cout<<setw(6)<<"번호"<<setw(15)<<"이름"<<setw(7)<<"국어"<<setw(7)<<"영어"<<setw(7)<<"수학"<<setw(7)<<"총점"<<endl;
	for(int i=0; i<_in; i++){
		cout<<setw(6)<<i+1<<setw(15)<<p[i].name<<setw(7)<<p[i].kor<<setw(7)<<p[i].eng<<setw(7)<<p[i].math<<setw(7)<<p[i].sum<<endl;
	}
}

void ex2(){
	int in;
	cout<<"학생 수 입력 : ";
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