#include <iostream>
#include <iomanip>
using namespace std;

void print(int a, int b){
	cout<<a<<" "<<b<<endl;
}
void print(double a, int b){
	cout<<a<<" "<<b<<endl;
}
void print(int a, char b){
	cout<<a<<" "<<b<<endl;
}
void print(double a, char b){
	cout<<a<<" "<<b<<endl;
}

void ex1(){
	print(1,2);			//print(int , int );
	print(1.2, 10);		//print(double , int );
	print(10, 'a');		//print(int , char );
	print(1.2, 'a');	//print(double , char );
	print('a', 10);		//print(char , int ); 또는 print(int , int );
}
//함수 오버로딩의 장점은 동일함수명으로 매개변수가 다른 함수들을 하나의 함수처럼 쓰고 관리할 수 있다는 것이다. 
//하지만 여전히 매개변수로 들어갈 자료형에 대한 함수가 존재하지 않는다면 일일히 만들어줘야 한다는 단점이 존재한다.
//-> 이럴 때 템플릿을 사용한다.


template <typename S, typename T>	//S와 T라는 자료형을 만듬
void print1(S a, T b){
	cout<<a<<" "<<b<<endl;
} //템플릿으로 만든 임시 자료형은 하나의 함수에만 적용된다.(바로 아래에 정의되어있는 하나의 함수/클래스에 대해서만 적용)
void ex2(){
	print1(1, 2);		//print1(int , int );
	print1(1.2, 10);	//print1(double , int );
	print1(10, 'a');	//print1(int , char );
	print1(1.2, 'a');	//print1(double , char );
	print1(1.2, "Test");	//print1(double , char* );
}
//포인터 외에도 구조체나 클래스가 typename의 자료형이 될 수 있다. -> 그렇다면 배열이나 레퍼런스변수는?


template <typename T>
class Data{
	T data;
public:
	Data(T a){
		data = a;
	}
	void setData(T d){
		data = d;
	}
	T getData(){
		return data;
	}
};
void ex3(){
	Data<int> d1(10);
	d1.setData(100);
	Data<char> d2('a');
	cout<<d1.getData()<<endl;
	cout<<d2.getData()<<endl;
}


/*
Stack 영역은 항아리라고 볼 수도 있으며 LIFO(Last Input First Output)구조이다. 제일 나중에 생긴 것부터 제일 먼저 처리(제거)한다.
-> stack영역에 생긴 객체가 제거될 때 가장나중에 생긴게 먼저 없어지는 이유

stack영역에 데이터를 넣을 때에는 push라고 하며 데이터를 꺼낼 때에는 pop이라고 한다.
데이터를 더 넣을 수 없을 때 더 넣으려고 하면 오류가 발생하는데 이 때의 오류를 overflow라고 한다.
데이터를 더 이상 꺼낼 수 없을 때 더 꺼내려고 할 때에도 오류가 발생하는데 이 때의 오류는 underflow라고 한다.

포인터 연산
주소와 연산자가 만나면 산술연산이 아닌 주소연산을 진행한다.
주소 + 1 은 주소값의 숫자에 숫자 1을 더하라는 것이 아닌 다음변수(방)의 주소를 계산하라는 계산식이다.
마찬가지로 주소 - 1 은 주소값 기준으로 전 변수(방)의 주소를 계산하라는 계산식이다.
증감연산도 마찬가지로 적용된다. 
*/

template <typename T>
class Stack{
private:
	T* bottom, top;
	int gae;
public:
	Stack(){
		bottom=top=NULL;
		gae=0;
	}
	Stack(int a){
		gae=a;
		bottom = new T[a];
		top = bottom;
	}
	int OverFlow(){
		return (top==bottom+gae ? 1:0);		//포인터 연산
	}
	int UnderFlow(){
		return (top==bottom ? 1:0);
	}
	int IsEmpty(){
		return (top==bottom ? 1:0);
	}
	void Push(T a){
		if(OverFlow()){
			cout<<"OverFlow\n";
			return;
		}
		*top++ = a;
	}
	T Pop(){
		if(UnderFlow(){
			cout<<"UnderFlow\n";
			return 0;
		}
		T im = *--top;
		return im;
	}
	~Stack(){
		delete[] bottom;
	}
};

void ex4(){
	Stack<int> Kim(2);
	Kim.Push(10);
	Kim.Push(20);
	Kim.Push(30);
	cout<<Kim.Pop()<<endl;
	cout<<Kim.Pop()<<endl;

	Stack<char> Lee(2);
	Lee.Push('A');
	Lee.Push('B');
	cout<<Lee.Pop()<<endl;
	cout<<Lee.Pop()<<endl;
	cout<<Lee.Pop()<<endl;
}

void main(){
	ex1();
	ex2();
	ex3();
	ex4();
}