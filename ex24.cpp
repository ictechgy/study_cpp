#include <iostream>
#include <iomanip>
using namespace std;

class Base_class{	//부모클래스
private:
	int b, c;
protected:
	int d;
public:
	void set_b(int B){
		b = B;
	}
	void set_c(int C){
		c = C;
	}
	int get_b(){
		return b;
	}
	int get_c(){
		return c;
	}
};
class Der_class : public Base_class {	//자식클래스
private:
	int a;
public:
	void set_a(int A){
		a = A;
	}
	int get_a(){
		return a;
	}
	//자식클래스가 부모클래스를 상속받았다고 하더라도 부모클래스의 private멤버는 이곳(자식클래스)에서 접근할 수 없다.
};
void ex1(){
	Der_class ob;
	ob.set_a(10);
	ob.set_b(20);
	ob.set_c(30);
	cout<<ob.get_a()<<endl;
	cout<<ob.get_b()<<endl;
	cout<<ob.get_c()<<endl;
}


class Score{
protected:
	int kor, eng, mat, tot;
	double avg;
public:
	void set_kor(){
		cout<<"KOR : ";
		cin>>kor;
	}
	void set_eng(){
		cout<<"ENG : ";
		cin>>eng;
	}
	void set_mat(){
		cout<<"MAT : ";
		cin>>mat;
	}
	int get_tot(){
		tot = kor + eng + mat;
		return tot;
	}
	double get_avg(){
		avg=tot/3.0;
		return avg;
	}
};
class Score2 : public Score{
private:
	int com, mus;
public:
	void set_com(){
		cout<<"COM : ";
		cin>>com;
	}
	void set_mus(){
		cout<<"MUS : ";
		cin>>mus;
	}
	int get_tot(){
		tot = kor + eng + mat + com + mus;
		//tot = Score::get_tot() + com + mus;
		return tot;
	}
	double get_avg(){
		avg=tot/5.0;
		return avg;
	}
};
void ex2(){
	Score2 sung;
	sung.set_kor();
	sung.set_eng();
	sung.set_mat();
	sung.set_com();
	sung.set_mus();
	cout<<"TOT : "<<sung.get_tot()<<endl;
	cout<<"AVG : "<<sung.get_avg()<<endl;
}

void main(){
	ex1();
	ex2();
}
