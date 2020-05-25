#include <iostream>
#include <iomanip>
using namespace std;

/*
문제 1. 사원 클래스를 만들고 사원 클래스를 상속받는 정규직 사원 클래스와 임시사원 클래스를 만들어 보자.
	- 정규사원의 실제 급여는 기본급에 수당을 합해서 구한다.
	- 임시사원의 실제 급여는 일당급여액에 근무일수를 곱해서 구한다.

	1. Employee 클래스
	- private 멤버변수
		이름, 주민등록번호
	- public 멤버함수
		setName - 이름 대입
		setId - 주민등록번호 대입
		getName - 이름 리턴
		getId - 주민등록번호 리턴

	2. FullTime 클래스는 Employee 클래스 상속
	- private 멤버변수
		사원 코드, 기본급, 수당
	- public 멤버함수
		setEmpcode - 사원 코드 대입
		setBaseSalary - 기본급 대입
		setSudang - 수당 대입
		outData - 이름, 주민등록번호, 사원코드, 기본급, 수당, 실제 급여 출력

	3. PartTime 클래스는 Employee 클래스 상속
	- private 멤버변수
		일당급여액, 근무일수
	- public 멤버함수
		setDayPay - 일당급여액 대입
		setWorkDay - 근무일수 대입
		outData - 이름, 주민번호, 일당급여액, 근무일수, 실제 급여 출력

	4. 출력 결과
	------------정규사원-------------
	성명		: 홍길동
	주민등록번호: 901012-1234567
	사원 코드	: 20161201
	기본급		: 1500000
	수당		: 700000
	실제 급여	: 2200000

	------------임시사원-------------
	성명		: 김초아
	주민등록번호: 920712-2345678
	일당급여액	: 50000
	근무일수	: 20
	실제 급여	: 1000000
*/

class Employee{
private:
	char name[20], id[20];
public:
	void setName(char* pn){  //매개변수로 char pn[20]으로 배열 생성 가능함
		strcpy(name, pn);	//만약에 생성자를 통해 변수에 값을 넣는다면 그건 초기화일테니까 strcpy를 안써도 될지도
	}
	void setId(char* pi){
		strcpy(id, pi);
	}
	char* getName(){  //주소값을 돌려줄때 char[20] 이걸로 반환형 만들지는 못하네.. 흠
		return name;
	}
	char* getId(){
		return id;
	}
};

class FullTime : public Employee{   //상속받을 때도 접근지정자 생략할 수 있는데 이 때에는 private가 됨
private:							//private로 상속받았다면 자식클래스에서는 여전히 부모클래스의 public에는 제한없이 접근 가능하지만
	char empcode[10];				//외부함수에서 자식객체명으로 부모의 public 멤버에 접근 불가능해짐
	int baseSalary, sudang;
public:
	void setEmpcode(char* pe){
		strcpy(empcode, pe);
	}
	void setBaseSalary(int b){
		baseSalary = b;
	}
	void setSudang(int s){
		sudang=s;
	}
	void outData(){
		cout<<"------------정규사원-------------"<<endl;
		cout<<"성명\t\t: "<<getName()<<endl;
		cout<<"주민등록번호\t: "<<getId()<<endl;
		cout<<"사원 코드\t: "<<empcode<<endl;
		cout<<"기본급\t\t: "<<baseSalary<<endl;
		cout<<"수당\t\t: "<<sudang<<endl;
		cout<<"실제 급여\t: "<<baseSalary+sudang<<endl;
		//setw()로 공간확보 후 출력해도 되는데 이 때 cout<<left; 를 앞에 써놓으면 왼쪽 정렬 후 출력됨
	}
};

class PartTime : public Employee{
private:
	int dayPay, workDay;
public:
	void setDayPay(int p){
		dayPay = p;
	}
	void setWorkDay(int w){
		workDay = w;
	}
	void outData(){
		cout<<"------------임시사원-------------"<<endl;
		cout<<"성명\t\t: "<<getName()<<endl;
		cout<<"주민등록번호\t: "<<getId()<<endl;
		cout<<"일당급여액\t: "<<dayPay<<endl;
		cout<<"근무일수\t: "<<workDay<<endl;
		cout<<"실제 급여\t: "<<dayPay*workDay<<endl;
	}
};


void pr1(){
	FullTime f;
	f.setName("홍길동");
	f.setId("901012-1234567");
	f.setEmpcode("20161201");
	f.setBaseSalary(1500000);
	f.setSudang(700000);
	f.outData();

	PartTime p;
	p.setName("김초아");
	p.setId("950712-2345678");
	p.setDayPay(50000);
	p.setWorkDay(20);
	p.outData();
}

void main(){
	pr1();
}