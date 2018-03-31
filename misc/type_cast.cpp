#include<iostream>
using namespace std;

int main(){
	int a=5;
	double b=static_cast<double>(a);
	cout<<a<<endl;
	cout<<b<<endl;

	int *c=&a;
	double* d=reinterpret_cast<double*>(c);
	cout<<*c<<endl;
	cout<<*d<<endl;
}
