#include<iostream>

using namespace std;

int main() {
	bool a[3][3];
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout<<a[i][j]<<"\t";
		cout<<endl;
	}
	bool b[3][3]={true};
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++)
			cout<<b[i][j]<<"\t";
		cout<<endl;
	}
}
