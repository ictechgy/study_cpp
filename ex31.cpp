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
	print('a', 10);		//print(char , int ); �Ǵ� print(int , int );
}
//�Լ� �����ε��� ������ �����Լ������� �Ű������� �ٸ� �Լ����� �ϳ��� �Լ�ó�� ���� ������ �� �ִٴ� ���̴�. 
//������ ������ �Ű������� �� �ڷ����� ���� �Լ��� �������� �ʴ´ٸ� ������ �������� �Ѵٴ� ������ �����Ѵ�.
//-> �̷� �� ���ø��� ����Ѵ�.


template <typename S, typename T>	//S�� T��� �ڷ����� ����
void print1(S a, T b){
	cout<<a<<" "<<b<<endl;
} //���ø����� ���� �ӽ� �ڷ����� �ϳ��� �Լ����� ����ȴ�.(�ٷ� �Ʒ��� ���ǵǾ��ִ� �ϳ��� �Լ�/Ŭ������ ���ؼ��� ����)
void ex2(){
	print1(1, 2);		//print1(int , int );
	print1(1.2, 10);	//print1(double , int );
	print1(10, 'a');	//print1(int , char );
	print1(1.2, 'a');	//print1(double , char );
	print1(1.2, "Test");	//print1(double , char* );
}
//������ �ܿ��� ����ü�� Ŭ������ typename�� �ڷ����� �� �� �ִ�. -> �׷��ٸ� �迭�̳� ���۷���������?


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
Stack ������ �׾Ƹ���� �� ���� ������ LIFO(Last Input First Output)�����̴�. ���� ���߿� ���� �ͺ��� ���� ���� ó��(����)�Ѵ�.
-> stack������ ���� ��ü�� ���ŵ� �� ���峪�߿� ����� ���� �������� ����

stack������ �����͸� ���� ������ push��� �ϸ� �����͸� ���� ������ pop�̶�� �Ѵ�.
�����͸� �� ���� �� ���� �� �� �������� �ϸ� ������ �߻��ϴµ� �� ���� ������ overflow��� �Ѵ�.
�����͸� �� �̻� ���� �� ���� �� �� �������� �� ������ ������ �߻��ϴµ� �� ���� ������ underflow��� �Ѵ�.

������ ����
�ּҿ� �����ڰ� ������ ��������� �ƴ� �ּҿ����� �����Ѵ�.
�ּ� + 1 �� �ּҰ��� ���ڿ� ���� 1�� ���϶�� ���� �ƴ� ��������(��)�� �ּҸ� ����϶�� �����̴�.
���������� �ּ� - 1 �� �ּҰ� �������� �� ����(��)�� �ּҸ� ����϶�� �����̴�.
�������굵 ���������� ����ȴ�. 
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
		return (top==bottom+gae ? 1:0);		//������ ����
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