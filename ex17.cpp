#include <iostream>
#include <iomanip>
using namespace std;

class Book{
private:
	char* title;
	char* author;
	int pub_year;
public:
	Book(char* s1, char* s2, int year){  //�Ű������� �����ϴ� ������
		title = new char[strlen(s1)+1];  //�����Ҵ����� �������� ����(Heap)
		author = new char[strlen(s2)+1];
		strcpy(title, s1);
		strcpy(author, s2);
		pub_year = year;
		cout<<"������ ȣ��"<<endl;
	}
	void getData(){
		cout<<"Title : "<<title<<endl;
		cout<<"Author : "<<author<<endl;
		cout<<"Publish-Year : "<<pub_year<<endl<<endl;
	}
	void delMem(){
		delete[] title;
		delete[] author;
	}
	~Book(){  //�Ҹ���
		delete[] title;
		delete[] author;
		cout<<"�Ҹ��� ȣ��"<<endl;
	}
};

void ex1(){
	Book ob("Best C++", "ȫ�浿", 2015); //Book�̶�� Ŭ������ �ν��Ͻ��� ob��ü�� �����ϸ鼭 �Ű������� �����ϴ� ������ ȣ��
	ob.getData();
	//ob.delMem();
	//ob.~Book();

	//�Ҹ��ڴ� ��ü�� �����Ҵ����� ��������� �׳� ��������� �ѹ��� �� ȣ��Ǿ����� ������ ���δ�.
	//�ٸ� ��ü(����) ��ü�� ������ �� ��ü ������ ���� �� ���� �����Ҵ�κ��� ���������� �����Ƿ� Ŭ���� ���ο��� ���� �� �����Ҵ��� �� ��� �� �κп� ���� delete���ִ�
	//������ ������� �� �� ����.
}

void main(){
	ex1();  //���⼭ �����ϴ� ��ü ��ü�� �ϴ� ��������� stack��, ����Լ��� code�ο� ����
}

//�Լ��� ���ڿ��� ������ �� �Լ��� �Ű������� �� �����Ϳ��� �ϳ�? �׳� ���ڿ��迭�� �Ѿ���� ���ڿ� �޾ƿ� ���� ���� �ʳ�?