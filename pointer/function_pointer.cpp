#include <iostream>
using namespace std;

typedef int (*tfp) (int, int);

int add(int a, int b){
	return a+b;
}

int multiply(int a, int b){
	return a*b;
}

int subtract(int a, int b) {
	return a-b;
}

int divide(int a, int b) {
	return a/b;
}

int (*arithmetic(int type)) (int, int) {
	switch (type) {
		case 0: return add;
		case 1: return subtract;
		case 2: return multiply;
		case 3: return divide;
		default:
			return NULL;
	}
}

void print(int a){
	cout<<a<<endl;
}

void print(int (*f) (int, int),int a, int b){
	cout<<f(a,b)<<endl;
}

int main() {
	int a=3,b=5;
	cout<<"a:"<<a<<"\t"<<"b:"<<b<<endl;
	int (*f) (int,int) = nullptr;
	f=add;
	print(f(a,b));
	print((*f)(a,b));
	print(f,a,b);
	print(*f,a,b);

	f=&multiply;
	print(f(a,b));
	print((*f)(a,b));
	print(f,a,b);
	print(*f,a,b);

	print(arithmetic(0), a, b);
	print(arithmetic(1), a, b);
	print(arithmetic(2), a, b);
	print(arithmetic(3), a, b);

	int (*fa[4]) (int, int) = {&add, &subtract, &multiply, &divide};
	for(int i=0; i<4; i++){
		print(fa[i], a, b);
	}

	tfp fp=&multiply;
	print(fp, a, b);
}
