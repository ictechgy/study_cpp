#include <iostream>
#include <iomanip>
using namespace std;

//ex13.cpp의 내용을 복사하여 콜론의 초기화를 이용해보자

class Triangle{
private:
	int width, height;
public:
	Triangle() : width(0), height(0){
		width=0;
		height=0;
		//콜론초기화와 그냥 초기화를 같이 넣어도 상관은 없다.
	}
	Triangle(int width, int height) : width(width), height(height){ //콜론의 초기화를 이용하는 경우 변수명의 중복을 피할 수 있다.
		this->width = width;
		this->height = height;
	}

	void setTriangle(int width, int height){
		this->width = width;
		this->height = height;
	}

	double getArea(){
		return (double)width*height/2;   
	}
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