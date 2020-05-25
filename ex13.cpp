#include <iostream>
#include <iomanip>
using namespace std;

/*
����. Triangle Ŭ������ ����� ����.

* Triangle Ŭ����
  - private �������
    �غ�, ���� : int�� ����
  - public ����Լ�
    ������ - ������� �ʱ�ȭ(�Ű����� ����)
	������ - ���޹��� ������ ������� �ʱ�ȭ(�Ű����� 2��)
	setTriangle - �غ�, ���� ���� �Լ�
	getArea - �ﰢ���� ���� ���� �Լ�
*/

class Triangle{
private:
	int width, height;
public:
	Triangle(){
		width=0;
		height=0;
		//�Ǵ� width=height=0; �̶�� �� ���� �ִ�.
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
		return (double)width*height/2;   //�Ǵ� return width*height/2.0; �̶�� �ᵵ �ȴ�.
	}
};

void pr1(){
	Triangle t1(45, 7);
	cout<<"�ﰢ���� ���� : "<<t1.getArea()<<endl;

	Triangle t2;  //�������� ���� ���� �� Triangle t2(); �� ���� �ȵȴ�. �Ұ�ȣ�� �����ڿ� ���� ������ �� �� ����.
	t2.setTriangle(5, 12);
	cout<<"�ﰢ���� ���� : "<<t2.getArea()<<endl;
}
void main(){
	pr1();
}