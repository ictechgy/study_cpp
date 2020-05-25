#include <iostream>
#include <iomanip>
using namespace std;

int plus(int a, int b){
	return a+b;
}

double plus(int a, double b){
	return a+b;
}

double plus(double a, int b){
	return a+b;
}

double plus(double a, double b){
	return a+b;
}

void main(){
	int c, d;
	cout<<"정수 두개 입력 : ";
	cin>>c>>d;

	cout<<plus(c,d)<<endl;
	
	cout<<plus(10, 25.75) <<endl;
	cout<<plus(10.75, 25) <<endl;
	cout<<plus(10.75, 25.75) <<endl;
}