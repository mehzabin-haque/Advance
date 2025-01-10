#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int n,m;

bool dfs(int r, int c, vector<vector<int>> &g, vector<vector<int>> &vis, vector<vector<int>> &dp){
   if(r==n-1 && c==0){
    return true;
   }

   if(dp[r][c]!=-1){
    return true;
   }

   vis[r][c]=1;
   int temp = INT_MAX;

   //left
   for(int i=c-1;i>=0;i--){
    if(g[r][i]==0){
        break;
    }
    if(vis[r][i]==0 && dfs(r,i,g,vis,dp)){
        temp = min(temp,dp[r][i]);
    }
   }
   //right
   for(int i=c+1;i<m;i++){
    if(g[r][i]==0){
        break;
    }
    if(vis[r][i]==0 && dfs(r,i,g,vis,dp)){
        temp = min(temp,dp[r][i]);
    }
   }
   //up
   for(int i=r-1;i>=0;i--){
    if(g[i][c]==0){
        continue;;
    }
    if(vis[i][c]==0 && dfs(i,c,g,vis,dp)){
        temp = min(temp,max(dp[i][c],abs(r-i)));
    }
    else if(dp[i][c] != INT_MAX && dp[i][c]!=-1){
         temp = min(temp,max(dp[i][c],abs(r-i)));
    }
   }
   //down
   for(int i=r+1;i<n;i++){
    if(g[i][c]==0){
        continue;
    }
    if(vis[i][c]==0 && dfs(i,c,g,vis,dp)){
        temp = min(temp,max(dp[i][c],abs(r-i)));
    }
    else if(dp[i][c] != INT_MAX && dp[i][c]!=-1){
         temp = min(temp,max(dp[i][c],abs(r-i)));
    }
   }
   
   dp[r][c]=temp;
    return temp != INT_MAX;
}

int main(){
    cin>>n>>m;
    int x,y;
    vector<vector<int>> g(n,vector<int>(m));
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> dp(n,vector<int>(m,-1));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]==3){
                x=i;
                y=j;
            }
        }
    }

    dp[n-1][0]=0;
    dfs(x,y,g,vis,dp);
    cout << dp[x][y]<<endl;
    return 0;
}