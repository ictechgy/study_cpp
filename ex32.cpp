#include <iostream>
#include <iomanip>
using namespace std;

void ex1(){
	int a, b;

	cout<<"�ΰ��� ���� �Է� : ";
	cin>>a>>b;
	cout<<"a/b�� �� : "<<a/b<<endl;		//a�� b �Ѵ� double�̸� b�� 0�� �� ����� ������� ��. Infinity��
	cout<<"a/b�� ������ : "<<a%b<<endl;
}//a�� b�� double�̸� ������������ �� ���ϴ� ���� �ƴ϶� ������������ �̾�����.(������µ� �Ǽ����·� ������ �Ϸ� ��) ���� ������ ������ �Ұ�������

void ex2(){
	int a, b;

	while(1){
		cout<<"�ΰ��� ���� �Է� : ";
		cin>>a>>b;
		
		if(b!=0){
			cout<<"a/b�� �� : "<<a/b<<endl;		
			cout<<"a/b�� ������ : "<<a%b<<endl;
			break;
		}else{
			cout<<"b �Է��� �߸��Ǿ����ϴ�."<<endl;
		}
	}
}

void ex3(){
	int a, b;

	while(1){
		cout<<"�ΰ��� ���� �Է� : ";
		cin>>a>>b;
		
		try{
			if(b==0) throw b;  //���ܰ��� ����
			cout<<"a/b�� �� : "<<a/b<<endl;		
			cout<<"a/b�� ������ : "<<a%b<<endl;
			break;
		
		}catch(int e){		//���� ���� ����
			cout<<"b = "<<e<<"�Է��� �߸��Ǿ����ϴ�."<<endl;
		}

	}
}


void quotient(int a, int b){	//���� ���ϴ� �Լ���� ����
	if(b==0) throw 1;			//main���� ���� �Լ����� ������ �� ������ �߻��� �κп� ���� throw�� �ϵ��� �����.
}
void ex(){
	if(���ǽ�) throw 2;
	if(���ǽ�) throw 3;
}

void main(){
	//���α׷��� © ������ ���� main��ü�� try-catch�������� ���´�.
	try{
		//��ɹ���
		quotient();
		ex();
		//����� ���� �Լ����� main���� ȣ��Ǿ��� �� �ִ�.
	}catch(int e){
		switch(e){
		case 1: //�����޽����� ����ϰų� log file(~.log : ��,��,��,��,��,�� �� �����޽���)�� �����ϴ� �ڵ带 �ۼ��Ѵ�.
		case 2:
		case 3:
		//�������� ���̽����� �д�.
		}
	}
	//�̷��� �ϸ� ���ܰ� �߻����� �� ��Լ����� ���ܰ� �߻��ߴ���, � �κп��� �߻��ߴ��� �ľ��ϱ� ��������.
}