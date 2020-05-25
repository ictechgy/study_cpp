#include <iostream>
#include <iomanip>
using namespace std;

class Test{
private:
	int a;
	const int b;
	static int c;
	static const int d = 5;   //����� ���ÿ� �ʱ�ȭ�� ������ ������ �׸�
	
public:
	Test():b(10){  //const�� ����� ���ÿ� �ʱ�ȭ�� �Ұ����ϸ� �ݷ��� �ʱ�ȭ������ �ʱ�ȭ�� �����ϴ�.
		a = 10;  //�Ϲݸ�������� �����ڿ����� ��� ������ε� �ʱ�ȭ�� �����ϴ�. �ݷ��� �ʱ�ȭ�� �����ϴ�.
		c = 10;  //static ��������� ��ü�� �����ɶ����� ������ �ǰڴٸ� ������ ���ο��� �� ������ �����ϴ�.
	}
	void method(){
		c = 10;  //static ��������� �Լ��� ���� �� ���� ����
		func(); //�Ϲ� ����Լ������� static����Լ��� ȣ���� �� �ִ�.
	}
	void static func(){
		cout<<"hello"<<endl;
		cout<<c<<d<<endl; //static����Լ������� static����� ��� �����ϴ�.
	}
};

int Test::c; //�� ������ �ݵ�� �����ؾ��ϸ� ������� �����Ͽ���
//static ��������� ���� ������ ���𱸹����μ� �ʼ��ۼ��ؾ��ϸ� ���⼭ �ʱ�ȭ�� �����ϴ�.


void main(){
	Test t1;
	Test t2;
	t1.method();
}