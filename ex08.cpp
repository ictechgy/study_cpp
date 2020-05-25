#include <iostream>
#include <iomanip>
using namespace std;

void ex1(){
	//배열명 : 첫번째 변수(방)의 주소
	//1차원 배열 : 문자열 1개만 저장 가능

	char name[20] = "홍길동";    //한글은 유니코드를 쓰므로 한글자당 2byte를 차지한다.

	cout<<name<<endl;  //name이라는 주소를 찾아가서 NULL문자를 만날때까지 출력

	strcpy(name, "고길동"); //"고길동"이라는 값을 먼저 메모리에 저장하고 그곳의 주소를 이용해서 name이라는 주소에 값 저장
	cout<<name<<endl;

	cout<<"이름 입력 : ";
	cin>>name;   //공백문자는 저장 못하므로 "고 아 라" 를 입력시 name에는 "고"만 들어가며, 구분문자로 쓴 공백은 제거한 뒤 버퍼에는 "아 라"가 남게 된다.
	cout<<name<<endl;

	cin.get(name,20); //공백문자까지 입력가능. "고 아 라" 입력 시 "고 아 라"가 모두 들어가게 된다. 다만 버퍼에는 엔터값이 남게 되므로 fflush(stdin) 필요
	cout<<name<<endl;

	fflush(stdin);

	cin.get(name,20);  //엔터값이 남아있는경우 씹히게 됨. 엔터값 앞까지만 읽는데 버퍼에 엔터값이 남아있을 경우 아무것도 받아오지 못한다. 이후에도 엔터값은 남아있을까?
	cout<<name<<endl;

	//만약 버퍼에 엔터값이 남아있는경우 그냥 cin만 쓴다면 아무것도 받아오지는 못하더라도 엔터값은 삭제해주지 않을까

}  //printf나 scanf나 cout, cin 등. 문자열배열은 시작주소값으로 다 처리할 수 있게 배려해준건가

void ex2(){
	//동적할당으로 문자열 1개 저장
	char* name;
	name = new char[20];

	strcpy(name, "고길동");
	cout<<name<<endl;

	cout<<"이름 입력 : ";
	cin>>name;
	cout<<name<<endl;

	delete[] name;  //동적할당이 함수에서 쓰였다고 하더라도 함수가 끝날 때 제거되는 것은 name일 뿐 heap의 동적할당된 부분은 직접 제거해줘야 하는 듯
}

void output(char* p){
	cout<<p<<endl;
}
void ex3(){
	output("홍길동"); //"홍길동"이라는 문자열상수는 ex3()이 종료될 때 사라진다.
}

void main(){
	ex1();
	ex2();
	ex3();
}