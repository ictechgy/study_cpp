#include <iostream>
#include <iomanip>
using namespace std;

class AAA{	//base Ŭ����
public:
	AAA(){  //�⺻������ ȣ��� �θ�Ŭ������ ����Ʈ ������
		cout<<"AAA() call"<<endl;
	}
	AAA(int i){  //�θ�Ŭ�������� �Ű������� �ִ� �����ڴ� ���� ȣ�����־�� �Ѵ�.
		cout<<"AAA(int i) call" <<endl;
	}
};

class BBB : public AAA{ //derived Ŭ����
public:
	BBB(){  // : AAA() �� ȣ��Ǿ�����. �Ű������� ���� �θ�����ڴ� �⺻������ ȣ��Ǹ� ������ �����ϴ�.
		cout<<"BBB() call"<<endl;
	}
	BBB(int j){ // : AAA() ȣ��
		cout<<"BBB(int j) call"<<endl;
	}
};
//�̷��� �ڽ�Ŭ���� �θ�Ŭ���� �� ��������� ������ �ڽ�Ŭ������ ��ü�����ϸ� 1byte�� �⺻������ �����ȴ�. ���� �θ�Ŭ�����κе� �־�� �ؼ� 2byte�ϰŰ��Ҵµ�..
//�׸��� ���߻����??

void ex1(){
	cout<<"��ü 1 ����"<<endl;
	BBB bbb1;  //bbb1.BBB();

	cout<<"��ü 2 ����"<<endl;
	BBB bbb2(10);  //bbb2.BBB(10);
}


class Person{
private:
	int age;
	char name[20];
public:
	Person(int a, char* n){
		age = a;
		strcpy(name, n);
	}
	int getAge() const{
		return age;
	}
	const char* getName() const{
		return name;
	}
};

class Student : public Person{
	char major[20];
public:
	Student(int a, char* n, char* m) : Person(a, n){  //�θ�Ŭ������ ������ ȣ��
		strcpy(major, m);
	}
	const char* getMajor() const{
		return major;
	}
	void showData() const{
		cout<<"�̸� : "<<getName()<<endl;
		cout<<"���� : "<<getAge()<<endl;
		cout<<"���� : "<<getMajor()<<endl;
	}
};

void ex2(){
	Student bbb(25, "ȫ�浿", "��ǻ��");
	bbb.showData();
}

void main(){
	ex1();
	ex2();
}