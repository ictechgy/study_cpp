#include <iostream>
#include <iomanip>
using namespace std;

//ex15.cpp�� ������ �����Ͽ� ����Լ��� ����� �ܺ����Ǹ� �غ���

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
	cout<<"�ﰢ���� ���� : "<<t1.getArea()<<endl;

	Triangle t2; 
	t2.setTriangle(5, 12);
	cout<<"�ﰢ���� ���� : "<<t2.getArea()<<endl;
}
void main(){
	pr1();
}


//Triangle Ŭ���� ����Լ��� �ܺ�����

Triangle::Triangle(int width, int height) : width(width), height(height){
} //�̷������� �����ڵ� �ܺο� ���Ǹ� �� ���� ������ �ݷ��� �ʱ�ȭ �����ϴ�. ����Ʈ�Ű������κм���ο��� ����Ѵ�!!

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
	cout<<"�غ���"<<width<<"�̸� ���̴�"<<height<<"�Դϴ�."<<endl;
}