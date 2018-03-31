#include<iostream>
using namespace std;

class Empty{};
class OneVar{
	int var;
};

int main() {
	cout<<"Empty:"<<sizeof(Empty)<<endl;
	cout<<"OneVar:"<<sizeof(OneVar)<<endl;
}
