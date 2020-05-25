#include <iostream>
#include <iomanip>
using namespace std;

class Lotto{
private:   //생략가능. 생략하면 따로 뭐 지정하지 않는경우 private이다.
	int* m;
	int n;
public:
	Lotto(int size = 6);
	~Lotto();
	void selectLotto();   //번호만드는 함수
	void selectSort();	  //만들어진 번호 정렬
	void dispLotto();     //출력
};

Lotto::Lotto(int size){
	n = size;
	m = new int[n];
	srand(time(NULL)); //rand함수 초기화 함수(rand함수의 seed 바꾸기), 인자로 시드값을 주면 된다
}					   //time(NULL)은 1970년 1월 1일부터 현재까지의 시간을 초로 구해주는 함수이다.
					   //time stamp
Lotto::~Lotto(){
	delete[] m;
}

void Lotto::selectLotto(){
	int a, b, chk;
	m[0] = rand()%45+1; //임의의 정수를 1개 만드는 함수. rand()함수는 0~32767 사이의 숫자 1개를 반환한다.

	for(a=1; a<n;){    //나머지 부분에 로또번호 기입
		m[a] = rand()%45+1;
		chk=0;

		for(b=0; b<a; b++){   //이전값과의 중복여부 검증
			if(m[a]==m[b]){
				chk=1;
				break;
			}
		}
		if(!chk) a++;
	}
}
void Lotto::selectSort(){  //선택정렬 알고리즘
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
		cout<<"구매 갯수 입력 (종료=0) : ";
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