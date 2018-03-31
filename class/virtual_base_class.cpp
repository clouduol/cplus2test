#include<iostream>
#pragma pack(1)
using namespace std;

class A
{
public:
    int a;
    //int aa;
    //int aaa;
    //int d;
};

class B : virtual public A
{
public:
   int b;
};

class C :virtual public A
{
public:
   int c; 
};

class D : public B, public C
{
public:
   int d;
};

#pragma pack()
int main(){
	cout<<"sizeof void*: "<<sizeof(void*)<<endl;
	cout<<"sizeof A: "<<sizeof(A)<<endl;
	cout<<"sizeof B: "<<sizeof(B)<<endl;
	cout<<"sizeof C: "<<sizeof(C)<<endl;
	cout<<"sizeof D: "<<sizeof(D)<<endl;
}