#include <iostream>
#include <iomanip>
using namespace std;

/*
���� 1. ��� Ŭ������ ����� ��� Ŭ������ ��ӹ޴� ������ ��� Ŭ������ �ӽû�� Ŭ������ ����� ����.
	- ���Ի���� ���� �޿��� �⺻�޿� ������ ���ؼ� ���Ѵ�.
	- �ӽû���� ���� �޿��� �ϴ�޿��׿� �ٹ��ϼ��� ���ؼ� ���Ѵ�.

	1. Employee Ŭ����
	- private �������
		�̸�, �ֹε�Ϲ�ȣ
	- public ����Լ�
		setName - �̸� ����
		setId - �ֹε�Ϲ�ȣ ����
		getName - �̸� ����
		getId - �ֹε�Ϲ�ȣ ����

	2. FullTime Ŭ������ Employee Ŭ���� ���
	- private �������
		��� �ڵ�, �⺻��, ����
	- public ����Լ�
		setEmpcode - ��� �ڵ� ����
		setBaseSalary - �⺻�� ����
		setSudang - ���� ����
		outData - �̸�, �ֹε�Ϲ�ȣ, ����ڵ�, �⺻��, ����, ���� �޿� ���

	3. PartTime Ŭ������ Employee Ŭ���� ���
	- private �������
		�ϴ�޿���, �ٹ��ϼ�
	- public ����Լ�
		setDayPay - �ϴ�޿��� ����
		setWorkDay - �ٹ��ϼ� ����
		outData - �̸�, �ֹι�ȣ, �ϴ�޿���, �ٹ��ϼ�, ���� �޿� ���

	4. ��� ���
	------------���Ի��-------------
	����		: ȫ�浿
	�ֹε�Ϲ�ȣ: 901012-1234567
	��� �ڵ�	: 20161201
	�⺻��		: 1500000
	����		: 700000
	���� �޿�	: 2200000

	------------�ӽû��-------------
	����		: ���ʾ�
	�ֹε�Ϲ�ȣ: 920712-2345678
	�ϴ�޿���	: 50000
	�ٹ��ϼ�	: 20
	���� �޿�	: 1000000
*/

class Employee{
private:
	char name[20], id[20];
public:
	void setName(char* pn){  //�Ű������� char pn[20]���� �迭 ���� ������
		strcpy(name, pn);	//���࿡ �����ڸ� ���� ������ ���� �ִ´ٸ� �װ� �ʱ�ȭ���״ϱ� strcpy�� �Ƚᵵ ������
	}
	void setId(char* pi){
		strcpy(id, pi);
	}
	char* getName(){  //�ּҰ��� �����ٶ� char[20] �̰ɷ� ��ȯ�� �������� ���ϳ�.. ��
		return name;
	}
	char* getId(){
		return id;
	}
};

class FullTime : public Employee{   //��ӹ��� ���� ���������� ������ �� �ִµ� �� ������ private�� ��
private:							//private�� ��ӹ޾Ҵٸ� �ڽ�Ŭ���������� ������ �θ�Ŭ������ public���� ���Ѿ��� ���� ����������
	char empcode[10];				//�ܺ��Լ����� �ڽİ�ü������ �θ��� public ����� ���� �Ұ�������
	int baseSalary, sudang;
public:
	void setEmpcode(char* pe){
		strcpy(empcode, pe);
	}
	void setBaseSalary(int b){
		baseSalary = b;
	}
	void setSudang(int s){
		sudang=s;
	}
	void outData(){
		cout<<"------------���Ի��-------------"<<endl;
		cout<<"����\t\t: "<<getName()<<endl;
		cout<<"�ֹε�Ϲ�ȣ\t: "<<getId()<<endl;
		cout<<"��� �ڵ�\t: "<<empcode<<endl;
		cout<<"�⺻��\t\t: "<<baseSalary<<endl;
		cout<<"����\t\t: "<<sudang<<endl;
		cout<<"���� �޿�\t: "<<baseSalary+sudang<<endl;
		//setw()�� ����Ȯ�� �� ����ص� �Ǵµ� �� �� cout<<left; �� �տ� ������� ���� ���� �� ��µ�
	}
};

class PartTime : public Employee{
private:
	int dayPay, workDay;
public:
	void setDayPay(int p){
		dayPay = p;
	}
	void setWorkDay(int w){
		workDay = w;
	}
	void outData(){
		cout<<"------------�ӽû��-------------"<<endl;
		cout<<"����\t\t: "<<getName()<<endl;
		cout<<"�ֹε�Ϲ�ȣ\t: "<<getId()<<endl;
		cout<<"�ϴ�޿���\t: "<<dayPay<<endl;
		cout<<"�ٹ��ϼ�\t: "<<workDay<<endl;
		cout<<"���� �޿�\t: "<<dayPay*workDay<<endl;
	}
};


void pr1(){
	FullTime f;
	f.setName("ȫ�浿");
	f.setId("901012-1234567");
	f.setEmpcode("20161201");
	f.setBaseSalary(1500000);
	f.setSudang(700000);
	f.outData();

	PartTime p;
	p.setName("���ʾ�");
	p.setId("950712-2345678");
	p.setDayPay(50000);
	p.setWorkDay(20);
	p.outData();
}

void main(){
	pr1();
}