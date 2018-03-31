#include<iostream>
using namespace std;

class A {
public:
	int a;
	A(int a):a(a) {}
};

class B:public A {
public:
	int b;
	B(int a,int b):A(a),b(b){}
	//B(int a,int b):b(b){ A::A(a)}
};

int main(){
	//A obja;
	A obja(3);
	B objb(4,5);
	cout<<obja.a<<endl;
	cout<<objb.a<<"\t"<<objb.b<<endl;
}