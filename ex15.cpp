#include <iostream>
#include <iomanip>
using namespace std;

//ex14.cpp의 내용을 복사하여 디폴트매개변수를 이용해보자

class Triangle{
private:
	int width, height;
public:
	//Triangle() : width(0), height(0){}
	Triangle(int width=0, int height=0) : width(width), height(height){
	} //defalut생성자와 공존할 수 없다. 그냥 생성자 호출 시 어떤 걸 호출해야할지 모호해져버리므로

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

	Triangle t2;  //1. t1.Triangle();	2. t2.Tiangle(디폴트 값);
	t2.setTriangle(5, 12);
	cout<<"삼각형의 넓이 : "<<t2.getArea()<<endl;
}
void main(){
	pr1();
}