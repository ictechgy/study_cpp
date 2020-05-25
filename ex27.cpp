#include <iostream>
#include <iomanip>
using namespace std;

class Living{
public:
	void Live(){
		cout<<"����ִ�.\n";
	}
	virtual void Breath(){
		cout<<"������\n";
	}
	virtual void Walk(){
		cout<<"�ȱ�\n";
	}
};

class Animal : public Living{
public:
	void Breath(){
		cout<<"��ҷ� ȣ���Ѵ�.\n";
	}
	void Move(){
		cout<<"�����δ�.\n";
	}
};

class Mammalia : public Animal{  //������Ŭ����
public :
	void BringingUp(){
		cout<<"������ ������ �����Ѵ�.\n";
	}
	void Walk(){
		cout<<"�׹߷� �ȴ´�.\n";
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
���� 1. ������ �׸��� ���α׷��� �ۼ��غ���.
	(1) ������ ���̿� ��¹��ڸ� �Է¹޾� ������ �׸��� ���α׷��̴�.
	(2) ��Ӱ� �����Լ��� �̿��Ͽ� �������� �����Ѵ�.

	1. DrawData Ŭ����
	- private �������
		����, ��¹���
	- public ����Լ�
		set_height - ���� ����
		set_outchar - ���� ����
		get_height - ���� ����
		get_outchar - ��¹��� ����
		draw - virtual �Լ�

	2. IsoTriangle Ŭ������ DrawData Ŭ���� ���
	- public ����Լ�
		draw() - ��¹��ڷ� ���� �׸���

	3. Pyramid Ŭ������ DrawData Ŭ���� ���
	- public ����Լ�
		draw() - ��¹��ڷ� ���� �׸���

	4. ��� ���
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
