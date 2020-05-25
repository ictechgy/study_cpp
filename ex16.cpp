#include <iostream>
#include <iomanip>
using namespace std;

//ex15.cpp의 내용을 복사하여 멤버함수의 선언과 외부정의를 해보자

class Triangle{
private:
	int width, height;
public:
	Triangle(int width=0, int height=0);
	void setWidth(int width);
	void setHeight(int height);
	void setTriangle(int width, int height);
	int getWidth();
	int getHeight();
	double getArea();
	void output();
};

void pr1(){
	Triangle t1(45, 7);
	cout<<"삼각형의 넓이 : "<<t1.getArea()<<endl;

	Triangle t2; 
	t2.setTriangle(5, 12);
	cout<<"삼각형의 넓이 : "<<t2.getArea()<<endl;
}
void main(){
	pr1();
}


//Triangle 클래스 멤버함수의 외부정의

Triangle::Triangle(int width, int height) : width(width), height(height){
} //이런식으로 생성자도 외부에 정의를 할 수도 있으며 콜론의 초기화 가능하다. 디폴트매개변수부분선언부에만 써야한다!!

void Triangle::setWidth(int width){
	this->width = width;
}

void Triangle::setHeight(int height){
	this->height = height;
}

void Triangle::setTriangle(int width, int height){
	this->width = width;
	this->height = height;
}

int Triangle::getWidth(){
	return width;
}

int Triangle::getHeight(){
	return height;
}

double Triangle::getArea(){
	return (double)width*height/2;   
}

void Triangle::output(){
	cout<<"밑변은"<<width<<"이며 높이는"<<height<<"입니다."<<endl;
}