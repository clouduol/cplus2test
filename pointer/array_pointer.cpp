#include<iostream>
#include <typeinfo>
using namespace std;

int main() {
	int a[][3]={1,2,3,4,5,6};
	int (*b)[3];
	cout<<typeid(a).name()<<endl;
	cout<<sizeof(a)<<endl;
	cout<<typeid(a[0]).name()<<endl;
	cout<<sizeof(a[0])<<endl;
	cout<<typeid(b).name()<<endl;
	cout<<sizeof(b)<<endl;
	cout<<&a<<"\t"<<&a[1]<<endl;
	b=&a[0];
	cout<<b<<endl;
	cout<<(*b)[0]<<endl;
	b++;
	cout<<b<<endl;
	cout<<(*b)[0]<<endl;
}
