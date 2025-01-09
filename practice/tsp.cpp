#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int tsp(int pos,int mask, vector<vector<int>> &dis, vector<vector<int>> &dp,int n ){

    if(dp[pos][mask]!= -1){
       return dp[pos][mask];
    }

    if(mask == (1<<n)-1){
        return dis[pos][0];
    }

    int ans = INT_MAX;

    // you messed up here. remember that inside for loop everything is related to next
    for(int next=0;next<n;next++){
        if((mask & (1<<next))==0){
            int newAns = dis[pos][next]+tsp(next,mask|(1<<next),dis,dp,n);
            ans = min(ans,newAns);
        }
    }

    return dp[pos][mask]=ans;
}

int main(){

    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n;
        cin>>n;

        vector<vector<int>> dis(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>dis[i][j];
            }
        }

        vector<vector<int>> dp(n,vector<int>((1<<n),-1));

        cout << tsp(0,1,dis,dp,n)<<endl;
    }
    return 0;
}