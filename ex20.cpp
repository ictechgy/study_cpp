#include <iostream>
#include <iomanip>
using namespace std;

class AAA{
private:
	int val;
public:
	AAA(int n=0){
		cout<<"AAA(int n) ȣ��"<<this<<endl;
		this->val = n;
	}
	AAA(AAA& r){ //��������� - ���� �ڷ����� ��ü�� ���ڷ� ���� �� �ִ� ������
		cout<<"AAA(AAA& r) ȣ��"<<this<<endl;
		this->val = r.val;
	}
	~AAA(){
		cout<<"�Ҹ��� ����"<<this<<endl;
	}
	void showData(){
		cout<<this->val<<endl;
	}
};

void ex1(){
	AAA a(10); //a.AAA(10);
	a.showData();
	AAA b = a; //��ü����. AAA b(a); -> b.AAA(a);
	b.showData();
	cout<<"a = "<<&a<<", b = "<<&b<<endl;
}


void test2(AAA b){  //AAA b = a; �Ǵ� AAA b(a); ���� b.AAA(a) ����
	cout<<"b = "<<&b<<endl;
	b.showData();
}
void ex2(){
	AAA a(30);  //a.AAA(30);
	cout<<"a = "<<&a<<endl;
	test2(a);
}

//�Լ��� �۵���Ű�� �� ������� ������ �����ϰ��� �� �� �ӽú������ ���� ���������.
//�ӽú����� ��������� �Լ��� ���(����)���� ������ �ڿ� ������ �����Ѵٴ� ���̴�.
//������ 1�� ����

double plus(double a, double b){
	return a+b;
}
void plusTest(){
	double c;
	c = plus(1.2, 2.5);  //���Կ������� ��Ģ�� ��� ������=�����Ͱ�; �̹Ƿ� �� �ٰ����� ����� �۵��� �� ����.
	cout<<c<<endl;	//������ �ӽú����� ���������μ� ��밡���� �ڵ��̴�.
}
//c = plus(1.2, 2.5)�� ��������� ��� �Ʒ��� ����. 
//double �ӽú��� = �Լ� �������� 3.7;		=> �ӽú����� ����� �Լ��� �������� �����Ѵ�.
//c = �ӽú���;		=> �ش� �ӽú����� ���� c�� �����Ѵ�.

//���� ����ڷ��� = ���ϰ��� �ڷ��� = �ӽú����� �ڷ��� �̶�� �� �� �ִ�.
//void�� �ӽú����� ������ ����� ��

//�̷��� �Լ��� ���ϰ��� ������ �� ��ǻ�ʹ� �� ���� �ӽú����� ��� �����صд�.



AAA test2(){
	AAA b(10);  //b.AAA(10);
	cout<<"b = "<<&b<<endl;
	return b;
}
void ex3(){
	AAA a;  //a.AAA();
	cout<<"a = "<<&a<<endl;
	a = test2();  //AAA imsi = b; => AAA imsi(b); => imsi.AAA(b); ��� �ڵ尡 ���������� �۵�(�ӽ�Ŭ�������� ����). ���� a = imsi; ��� �ڵ� �۵�
	//�ӽú����� a�� ���� �������� �ڿ��� ��ü�� �Ҹ��� �۵��Ѵ�. imsi.~AAA();
	a.showData();
}
//�׳����� �̹� ���� aŬ��������(��ü)�� �ٸ� ��ü���� = ���Կ����ڸ� ���ؼ� ������� ���� ���� ���� �� �ֳ�����? (�ڹٴ� ������������ ����Ű�� �� ��)
//���࿡ Ŭ���� ���ο� ������������ �ְ�, �� ������������ heap������ ����Ű�� ��������ٸ�, =���� �����Ѱ�� �� ��ü�� ���� heap������ ����Ű�� �Ƿ���?
//=> �׷� �� ����. ���� �Ȱ��� �����ϴ� ������״� �ּҰ��� ����� ��. �׸��� ���� Ŭ����Ÿ�Գ����� ������ ������ ��?

//��ü��ü�� �����Ҵ����� ����� �װ� �����Ѵٰų�.. ������ �� Ŭ���� ���ο��� ������������ ����Ű�� ������ ���� �ʰ�(�������簡 �ȵǰ�) �Ѵٰų�..
//=> ���ó� ��ü ��ü�� �����Ҵ����� ����� �׳� ���Կ����ڷ� (���Թ�����μ�)�����ϸ� �̴� ������� �� ��ü�� ����� ���̴�.(���� ����)
//=> ��ü���� ���Կ����ھ��°� �ᱹ ���� �����Ű�� ���ϻ�.. �������縸 �����Ѱ� �ƴұ�

//���࿡ ex3()���� AAA a = Test2(); �� �ߴٸ� ��������ڰ� �ι� �۵��߰���?. �׷��� AAA a(Test2()); ��� �ᵵ �Ǵ°ǰ�



class Person{
	char* name;
	char* phone;
	int age;
public:
	Person(char* a, char* b, int c){
		name = new char[strlen(a)+1];
		strcpy(name, a);

		phone = new char[strlen(b)+1];
		strcpy(phone, b);

		age = c;
	}
	/*
	Person(Person& r){     //����Ʈ ����������� ���
		name=r.name;
		phone=r.phone;
		age=r.age;
	}
	//���� ����μ� ���� ������ ����Ű�� ��(�ּҰ��� �����)
	*/
	Person(Person& r){
		name = new char[strlen(r.name)+1];
		strcpy(name, r.name);

		phone = new char[strlen(r.phone)+1];
		strcpy(phone, r.phone);

		age = r.age;
	} //���� ���縦 ���� ���� ������ ���������

	~Person(){
		delete[] name;
		delete[] phone;
	}

	void showData(){
		cout<<name<<endl;
		cout<<phone<<endl;
		cout<<age<<endl;
	}
};
void ex4(){
	Person p1("ȫ�浿", "010-1234-5678", 25);
	Person p2=p1; //Person p2(p1);
	p1.showData();
	p2.showData();
	//p2.~Person();
	//p1.~Person();
}
/*
���� 
Person p2;
p2=p1;
�̶�� ������ �׳� �������翴�� ��
*/


void main(){
	ex1();
	ex2();
	ex3();
	ex4();
}


//��������ڸ� ������ִ� ��(�����ڿ����ε��̶�� ���� �� ��)�� Ŭ���� ��������� �����ͺ����̰� �����Ҵ��� ���� ��� �ַ� ������ش�.
//�Ҹ��ڴ� �������̵� �����ΰ