#include<cstdio>
#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<queue>
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
    {-1,0,-1,0},
};

void dfs(int h,int w,int r, int c, int l, int &ans,vector<vector<int>> &g,vector<vector<int>> &vis,vector<vector<int>> &dfsvisited){
    if(r<0 || r>=h || c<0 || c>=w || l<=0 || g[r][c]==0 || dfsvisited[r][c]==1){
        return;
    }

    if(!vis[r][c]){
        ans++;
    }

    vis[r][c]=1;
    dfsvisited[r][c]=1;

    int left = dir[g[r][c]][0];
    int right = dir[g[r][c]][1];
    int up = dir[g[r][c]][2];
    int down = dir[g[r][c]][3];

    //left
    if(c+left>=0 && c+left<w && dir[g[r][c]][0]==-1 && dir[g[r][c+left]][1]==1){
        dfs(h,w,r,c+left,l-1,ans,g,vis,dfsvisited);
    }
    //right
    if(c+right>=0 && c+right<w && dir[g[r][c]][1]==1 && dir[g[r][c+right]][0]==-1){
        dfs(h,w,r,c+right,l-1,ans,g,vis,dfsvisited);
    }
    //up
    if(r+up>=0 && r+up<h && dir[g[r][c]][2]==-1 && dir[g[r+up][c]][3]==1){
        dfs(h,w,r+up,c,l-1,ans,g,vis,dfsvisited);
    }
    //down
    if(r+down>=0 && r+down<h && dir[g[r][c]][3]==1 && dir[g[r+down][c]][2]==-1){
        dfs(h,w,r+down,c,l-1,ans,g,vis,dfsvisited);
    }

    dfsvisited[r][c]=0;
}

int main(){

    int t;
    cin>>t;
    while(t--){
        int h,w,r,c,l,ans=0;
        cin>>h>>w>>r>>c>>l;

        vector<vector<int>> g(h,vector<int>(w));
        vector<vector<int>> visited(h,vector<int>(w,0));
        vector<vector<int>> dfsvisited(h,vector<int>(w,0));

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>g[i][j];
            }
        }

        dfs(h,w,r,c,l,ans,g,visited,dfsvisited);
        cout<<ans<<endl;

    }
}