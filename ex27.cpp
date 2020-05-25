#include <iostream>
#include <iomanip>
using namespace std;

class Living{
public:
	void Live(){
		cout<<"살아있다.\n";
	}
	virtual void Breath(){
		cout<<"숨쉬기\n";
	}
	virtual void Walk(){
		cout<<"걷기\n";
	}
};

class Animal : public Living{
public:
	void Breath(){
		cout<<"산소로 호흡한다.\n";
	}
	void Move(){
		cout<<"움직인다.\n";
	}
};

class Mammalia : public Animal{  //포유류클래스
public :
	void BringingUp(){
		cout<<"젖으로 새끼를 양육한다.\n";
	}
	void Walk(){
		cout<<"네발로 걷는다.\n";
	}
};

void ex1(){
	Living* p1 = new Living;
	Living* p2 = new Animal;
	Living* p3 = new Mammalia;

	p1->Live();
	p2->Live();
	p3->Live();

	p2->Breath();
	p3->Walk();
}

/*
문제 1. 도형을 그리는 프로그램을 작성해보자.
	(1) 도형의 높이와 출력문자를 입력받아 도형을 그리는 프로그램이다.
	(2) 상속과 가상함수를 이용하여 다형성을 구현한다.

	1. DrawData 클래스
	- private 멤버변수
		높이, 출력문자
	- public 멤버함수
		set_height - 높이 대입
		set_outchar - 문자 대입
		get_height - 높이 리턴
		get_outchar - 출력문자 리턴
		draw - virtual 함수

	2. IsoTriangle 클래스는 DrawData 클래스 상속
	- public 멤버함수
		draw() - 출력문자로 도형 그리기

	3. Pyramid 클래스는 DrawData 클래스 상속
	- public 멤버함수
		draw() - 출력문자로 도형 그리기

	4. 출력 결과
	x
	xx
	xxx
	xxxx
	xxxxx
	xxxxxx
	xxxxxxx
	xxxxxxxx
	xxxxxxxxx
	xxxxxxxxxx
		     #
		    ###
		   #####
	      #######
	     #########
	    ###########
	   #############
	  ###############
	 #################
	###################
*/

class DrawData{
private:
	int height;
	char outchar;
public:
	void set_height(int h){
		height = h;
	}
	void set_outchar(char o){
		outchar = o;
	}
	int get_height(){
		return height;
	}
	char get_outchar(){
		return outchar;
	}
	virtual void draw(){};
};

class IsoTriangle : public DrawData{
	void draw(){
		for(int i=1; i<=get_height(); i++){
			for(int j=1; j<=i; j++){
				cout<<get_outchar();
			}
			cout<<endl;
		}
	}
};

class Pyramid : public DrawData{
	void draw(){
		//cout<<center;
		for(int i=1; i<=get_height(); i++){
			for(int k=1; k<=get_height()-i; k++){
				cout<<" ";
			}
			for(int j=1; j<=2*i-1; j++){
				//cout<<setw(get_height()*2-1)<<get_outchar();
				cout<<get_outchar();
			}
			cout<<endl;
		}
	}
};

void pr1(){
	DrawData* pa;
	pa = new IsoTriangle;
	pa->set_height(10);
	pa->set_outchar('x');
	pa->draw();
	delete pa;

	pa = new Pyramid;
	pa->set_height(10);
	pa->set_outchar('#');
	pa->draw();
	delete pa;
}

void main(){
	ex1();
	pr1();
}
