#include <iostream>
#include <iomanip>
using namespace std;

/*
문제. Triangle 클래스를 만들어 보자.

* Triangle 클래스
  - private 멤버변수
    밑변, 높이 : int형 변수
  - public 멤버함수
    생성자 - 멤버변수 초기화(매개변수 없음)
	생성자 - 전달받은 값으로 멤버변수 초기화(매개변수 2개)
	setTriangle - 밑변, 높이 대입 함수
	getArea - 삼각형의 넓이 리턴 함수
*/

class Triangle{
private:
	int width, height;
public:
	Triangle(){
		width=0;
		height=0;
		//또는 width=height=0; 이라고 쓸 수도 있다.
	}
	Triangle(int width, int height){
		this->width = width;
		this->height = height;
	}

	void setTriangle(int width, int height){
		this->width = width;
		this->height = height;
	}

	double getArea(){
		return (double)width*height/2;   //또는 return width*height/2.0; 이라고 써도 된다.
	}
};

void pr1(){
	Triangle t1(45, 7);
	cout<<"삼각형의 넓이 : "<<t1.getArea()<<endl;

	Triangle t2;  //전달해줄 값이 없을 때 Triangle t2(); 로 쓰면 안된다. 소괄호는 생성자에 값을 전달해 줄 때 쓴다.
	t2.setTriangle(5, 12);
	cout<<"삼각형의 넓이 : "<<t2.getArea()<<endl;
}
void main(){
	pr1();
}