#include <iostream>
using namespace std;

void print(int a, double b){
	cout<<a<<"\t"<<b<<endl;
}

void print(double a, int b){
	cout<<a<<"\t"<<b<<endl;
}

class A{
public:
	void print(){
		cout<<"non-const function is called"<<endl;
	}

	void print() const {
		cout<<"const function is called"<<endl;
	}
};

//void print(int a, double b, int c=10){
//	cout<<a<<"\t"<<b<<"\t"<<c<<endl;
//}

void print(int a, double b, int c){
	cout<<a<<"\t"<<b<<"\t"<<c<<endl;
}

int main() {
	int a=3;
	double b=5.0;
	print(a,b);
	print(b,a);

	A aa;
	aa.print();
	const A aaa;
	aaa.print();
}
