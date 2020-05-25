#include <iostream>   //이걸 하자마자 이 파일에는 cin과 cout객체가 전역변수(객체)로 존재하게 됨 - 전역변수이므로 RAM의 DATA영역에 생성
#include <iomanip>
using namespace std;

class OL{
private:
	char* data;
public:
	friend istream& operator >> (istream& i, OL& in);
	friend ostream& operator << (ostream& o, OL& out);
	~OL(){
		delete[] data;
	}
};

istream& operator >> (istream& i, OL& in){  // 'istream객체 >> OL객체'  코드가 있을 때 작동 될 전역함수
		in.data = new char[200];
		fflush(stdin);
		i.get(in.data, 200);
		return i;
}

ostream& operator << (ostream& o, OL& out){ // 'ostream객체 << OL객체' 코드가 있을 때 작동 될 전역함수
		o<<out.data;
		return o;
}

void ex1(){
	OL ob;
	cout<<"문자열 입력 : ";
	cin>>ob;  // cin.operator>>(ob)또는 operator>>(cin, ob)를 찾음
	cout<<ob<<endl; // cout.operator(ob) 또는 operator(cout, ob)를 찾음
}

void main(){
	ex1();
}

/*
작동방식
cin>>ob;를 우선 보자. 컴퓨터는 >>연산이 있는 것을 보지만 좌우 항 모두 일반변수가 아니므로 오퍼레이터함수를 작동시키려 한다.
먼저 cin이 왼쪽에 있으므로 cin.operator>>(ob) 가 작동될 수 있는지 cin객체의 클래스(istream)내부를 살펴본다. 하지만 ob라는 매개변수에 상응하는 함수는 존재하지 않는다.
이후 오퍼레이터 전역함수를 찾는다. operator>>(cin, ob)에 맞는 함수를 찾던 도중 'istream& operator>>(istream& i, OL& in)' 를 찾게 된다.
cin객체에는 i라는 별명을 붙이고 ob라는 객체에는 in이라는 별명을 짓는다. 함수의 내용을 실행시키는데,

		in.data = new char[200];				ob.data = new char[200];
		fflush(stdin);							fflush(stdin);
		i.get(in.data, 200);             ->		cin.get(ob.data, 200);
		return i;								return cin;
위와 같은 내용으로 실행하게 된다.
실행 후 return을 하게 되는데, istream& imsi = i 내용으로 반환 후 오퍼레이터함수는 종료된다.

왜 오퍼레이터함수 매개변수로 레퍼런스를 두었는가? 
객체가 동적할당된게 아닌 이상 매개변수에 그냥 클래스변수가 생성되게 해서 바깥함수 객체의 값을 복사해올 필요는 없다.
더군다나 객체들의 값을 직접적으로 이용을 하고 변경도 진행할 것이기 때문에 오퍼레이터함수에는 레퍼런스변수를 매개변수로 둔다.

반환값으로 istream& 이 있는 이유는? istream 으로 두어도 되는 것 아닌가?
매개변수로 cin이 i라는 이름이 붙어 들어왔다. 함수 내에서 쓰는 i는 사실 cin을 쓰는 것과 다름이 없다.
이 함수가 끝난 뒤에도, cin은 쓰일 수 있다. 이를테면 cin>>ob1 >> ob2; 와 같은 경우.
따라서 cin의 반환은 꼭 필요한데, 사실 istream으로 두어도 상관은 없을 것이다. 하지만 cin 객체를 굳이 istream 임시변수에 복사시켜서 내보낼 필요가 있는가? 이다.
복사생성자가 어찌 되어있는지는 모르겠지만, 그냥 cin자체를 내보내도 상관이 없다는 것이다. 따라서 위와 같이 istream& 형태로 내보내게 되면 cin에는 i라는 별칭 외에도
imsi라는 별칭이 생기는 것이고(레퍼런스변수로 레퍼런스를 가리키면 결국 최종객체의 별명이 2개가 생성됨) cin자체를 가지고 또 다른 연산에 대해 쓸 수 있게 된다.


cout<<ob 작동원리
우선 좌우항 모두 일반적인 값(변수)가 아니고 객체이므로 컴퓨터는 오퍼레이터함수를 작동시키려 한다.
cout.operator<<(ob)가 존재하는지 먼저 살펴보는데 해당 타입에 대한 함수는 멤버함수로서 존재하지 않을 것이다. 따라서 operator<<(cout, ob)를 찾는다. 
ostream& operator<<(ostream& o, OL& out) 를 찾고, cout에는 o라는 별명, ob객체에는 out이라는 별명을 붙인다.

		o<<out.data;						cout<<ob.data;	
		return o;						->	return cout;
위와같은 내용으로 실행하게 된다.
실행 후 리턴을 하는데, ostream클래스 임시변수를 만들고 거기에 cout을 복사시킬 필요는 없으므로 ostream& 형태로 반환하게 해서 cout에 임시변수 별칭을 하나 더 붙이고 그냥
그대로 반환 후 끝낸다. (cin과 동일)
*/