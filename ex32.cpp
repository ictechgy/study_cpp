#include <iostream>
#include <iomanip>
using namespace std;

void ex1(){
	int a, b;

	cout<<"두개의 숫자 입력 : ";
	cin>>a>>b;
	cout<<"a/b의 몫 : "<<a/b<<endl;		//a와 b 둘다 double이면 b가 0일 때 결과가 나오기는 함. Infinity로
	cout<<"a/b의 나머지 : "<<a%b<<endl;
}//a와 b가 double이면 나눗셈연산은 몫만 구하는 것이 아니라 나눠질때까지 이어진다.(결과형태도 실수형태로 나오게 하려 함) 따라서 나머지 연산은 불가능해짐

void ex2(){
	int a, b;

	while(1){
		cout<<"두개의 숫자 입력 : ";
		cin>>a>>b;
		
		if(b!=0){
			cout<<"a/b의 몫 : "<<a/b<<endl;		
			cout<<"a/b의 나머지 : "<<a%b<<endl;
			break;
		}else{
			cout<<"b 입력이 잘못되었습니다."<<endl;
		}
	}
}

void ex3(){
	int a, b;

	while(1){
		cout<<"두개의 숫자 입력 : ";
		cin>>a>>b;
		
		try{
			if(b==0) throw b;  //예외값을 던짐
			cout<<"a/b의 몫 : "<<a/b<<endl;		
			cout<<"a/b의 나머지 : "<<a%b<<endl;
			break;
		
		}catch(int e){		//던진 값을 받음
			cout<<"b = "<<e<<"입력이 잘못되었습니다."<<endl;
		}

	}
}


void quotient(int a, int b){	//몫을 구하는 함수라고 가정
	if(b==0) throw 1;			//main에서 쓰일 함수들을 정의할 때 에러가 발생할 부분에 대해 throw를 하도록 만든다.
}
void ex(){
	if(조건식) throw 2;
	if(조건식) throw 3;
}

void main(){
	//프로그램을 짤 때에는 보통 main전체를 try-catch구문으로 묶는다.
	try{
		//명령문들
		quotient();
		ex();
		//등등의 여러 함수들이 main에서 호출되어질 수 있다.
	}catch(int e){
		switch(e){
		case 1: //에러메시지를 출력하거나 log file(~.log : 년,월,일,시,분,초 및 에러메시지)을 저장하는 코드를 작성한다.
		case 2:
		case 3:
		//여러개의 케이스문을 둔다.
		}
	}
	//이렇게 하면 예외가 발생했을 때 어떤함수에서 예외가 발생했는지, 어떤 부분에서 발생했는지 파악하기 쉬워진다.
}