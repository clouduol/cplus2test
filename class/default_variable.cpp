#include <iostream>
using namespace std;

class Test{
	int a=1;
	string str="hello";
public:
	Test(int a, string str):a(a),str(str) {
		cout<<this->a<<endl;
		cout<<this->str<<endl;
	}
	Test(){
		cout<<this->a<<endl;
		cout<<this->str<<endl;
	}
	~Test(){}
};

int main() {
	Test t;
	Test t2(3,"world");
}
