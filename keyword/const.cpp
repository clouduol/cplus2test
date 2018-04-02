#include <iostream>
#include <typeinfo>
using namespace std;

const double PI=3.14;
//const int U;

void print(const int& a){
	//a=5;
	cout<<a<<endl;
}

void print(const int* a){
	//*a=5;
	a++;
	a--;
	cout<<*a<<endl;
}

class A {
public:
	const int b;
	int a;
	A(int b):b(b){}
	//A(int b){this->b=b;}
	void seta(int a) { this->a=a;}
	int geta() { return a;}
	void setac(int a) const {}
	int getac() const{ return a;}
};

int main() {
	// const variable
	cout<<typeid(PI).name()<<endl;
	cout<<sizeof(PI)<<endl;
	cout<<&PI<<endl;

	if(1){
		const int embed=1;
		cout<<embed<<endl;
	}
	//cout<<embed<<endl;
	double pi=PI;
	cout<<&pi<<endl;
	double* d=(double*)&PI;
	//*d=3.14159;
	cout<<*d<<"\t"<<PI<<endl;
	/** interesting */
	const int CIF=100;
	int* i=(int*)&CIF;
	cout<<i<<"\t"<<&CIF<<endl;
	cout<<*i<<"\t"<<CIF<<endl;
	*i=1000;
	cout<<i<<"\t"<<&CIF<<endl;
	cout<<*i<<"\t"<<CIF<<endl;

	// const pointer & pointer const variable
	int base[]={10,11};
	const int * p1=base;
	//int const * p1=base;
	cout<<*p1<<endl;
	//*p1=20;
	p1++;
	cout<<*p1<<endl;
	int* const p2=base;
	*p2=20;	
	cout<<*p2<<endl;
	//p2++;
	cout<<*(p1-1)<<endl;
	//int* p3=p1;
	int* p3=const_cast<int*>(p1);
	cout<<*p3<<endl;
	p1=p3-1;
	cout<<*p1<<endl;

	// const function parameter
	int a=56;
	print(a);
	print(&a);

	A oa(100);
	oa.seta(3);
	cout<<oa.geta()<<endl;
	oa.setac(5);
	cout<<oa.getac()<<endl;

	const A ob=oa;
	//ob.seta(30);
	//cout<<ob.geta()<<endl;
	ob.setac(50);
	cout<<ob.getac()<<endl;
}
