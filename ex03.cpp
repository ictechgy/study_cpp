#include <iostream>
#include <iomanip>
using namespace std;

int ex1(int a=10); //�Լ��� ����

void main(){
	cout<<ex1()<<endl;
	cout<<ex1(10)<<endl;
}

int ex1(int a){  //�Լ��� ����
	return a+100;
}
//����Ʈ �Ű������� �����ϴ� �Լ��� �ۼ��� �� �Լ��� ������ ���� �ΰ� �Լ��� ���Ǹ� �Ʒ��� �δ°��,
//�����尪�� ����ο����� �־�� �Ѵ�.