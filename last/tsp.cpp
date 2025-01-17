#include<cstdio>
#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int min_tsp(int pos,int mask,vector<vector<int>> &dist,vector<vector<int>> &dp,int n){
    if(mask ==(1<<n)-1){
        return dist[pos][0];
    }

    if(dp[pos][mask]!=-1){
        return dp[pos][mask];
    }

    int minAns = INT_MAX;

    for(int next=0;next<n;next++){
        if((mask & (1<<next))==0){
            int newAns = dist[pos][next]+min_tsp(next,mask|(1<<next),dist,dp,n);
            minAns=min(minAns,newAns);
        }
    }

    dp[pos][mask]=minAns;
    return minAns;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> dist(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>dist[i][j];
            }
        }

        vector<vector<int>> dp(n,vector<int>(1<<n,-1));
        cout<<min_tsp(0,1,dist,dp,n)<<endl;
    }
}