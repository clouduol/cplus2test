#include<iostream>
using namespace std;

class A{
public:
	A(int v):val(v){}
	int val;
	virtual void f(){
		cout<<"virtual function class A: "<<val<<endl;
	}
};

class B:public A {
public:
	B(int v):A(0),val(v){}
	int val;
	virtual void f() {
		cout<<"virtual function class B: "<<val<<endl;
	}
	void f2() {
		cout<<"class B, normal function"<<endl;
	}
	virtual void f3() {
		cout<<"class B, own virtual function"<<endl;
	}
};

class C:public A {
public:
	C(int v):A(0),val(v){}
	int val;
};

int main() {
	A a(10);
	a.f();
	B b(11);
	b.f();
	C c(12);
	c.f();

	//A& d=a;
	A d=a;
	d.f();
	d=b;
	d.f();
	d=c;
	d.f();

	A* e=&a;
	e->f();
	e=&b;
	e->f();
	//e->f2();
	//e->f3();
	e=&c;
	e->f();
}

