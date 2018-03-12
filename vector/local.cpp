#include<iostream>
#include<vector>

using namespace std;

vector<int>& local(int tail){
	vector<int> ret;
	ret.push_back(tail);
	return ret;
}

void local2(vector<int>& ret){
	vector<int> tmp;
	tmp.push_back(100);
	ret=tmp;
}

int main(){
	vector<int> ret = local(3);
	for(int i=0;i<ret.size();i++){
		cout<<ret[i]<<"\t";
	}
	cout<<endl;

	vector<int> ret2;
	local2(ret2);
	for(int i=0;i<ret2.size();i++){
		cout<<ret2[i]<<"\t";
	}
	cout<<endl;
}
