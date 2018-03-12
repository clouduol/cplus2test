#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > allPathsSourceTarget(vector<vector<int> >& graph) {
        int n=graph.size();
        vector<vector<int> > res;
        vector<vector<vector<int> > > trace;
        vector<int> thi;
        thi.push_back(-1);
		vector<vector<int> > sec;
		sec.push_back(thi);
        for(int i=0;i<n;i++){
            trace.push_back(sec);
        }

		cout<<"before first dfs"<<endl;
        dfs(graph,0,n-1,res,trace);
        return res;
        
    }
    
    void dfs(vector<vector<int> >& graph, int s, int d, vector<vector<int> >& paths, vector<vector<vector<int> > >& trace){
		cout<<"s:\t"<<s<<"\tt:\t"<<d<<endl;
        for(int i=0;i<graph[s].size();i++){
            if(graph[s][i]==d){
                vector<int> path;
                path.push_back(s);
                path.push_back(d);
                paths.push_back(path);
            }else{
                vector<vector<int> > subpaths;
                if(trace[graph[s][i]].size()!=0 &&  trace[graph[s][i]][0][0]!=-1){
					cout<<"using trace: \t"<<graph[s][i]<<endl;
                    subpaths=trace[graph[s][i]];
                }else{
					cout<<"recursive: \t"<<graph[s][i]<<endl;
                    dfs(graph,graph[s][i],d,subpaths,trace);
                }   
                if(subpaths.size()!=0){
                    for(int j=0;j<subpaths.size();j++){
                        vector<int> path;
                        path.push_back(s);
                        for(int k=0;k<subpaths[j].size();k++){
                            path.push_back(subpaths[j][k]);
                        }
                        paths.push_back(path);
                    }
                }
            }
            
            if(trace[s][0][0]==-1){
                trace[s].erase(trace[s].begin());
            }
            trace[s]=paths;
        }
    }
};


int main(){
	Solution solution;
	vector<vector<int> > graph;
	vector<int> adj;
	adj.push_back(1);
	adj.push_back(2);
	graph.push_back(adj);
	adj.erase(adj.begin());
	adj.erase(adj.begin());
	adj.push_back(3);
	graph.push_back(adj);
	graph.push_back(adj);
	adj.erase(adj.begin());
	graph.push_back(adj);
	for(int i=0;i<graph.size();i++){
		cout<<i<<"\t";
		for(int j=0;j<graph[i].size();j++){
			cout<<graph[i][j]<<"\t";
		}
		cout<<endl;
	}


	vector<vector<int> > res;
	res=solution.allPathsSourceTarget(graph);
	cout<<"result"<<endl;
	for(int i=0;i<res.size();i++){
		cout<<i<<"\t";
		for(int j=0;j<res[i].size();j++){
			cout<<res[i][j]<<"\t";
		}
		cout<<endl;
	}
}
