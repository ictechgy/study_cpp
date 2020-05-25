#include <iostream>
#include <iomanip>
using namespace std;

class Book{
private:
	char* title;
	char* author;
	int pub_year;
public:
	Book(char* s1, char* s2, int year){  //매개변수가 존재하는 생성자
		title = new char[strlen(s1)+1];  //동적할당으로 변수공간 생성(Heap)
		author = new char[strlen(s2)+1];
		strcpy(title, s1);
		strcpy(author, s2);
		pub_year = year;
		cout<<"생성자 호출"<<endl;
	}
	void getData(){
		cout<<"Title : "<<title<<endl;
		cout<<"Author : "<<author<<endl;
		cout<<"Publish-Year : "<<pub_year<<endl<<endl;
	}
	void delMem(){
		delete[] title;
		delete[] author;
	}
	~Book(){  //소멸자
		delete[] title;
		delete[] author;
		cout<<"소멸자 호출"<<endl;
	}
};

void ex1(){
	Book ob("Best C++", "홍길동", 2015); //Book이라는 클래스의 인스턴스인 ob객체를 생성하면서 매개변수가 존재하는 생성자 호출
	ob.getData();
	//ob.delMem();
	//ob.~Book();

	//소멸자는 객체가 동적할당으로 만들어졌든 그냥 만들어졌든 한번은 꼭 호출되어지는 것으로 보인다.
	//다만 객체(변수) 자체만 없어줄 뿐 객체 내에서 따로 또 만든 동적할당부분은 제거해주지 않으므로 클래스 내부에서 따로 또 동적할당을 한 경우 그 부분에 대해 delete해주는
	//구문을 적어줘야 할 것 같다.
}

void main(){
	ex1();  //여기서 생성하는 객체 자체는 일단 멤버변수는 stack에, 멤버함수는 code부에 생성
}

//함수에 문자열을 전달할 때 함수의 매개변수는 꼭 포인터여야 하나? 그냥 문자열배열로 넘어오는 문자열 받아올 수도 있지 않나?