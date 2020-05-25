#include <iostream>
#include <iomanip>
using namespace std;

/*
문제. Gugudan 클래스를 만들어보자.

* Gugudan 클래스
  - private 멤버변수
    시작단, 끝단 : int형 변수
  - public 멤버함수
    setGugudan - 시작단, 끝단 대입
	dispGugudan - 구구단 출력
*/

class Gugudan{
private:
	int start, end;
public:
	void setGugudan(){
		cout<<"시작단 입력 : ";
		cin>>start;
		cout<<"끝단 입력 : ";
		cin>>end;
	}
	void setGugudan(int a, int b){
		start=a;
		end=b;
	}
	void dispGugudan(){
		for (int i=start; i<=end; i++){
			for (int j=1; j<=9; j++){
				cout<<i<<"×"<<j<<"="<<setw(2)<<i*j<<endl;
			}
			cout<<endl;
		}
	}
};

void main(){
	Gugudan g1;
	/*
	int s, e;
	cout<<"시작단 입력 : ";
	cin>>s;
	cout<<"끝단 입력 : ";
	cin>>e;
	g1.setGugudan(s,e);
	*/
	g1.setGugudan();
	g1.dispGugudan();
}