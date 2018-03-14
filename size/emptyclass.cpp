#include<iostream>

using namespace std;

class Test{};

class Test2{
public:
	Test2(){};
	~Test2(){};
};

class Test3{
public:
	Test3(){};
	virtual ~Test3(){};
};

int main() {
	Test t1;
	cout<<sizeof(Test)<<endl;
	cout<<sizeof(t1)<<endl;

	Test2 t2;
	cout<<sizeof(Test2)<<endl;
	cout<<sizeof(t2)<<endl;

	Test3 t3;
	cout<<sizeof(Test3)<<endl;
	cout<<sizeof(t3)<<endl;

	Test3* t4=new Test3();
	cout<<sizeof(Test3)<<endl;
	cout<<sizeof(t4)<<endl;

	Test3* t5=new Test3;
	cout<<sizeof(Test3)<<endl;
	cout<<sizeof(t5)<<endl;
}
