#include <iostream>
#include <iomanip>
using namespace std;

class Lotto{
private:   //��������. �����ϸ� ���� �� �������� �ʴ°�� private�̴�.
	int* m;
	int n;
public:
	Lotto(int size = 6);
	~Lotto();
	void selectLotto();   //��ȣ����� �Լ�
	void selectSort();	  //������� ��ȣ ����
	void dispLotto();     //���
};

Lotto::Lotto(int size){
	n = size;
	m = new int[n];
	srand(time(NULL)); //rand�Լ� �ʱ�ȭ �Լ�(rand�Լ��� seed �ٲٱ�), ���ڷ� �õ尪�� �ָ� �ȴ�
}					   //time(NULL)�� 1970�� 1�� 1�Ϻ��� ��������� �ð��� �ʷ� �����ִ� �Լ��̴�.
					   //time stamp
Lotto::~Lotto(){
	delete[] m;
}

void Lotto::selectLotto(){
	int a, b, chk;
	m[0] = rand()%45+1; //������ ������ 1�� ����� �Լ�. rand()�Լ��� 0~32767 ������ ���� 1���� ��ȯ�Ѵ�.

	for(a=1; a<n;){    //������ �κп� �ζǹ�ȣ ����
		m[a] = rand()%45+1;
		chk=0;

		for(b=0; b<a; b++){   //���������� �ߺ����� ����
			if(m[a]==m[b]){
				chk=1;
				break;
			}
		}
		if(!chk) a++;
	}
}
void Lotto::selectSort(){  //�������� �˰���
	int i, j;

	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			if(m[i]>m[j]){
				int temp=m[i];
				m[i]=m[j];
				m[j]=temp;
			}
		}
	}
}
void Lotto::dispLotto(){
	selectSort();

	for(int a=0; a<n; a++){
		cout<<setw(4)<<m[a];

	cout<<endl;
}

void ex3(){
	Lotto A;
	int num;

	while(1){
		cout<<"���� ���� �Է� (����=0) : ";
		cin<<num;
		if(num==0) break;

		for(int i=1; i<=num; i++){
			A.selectLotto();
			A.dispLotto();
		}
	}
}

void main(){
	ex3();
}