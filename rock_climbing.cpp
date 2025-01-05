#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int n,m; // n=row, m=col
typedef long long ll;

bool dfs(int r,int c, vector<vector<int>> &dp, vector<vector<int>> &vis, vector<vector<int>> &g){
    if(r==n-1 && c==0){
        return true;
    }
    
    if(dp[r][c]!=-1){
        return true;
    }
    
    int temp= INT_MAX;
    vis[r][c]=1;
    
    //left
    for(int i=c-1;i>=0;i--){
        if(g[r][i]==0){
            break;
        }
        if(vis[r][i]==0 && dfs(r,i,dp,vis,g)){
            temp = min(temp,dp[r][i]);
        }
    }
    
    //right
    for(int i=c+1;i<m;i++){
        if(g[r][i]==0){
            break;
        }
        if(vis[r][i]==0 && dfs(r,i,dp,vis,g)){
            temp = min(temp,dp[r][i]);
        }
    }
    
    //upward
    for(int i=r-1;i>=0;i--){
        if(g[i][c]==0){
            continue;
        }
        if(vis[i][c]==0 && dfs(i,c,dp,vis,g)){
            temp = min(temp,max(dp[i][c],abs(r-i)));
        }
        
        else if(dp[i][c] != INT_MAX && dp[i][c]!=-1){
            temp = min(temp,max(dp[i][c],abs(r-i)));
        }
    }
    
    //downward
    for(int i=r+1;i<n;i++){
        if(g[i][c]==0){
            continue;
        }
        if(vis[i][c]==0 && dfs(i,c,dp,vis,g)){
            temp = min(temp,max(dp[i][c],abs(r-i)));
        }
        
        else if(dp[i][c] != INT_MAX && dp[i][c]!=-1){
            temp = min(temp,max(dp[i][c],abs(r-i)));
        }
    }
    
    dp[r][c]=temp;
    return temp!=INT_MAX;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    cin>>n>>m;
    
    vector<vector<int>> g(n,vector<int>(m));
    vector<vector<int>> vis(n,vector<int>(m,0));
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int x=-1,y=-1;
    
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
    dfs(x,y,dp,vis,g);
    cout<<dp[x][y]<<endl;
    
    return 0;
}
