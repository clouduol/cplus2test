#include<iostream>
using namespace std;

static int base=10;

void f(int a, int b=base+1, int c=3){
	cout<<a<<"\t"<<b<<"\t"<<c<<endl;
}

int main() {
	f(1,2,5);
	f(2,3);
	f(6);
}
