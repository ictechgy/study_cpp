#include <iostream>
#include <iomanip>
using namespace std;

/*
����. Gugudan Ŭ������ ������.

* Gugudan Ŭ����
  - private �������
    ���۴�, ���� : int�� ����
  - public ����Լ�
    setGugudan - ���۴�, ���� ����
	dispGugudan - ������ ���
*/

class Gugudan{
private:
	int start, end;
public:
	void setGugudan(){
		cout<<"���۴� �Է� : ";
		cin>>start;
		cout<<"���� �Է� : ";
		cin>>end;
	}
	void setGugudan(int a, int b){
		start=a;
		end=b;
	}
	void dispGugudan(){
		for (int i=start; i<=end; i++){
			for (int j=1; j<=9; j++){
				cout<<i<<"��"<<j<<"="<<setw(2)<<i*j<<endl;
			}
			cout<<endl;
		}
	}
};

void main(){
	Gugudan g1;
	/*
	int s, e;
	cout<<"���۴� �Է� : ";
	cin>>s;
	cout<<"���� �Է� : ";
	cin>>e;
	g1.setGugudan(s,e);
	*/
	g1.setGugudan();
	g1.dispGugudan();
}