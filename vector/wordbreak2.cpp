#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        int n=s.size();
        vector<int>* tr=new vector<int>[n];
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=i;j--){
                vector<string>::iterator iter=find(wordDict.begin(), wordDict.end(),s.substr(i,j-i+1));
                if((i==n || tr[j+1].size()!=0) && iter!=wordDict.end()){
                    tr[i].push_back(j);
                }
            }
        }
	for(int i=0;i<n;i++){
		cout<<i<<"\t";
		for(int j=0;j<tr[i].size();j++)
			cout<<tr[i][j]<<"\t";
		cout<<endl;
	}
        
        recur(tr,n,s,0,res);
        
        return res;
    }
    
    void recur(vector<int> * tr, int n, string s, int k, vector<string>& res){
        for(int i=0; i< tr[k].size(); i++){
            if(tr[k][i]==n-1){
                res.push_back(s.substr(k,n-k));
            }
            else{
                string pre=s.substr(k,tr[k][i]-k+1);
                vector<string> suf;
                recur(tr,n,s,tr[k][i]+1,suf);
                for(int j=0;j<suf.size();j++)
                    res.push_back(pre+" "+suf[j]);
            }
        }
        return;
    }
};

int main() {
	string s="aaaaaaaa";
	vector<string> wordDict;
	wordDict.push_back("aaaa");
	wordDict.push_back("aa");
	wordDict.push_back("a");

	string s2="catsanddog";
	vector<string> wordDict2;
	wordDict2.push_back("cat");
	wordDict2.push_back("cats");
	wordDict2.push_back("and");
	wordDict2.push_back("sand");
	wordDict2.push_back("dog");
	
	
	Solution solution;
	vector<string> result2 = solution.wordBreak(s2,wordDict2);
	for(int i=0;i<result2.size();i++)
		cout<<i<<"\t"<<result2[i]<<endl;
	cout<<endl;	

	vector<string> result = solution.wordBreak(s,wordDict);
	for(int i=0;i<result.size();i++)
		cout<<i<<"\t"<<result[i]<<endl;
	cout<<endl;	
}
