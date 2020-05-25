#include <iostream>
#include <iomanip>
using namespace std;

class Test{
public:
	Test(){   //Test(Test* this)
		cout<<"object creation"<<this<<endl;
	}
	~Test(){  //Test(Test* this)
		cout<<"object destruction"<<this<<endl;
	}
};

//멤버변수가 존재하지 않는다. 이 클래스를 인스턴스화 하면 최소한의 크기인 1byte의 크기로 클래스변수가 만들어진다.
//각각의 객체를 구분하고 그 각각의 객체들을 this가 가리켜야 하기 때문.
//이 1byte로 만들어진 공간에는 어떤 값도 저장할 수는 없음. 단지 그 변수의 주소를 this가 가리키기만 함

//멤버변수가 존재했다면 멤버변수들이 만들어지고 이 멤버변수들을 통칭해서 클래스변수명으로 묶어놨겠지. 마치 구조체처럼

void ex2(){
	Test A, B, C;
	//A.Test(); => A.Test(&A);
	//B.Test(); => B.Test(&B);
	//C.Test(); => C.Test(&C);
	cout<<sizeof(A)<<endl;
	cout<<"A : "<<&A<<", B : "<<&B<<", C : "<<&C<<endl;

	//C.~Test(); => C.~Test(&C);
	//B.~Test(); => B.~Test(&B);
	//A.~Test(); => A.~Test(&A);
	//소멸자는 반대로 호출된다. 메모리의 구조때문인가? 가장 나중에 만들어진게 메모리상 가장 위에 있을테니 가장 위부터 순차적으로 제거?
}

void main(){
	ex2();
}

//sizeof()나 strlen()의 동작원리에 대하여. 배열, 문자열, 포인터-실질공간 을 인자로 넣었을 때..
//포인터를 인자로 넣으면 포인터에 대해 나올까 포인터가 가리키는 공간에 대해 나올까, 포인터가 가리키는 배열공간 등
//strlen은 원래 주소값을 통해 문자열의 길이를 반환하니까 포인터변수를 인자로 넣어도 실질적 공간의 값을 반환할 것 같은데(문자열의 경우)