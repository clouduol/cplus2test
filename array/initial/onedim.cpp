#include<iostream>
#include<typeinfo>

using namespace std;

void printChar(char c[1], int n){
	cout<<typeid(c).name()<<endl;
	for(int i=0;i<n;i++)
		cout<<c[i]<<"\t";
	cout<<endl;
}

void printInt(int c[5], int n) {
	cout<<typeid(c).name()<<endl;
	for(int i=0;i<n;i++)
		cout<<c[i]<<"\t";
	cout<<endl;
}

int main() {
	int a[3] = {1,2,};
	printInt(a, 3);
	//int b[3] = {1,,3};
	int b[] = {1,2,3};
	cout<<sizeof(b)<<endl;
	printInt(b, 3);

	char c[]="hello";
	cout<<sizeof(c)<<endl;
	printChar(c,sizeof(c));
	char d[]={'3','s',0};
	cout<<sizeof(d)<<endl;
	cout<<d<<endl;
	printChar(d,sizeof(d));
	//char e[3]="hello";

	int* p1=new int;
	cout<<*p1<<endl;
	*p1=3;
	cout<<*p1<<endl;
	delete p1;
	int* p2=new int(4);
	cout<<*p2<<endl;
	*p2=5;
	cout<<*p2<<endl;
	delete p2;
	//int* p3=new int[10](1);
	int* p3=new int[10]();
	printInt(p3,10);
	delete []p3;
	int* p4=new int[10];
	printInt(p4,10);
	delete []p4;
}
