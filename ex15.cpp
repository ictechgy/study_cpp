#include <iostream>
#include <iomanip>
using namespace std;

//ex14.cpp�� ������ �����Ͽ� ����Ʈ�Ű������� �̿��غ���

class Triangle{
private:
	int width, height;
public:
	//Triangle() : width(0), height(0){}
	Triangle(int width=0, int height=0) : width(width), height(height){
	} //defalut�����ڿ� ������ �� ����. �׳� ������ ȣ�� �� � �� ȣ���ؾ����� ��ȣ���������Ƿ�

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
	cout<<"�ﰢ���� ���� : "<<t1.getArea()<<endl;

	Triangle t2;  //1. t1.Triangle();	2. t2.Tiangle(����Ʈ ��);
	t2.setTriangle(5, 12);
	cout<<"�ﰢ���� ���� : "<<t2.getArea()<<endl;
}
void main(){
	pr1();
}