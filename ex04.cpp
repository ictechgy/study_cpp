#include <iostream>
#include <iomanip>
using namespace std;

bool isBig(int a, int b){
	if(a > b){
		return 1;  
	}else{
		return 0;  
	}
	//return ������ ���ڸ� ��ȯ�Կ��� �ұ��ϰ� bool������ ��ȯ����. char�� �����ϰ� short �� int ����
	//��, 0�� char������ ��ȯ��Ű�°�� cout������ null�� �ν�?
}
//1�� 0 ��� true �� false�� �ᵵ �� bool �ڷ�����ȯŸ������ �� �ʿ�� ���� ��

void main(){
	cout<<isBig(10, 20)<<endl; //0�� ���

	bool b;
	b = 100;
	cout<<b<<endl; //1 ��µȴ�. C�� C++������ 0�� �ƴ� ��� ���� ������ �ν��ϸ� �ᱹ 1�� �νĵ�
}