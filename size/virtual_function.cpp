#include<iostream>
using namespace std;

class A{
public:
	virtual void fa(){
		cout<<"virtual function class A: "<<endl;
	}
};

class B {
public:
	virtual void fb() {
		cout<<"virtual function class B: "<<endl;
	}
};

class C:public A {
public:
	virtual void fc() {}
};

class D:public A,public B {
public:
	virtual void fd() {}
};

int main() {
	cout<<"sizeof(A): "<<sizeof(A)<<endl;
	cout<<"sizeof(B): "<<sizeof(B)<<endl;
	cout<<"sizeof(C): "<<sizeof(C)<<endl;
	cout<<"sizeof(D): "<<sizeof(D)<<endl;
}
