#include<cstdio>
#include<climits>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// l r u d
const int dir[][4]={
    {0,0,0,0},
    {-1,1,-1,1},
    {0,0,-1,1},
    {-1,1,0,0},
    {0,1,-1,0},
    {0,1,0,1},
    {-1,0,0,1},
    {-1,0,1,0},
};

void dfs(int h,int w,int r,int c, int l, int &ans,vector<vector<int>> &grid,vector<vector<int>> &dfsvisited, vector<vector<int>> &visited){
    if(r<0 || r>=h || c<0 || c>=w || l<=0 || grid[r][c]==0 || dfsvisited[r][c]==1){
        return;
    }

    if(!visited[r][c]){
        ans++;
    }

    dfsvisited[r][c]=1;
    visited[r][c]=1;

    int left = dir[grid[r][c]][0];
    int right = dir[grid[r][c]][1];
    int up = dir[grid[r][c]][2];
    int down = dir[grid[r][c]][3];

    //left
    if(c+left>=0 && c+left<w && dir[grid[r][c]][0]==-1 && dir[grid[r][c+left]][1]==1){
        dfs(h,w,r,c+left,l-1,ans,grid,dfsvisited,visited);
    }

    //right
    if(c+right>=0 && c+right<w && dir[grid[r][c]][1]==1 && dir[grid[r][c+right]][0]==-1){
        dfs(h,w,r,c+right,l-1,ans,grid,dfsvisited,visited);
    }
    //up
    if(r+up>=0 && r+up<h && dir[grid[r][c]][2]==-1 && dir[grid[r+up][c]][3]==1){
        dfs(h,w,r+up,c,l-1,ans,grid,dfsvisited,visited);
    }

    //down
    if(r+down>=0 && r+down<h && dir[grid[r][c]][3]==1 && dir[grid[r+down][c]][2]==-1){
        dfs(h,w,r+down,c,l-1,ans,grid,dfsvisited,visited);
    }


    dfsvisited[r][c]=0;
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int h,w,r,c,l,ans=0;
        cin>>h>>w>>r>>c>>l;

        vector<vector<int>> grid(h,vector<int>(w));
        vector<vector<int>> dfsvisited(h,vector<int>(w,0));
        vector<vector<int>> visited(h,vector<int>(w,0));

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>grid[i][j];
            }
        }

        dfs(h,w,r,c,l,ans,grid,dfsvisited,visited);
        cout<<ans<<endl;

    }
}