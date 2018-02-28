#include<iostream>
#include<vector>

using namespace std;

int main() {
	vector<int> v(5,1);
	vector<int> c=v;
	c[2]=3;
	cout<<"initial v:\n";
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<"\t";
	}
	cout<<endl;
	cout<<"copy v:\n";
	for(int i=0;i<c.size();i++){
		cout<<c[i]<<"\t";
	}
	cout<<endl;
}
