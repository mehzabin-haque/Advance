#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
int n,m;

bool dfs(int row, int col, vector<vector<int>> &grid,vector<vector<int>> &dp,vector<vector<int>> &vis){

    if(row == n-1 && col==0){
        return true;
    }
    
    if(dp[row][col] !=-1){
        return true;
    }

    vis[row][col]=1;

    int temp = INT_MAX;

    //left
    for(int i=col-1;i>=0;i--){
        if(grid[row][i]==0){
            break;
        }

        if(vis[row][i]==0 && dfs(row,i,grid,dp,vis)){
            temp = min(temp,dp[row][i]);
        }
    }
    //right
    for(int i=col+1;i<m;i++){
         if(grid[row][i]==0){
            break;
        }
        if(vis[row][i]==0 && dfs(row,i,grid,dp,vis)){
            temp = min(temp,dp[row][i]);
        }
    }
    //up

     for(int i=row-1;i>=0;i--){
        if(grid[i][col]==0){
            continue;;
        }

        if(vis[i][col]==0 && dfs(i,col,grid,dp,vis)){
            temp = min(temp,max(abs(row-i),dp[i][col]));
        }

        if(dp[i][col]!=INT_MAX && dp[i][col]!=-1){
            temp = min(temp,max(abs(row-i),dp[i][col]));
        }
    }
    //down

    for(int i=row+1;i<n;i++){
        if(grid[i][col]==0){
            continue;
        }

        if(vis[i][col]==0 && dfs(i,col,grid,dp,vis)){
            temp = min(temp,max(abs(row-i),dp[i][col]));
        }

        if(dp[i][col]!=INT_MAX && dp[i][col]!=-1){
            temp = min(temp,max(abs(row-i),dp[i][col]));
        }
    }

    dp[row][col]=temp;
    return temp != INT_MAX;
}

int main(){

    cin>>n>>m;

    vector<vector<int>> grid(n,vector<int>(m));
    vector<vector<int>> dp(n,vector<int>(m,-1));
    vector<vector<int>> vis(n,vector<int>(m,0));
    int x,y;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            cin>>grid[i][j];
            if(grid[i][j] == 3){
                x=i;
                y=j;
            }
        }
    }

    dp[n-1][0]=0;

    dfs(x,y,grid,dp,vis);

    cout <<dp[x][y]<< endl;

    return 0;
}