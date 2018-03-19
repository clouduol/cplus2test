#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

class Solution {
    struct From{
        int u;
        int d;
        int r;
        int l;
        From(){
            u=d=r=l=0;
        }
    };
public:
    vector<int> hitBricks(vector<vector<int> >& grid, vector<vector<int> >& hits) {
        From from[201][201];
        bool labeled[201][201];
        queue<pair<int,int> > prop;
        int gm=grid.size();
        int gn=grid[0].size();
        for(int j=0;j<gn;j++){
            if(!grid[0][j])
                continue;
            if(gm<=1 || !grid[1][j]){
                continue;
            }
            from[1][j].u++;
            pair<int,int> p(1,j);
            prop.push(p);
            memset(labeled, 0, sizeof(labeled));
            while(!prop.empty()){
                p=prop.front();
                prop.pop();
                labeled[p.first][p.second]=true;
                // propagate to adjacent position
                // first, bfs, the same level, position independent
                // second, one top position, cann't back flood; but may flood diffenrent directions between two top positions
                // to up
                if(p.first-1>=1 && !labeled[p.first-1][p.second] && grid[p.first-1][p.second]){
                    from[p.first-1][p.second].d++;
                    pair<int,int> p2(p.first-1,p.second);
                    prop.push(p2);
                }
                // to left
                if(p.second-1>=0 && !labeled[p.first][p.second-1] && grid[p.first][p.second-1]){
                    from[p.first][p.second-1].r++;
                    pair<int,int> p2(p.first,p.second-1);
                    prop.push(p2);
                }
                // to down
                if(p.first+1<gm && !labeled[p.first+1][p.second] && grid[p.first+1][p.second]){
                    from[p.first+1][p.second].u++;
                    pair<int,int> p2(p.first+1,p.second);
                    prop.push(p2);
                }
                // to right
                if(p.second+1<gn && !labeled[p.first][p.second+1] && grid[p.first][p.second+1]){
                    from[p.first][p.second+1].l++;
                    pair<int,int> p2(p.first,p.second+1);
                    prop.push(p2);
                }
            }
        }

		//for(int i=0;i<gm;i++){
		//	for(int j=0;j<gn;j++)
		//		cout<<from[i][j].u<<from[i][j].l<<from[i][j].d<<from[i][j].r<<"\t";
		//	cout<<endl;
		//}
        
        // hit
        vector<int> ret;
        int hm=hits.size();
		//cout<<hm<<endl;
        for(int i=0;i<hm;i++){
			//cout<<i<<endl;
            if(!grid[hits[i][0]][hits[i][1]]){
                ret.push_back(0);
                continue;
            }
            // propagate to adjacent position
			from[hits[i][0]][hits[i][1]].u=0;
			from[hits[i][0]][hits[i][1]].l=0;
			from[hits[i][0]][hits[i][1]].d=0;
			from[hits[i][0]][hits[i][1]].r=0;
            grid[hits[i][0]][hits[i][1]]=0;
            memset(labeled, 0, sizeof(labeled));
            int count=0;
            pair<int, int> p(hits[i][0], hits[i][1]);
            prop.push(p);
			//cout<<hits[i][0]<<hits[i][1]<<endl;
            while(!prop.empty()){
                p=prop.front();
                prop.pop();
				labeled[p.first][p.second]=true;
                // to up
                if(p.first-1>=1 && !labeled[p.first-1][p.second] && from[p.first-1][p.second].d && grid[p.first-1][p.second]){
					if(grid[p.first][p.second])
                    	from[p.first-1][p.second].d--;
					else
                    	from[p.first-1][p.second].d=0;
                    if(from[p.first-1][p.second].u==0 && from[p.first-1][p.second].l==0 &&from[p.first-1][p.second].d==0 &&from[p.first-1][p.second].r==0){
                        count++;
                        grid[p.first-1][p.second]=0;
                    }
                    pair<int,int> p2(p.first-1,p.second);
                    prop.push(p2);
                }
                // to left
                if(p.second-1>=0 && p.first!=0 && !labeled[p.first][p.second-1] && from[p.first][p.second-1].r && grid[p.first][p.second-1]){
					if(grid[p.first][p.second])
                    	from[p.first][p.second-1].r--;
					else
                    	from[p.first][p.second-1].r=0;
                    if(from[p.first][p.second-1].u==0 && from[p.first][p.second-1].l==0 &&from[p.first][p.second-1].d==0 &&from[p.first][p.second-1].r==0){
                        count++;
                        grid[p.first][p.second-1]=0;
                    }
                    pair<int,int> p2(p.first,p.second-1);
                    prop.push(p2);
                }
                // to down
                if(p.first+1<gm && !labeled[p.first+1][p.second] && from[p.first+1][p.second].u && grid[p.first+1][p.second]){
					if(grid[p.first][p.second])
                    	from[p.first+1][p.second].u--;
					else
                    	from[p.first+1][p.second].u=0;
                    if(from[p.first+1][p.second].u==0 && from[p.first+1][p.second].l==0 &&from[p.first+1][p.second].d==0 &&from[p.first+1][p.second].r==0){
                        count++;
                        grid[p.first+1][p.second]=0;
                    }
                    pair<int,int> p2(p.first+1,p.second);
                    prop.push(p2);
                }
                // to right
                if(p.second+1<gn && p.first!=0 && !labeled[p.first][p.second+1] && from[p.first][p.second+1].l && grid[p.first][p.second+1]){
					if(grid[p.first][p.second])
                    	from[p.first][p.second+1].l--;
					else
                    	from[p.first][p.second+1].l=0;
                    if(from[p.first][p.second+1].u==0 && from[p.first][p.second+1].l==0 &&from[p.first][p.second+1].d==0 &&from[p.first][p.second+1].r==0){
                        count++;
                        grid[p.first][p.second+1]=0;
                    }
                    pair<int,int> p2(p.first,p.second+1);
                    prop.push(p2);
                }
            }
            ret.push_back(count);
			//for(int k=0;k<gm;k++){
			//	for(int m=0;m<gn;m++)
			//		cout<<from[k][m].u<<from[k][m].l<<from[k][m].d<<from[k][m].r<<"\t";
			//	cout<<endl;
			//}
        }
        
        return ret;
    }
};

