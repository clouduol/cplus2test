#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> v(2,1);
	vector<int>* p=&v;
	cout<<"initial p:"<<hex<<p<<dec<<endl;
	for(vector<int>::iterator iter=p->begin();iter!=p->end();iter++){
		cout<<(*iter)<<"\t";
	}
	cout<<endl;
	for(int i=0;i<100;i++){
		v.push_back(i);
	}
	cout<<"second p:"<<hex<<p<<dec<<endl;
	for(vector<int>::iterator iter=p->begin();iter!=p->end();iter++){
		cout<<(*iter)<<"\t";
	}
	cout<<endl;
	//p[2]=3;
}
