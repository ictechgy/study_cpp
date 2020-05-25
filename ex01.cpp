#include <iostream>  //입출력관련 헤더파일. cin과 cout존재
#include <iomanip>  //input ouput manipulate 입출력형식 조작 헤더파일
using namespace std;

void ex1(){
	int a, b;
	a = 5;
	b = 7;
	printf("a = %5d, b = %5d\n",a,b);

	printf("정수 2개 입력 : ");
	scanf("%d%d", &a, &b);  //입력을 받을 때에는 주소값이 필요. 변수명자체가 주소를 나타내는 경우 &는 필요 없음(배열변수명, 포인터 등)
	printf("a = %d, b = %d\n",a,b);
}

void ex2(){
	int a, b;
	a = 5;
	b = 7;
	cout<<"a = "<<setw(5)<<a<<", b = "<<setw(5)<<b<<endl;  //end line의 준말
	//출력형식제어문자인 %5d와 같이 setwidth()함수를 이용해서 출력형식을 제어할 수 있다. 5자리 확보 후 그 안에 a를 출력한다

	cout<<"정수 2개 입력 : ";
	cin>>a>>b;  //주소값이 필요없네? - cin의 장점
	cout<<"a = "<<a<<", b = "<<b<<endl;
}

void ex3()
{
	char str[20] = "ABCD"; //char형 배열 맨 마지막에는 끝을 나타내는 \0이 있었지??
	cout<<str<<endl;

	cout<<"문자열 입력 : ";
	cin>>str;  //scanf("%s", str);
	cout<<str<<endl;
	//"홍길동"이라고 입력하면 값이 모두 제대로 str에 들어가게 된다. 하지만 "홍 길 동"이라고 입력하면 "홍" 하나만 str에 들어가게 되고
	//버퍼에는 값 구분으로서 쓴 공백을 지운채 "길 동"이라는 글자만 남게 된다.

	cout<<"문자열 입력 :";
	cin.get(str,20); //str의 크기보다 크게 입력가능하게 만들고 그렇게 입력할경우 문제 발생
	cout<<str<<endl;
	//이제는 "홍 길 동" 이렇게 입력해도 모두 잘 들어가게 된다. 다만 버퍼에는 개행인자가 남게 된다.

	fflush(stdin);

	cout<<"문자열 입력 :";
	cin.get(str,20); //fflush(stdin)이 없을경우 씹히게 된다. 버퍼에 있는 개행인자는 사라지면서 씹히는건지 아니면 계속 버퍼에는 개행인자가 남아있는건지
	cout<<str<<endl;

	//만약 버퍼에 개행인자가 남아있는 상태에서 그냥 cin을 써서 a라는 변수에 값을 받도록 두면 아무값도 들어가지는 않겠지만 개행인자는 사라지지 않을까
}

void main(){
	ex1();
	ex2();
	ex3();
}