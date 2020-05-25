#include <iostream>
#include <iomanip>
using namespace std;

class Student{
private:
	const int no;
	char name[20];
	int age;
public:
	Student(int n, char* pn, int a);
	void show() const;
	void linePrint() const;
};
Student::Student(int n, char* pn, int a):no(n){
	strcpy(name, pn);
	age = a;
}
void Student::show() const{
	cout<<no<<" "<<name<<" "<<age<<endl;
	linePrint();
}
void Student::linePrint() const{
	for(int i=0; i<=20; i++){
		cout<<"-";
	}
	cout<<endl;
}
void ex1(){
	Student s(2016001, "ȫ�浿", 25);
	s.show();
}

void main(){
	ex1();
}