int main() {
	vector<vector<int> > grid;
	vector<int> ingrid;
	ingrid.push_back(1);
	ingrid.push_back(0);
	ingrid.push_back(1);
	grid.push_back(ingrid);
	ingrid.clear();
	ingrid.push_back(1);
	ingrid.push_back(1);
	ingrid.push_back(1);
	grid.push_back(ingrid);

	vector<vector<int> > hits;
	vector<int> inhits;
	inhits.push_back(0);
	inhits.push_back(0);
	hits.push_back(inhits);
	inhits.clear();
	inhits.push_back(0);
	inhits.push_back(2);
	hits.push_back(inhits);
	inhits.clear();
	inhits.push_back(1);
	inhits.push_back(1);
	hits.push_back(inhits);

	for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid[i].size();j++)
			cout<<grid[i][j]<<"\t";
		cout<<endl;
	}
	for(int i=0;i<hits.size();i++){
		for(int j=0;j<hits[i].size();j++)
			cout<<hits[i][j]<<"\t";
		cout<<endl;
	}

	Solution solution;
	vector<int> ret=solution.hitBricks(grid, hits);
	for(int i=0;i<ret.size();i++)
		cout<<ret[i]<<"\t";
	cout<<endl;

	cout<<"------------"<<endl;
	grid.clear();
	ingrid.clear();
	ingrid.push_back(1);
	grid.push_back(ingrid);
	grid.push_back(ingrid);
	grid.push_back(ingrid);
	grid.push_back(ingrid);
	grid.push_back(ingrid);

	hits.clear();
	inhits.clear();
	inhits.push_back(3);
	inhits.push_back(0);
	hits.push_back(inhits);
	inhits.clear();
	inhits.push_back(4);
	inhits.push_back(0);
	hits.push_back(inhits);
	inhits.clear();
	inhits.push_back(1);
	inhits.push_back(0);
	hits.push_back(inhits);
	inhits.clear();
	inhits.push_back(2);
	inhits.push_back(0);
	hits.push_back(inhits);
	inhits.clear();
	inhits.push_back(0);
	inhits.push_back(0);
	hits.push_back(inhits);
	for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid[i].size();j++)
			cout<<grid[i][j]<<"\t";
		cout<<endl;
	}
	for(int i=0;i<hits.size();i++){
		for(int j=0;j<hits[i].size();j++)
			cout<<hits[i][j]<<"\t";
		cout<<endl;
	}

	ret=solution.hitBricks(grid, hits);
	for(int i=0;i<ret.size();i++)
		cout<<ret[i]<<"\t";
	cout<<endl;

	cout<<"------------"<<endl;
	grid.clear();
	ingrid.clear();
	ingrid.push_back(0);
	ingrid.push_back(1);
	ingrid.push_back(1);
	ingrid.push_back(1);
	ingrid.push_back(1);
	grid.push_back(ingrid);
	ingrid.clear();
	ingrid.push_back(1);
	ingrid.push_back(1);
	ingrid.push_back(1);
	ingrid.push_back(1);
	ingrid.push_back(0);
	grid.push_back(ingrid);
	grid.push_back(ingrid);
	ingrid.clear();
	ingrid.push_back(0);
	ingrid.push_back(0);
	ingrid.push_back(1);
	ingrid.push_back(1);
	ingrid.push_back(0);
	grid.push_back(ingrid);
	ingrid.clear();
	ingrid.push_back(0);
	ingrid.push_back(0);
	ingrid.push_back(1);
	ingrid.push_back(0);
	ingrid.push_back(0);
	grid.push_back(ingrid);
	grid.push_back(ingrid);
	ingrid.clear();
	ingrid.push_back(0);
	ingrid.push_back(0);
	ingrid.push_back(0);
	ingrid.push_back(0);
	ingrid.push_back(0);
	grid.push_back(ingrid);
	grid.push_back(ingrid);
	grid.push_back(ingrid);

	hits.clear();
	inhits.clear();
	inhits.push_back(6);
	inhits.push_back(0);
	hits.push_back(inhits);
	inhits.clear();
	inhits.push_back(1);
	inhits.push_back(0);
	hits.push_back(inhits);
	inhits.clear();
	inhits.push_back(4);
	inhits.push_back(3);
	hits.push_back(inhits);
	inhits.clear();
	inhits.push_back(1);
	inhits.push_back(2);
	hits.push_back(inhits);
	inhits.clear();
	inhits.push_back(7);
	inhits.push_back(1);
	hits.push_back(inhits);
	inhits.clear();
	inhits.push_back(6);
	inhits.push_back(3);
	hits.push_back(inhits);
	inhits.clear();
	inhits.push_back(5);
	inhits.push_back(2);
	hits.push_back(inhits);
	inhits.clear();
	inhits.push_back(5);
	inhits.push_back(1);
	hits.push_back(inhits);
	inhits.clear();
	inhits.push_back(2);
	inhits.push_back(4);
	hits.push_back(inhits);
	inhits.clear();
	inhits.push_back(4);
	inhits.push_back(4);
	hits.push_back(inhits);
	inhits.clear();
	inhits.push_back(7);
	inhits.push_back(3);
	hits.push_back(inhits);
	for(int i=0;i<grid.size();i++){
		for(int j=0;j<grid[i].size();j++)
			cout<<grid[i][j]<<"\t";
		cout<<endl;
	}
	for(int i=0;i<hits.size();i++){
		for(int j=0;j<hits[i].size();j++)
			cout<<hits[i][j]<<"\t";
		cout<<endl;
	}

	ret=solution.hitBricks(grid, hits);
	for(int i=0;i<ret.size();i++)
		cout<<ret[i]<<"\t";
	cout<<endl;
}
