#include <iostream>
#include <iomanip>
using namespace std;

//ex13.cpp�� ������ �����Ͽ� �ݷ��� �ʱ�ȭ�� �̿��غ���

class Triangle{
private:
	int width, height;
public:
	Triangle() : width(0), height(0){
		width=0;
		height=0;
		//�ݷ��ʱ�ȭ�� �׳� �ʱ�ȭ�� ���� �־ ����� ����.
	}
	Triangle(int width, int height) : width(width), height(height){ //�ݷ��� �ʱ�ȭ�� �̿��ϴ� ��� �������� �ߺ��� ���� �� �ִ�.
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
	cout<<"�ﰢ���� ���� : "<<t1.getArea()<<endl;

	Triangle t2;  
	t2.setTriangle(5, 12);
	cout<<"�ﰢ���� ���� : "<<t2.getArea()<<endl;
}
void main(){
	pr1();
}