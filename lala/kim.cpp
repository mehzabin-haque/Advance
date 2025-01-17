#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int manhattan_dis(pair<int,int> A, pair<int,int> B){
    return abs(A.first-B.first)+abs(A.second-B.second);
}

int tsp(int pos, int mask, vector<vector<int>> &dist, vector<vector<int>> &dp){

    int n = dist.size();

    if(mask == (1<<n)-1){
        return dist[pos][n-1];
    }

    if(dp[pos][mask] !=-1){
        return dp[pos][mask];
    }

    int minAns = INT_MAX;

    for(int next=1;next<n;next++){
        if((mask & (1<<next))==0){
            int newAns = dist[pos][next] + tsp(next,mask | (1<<next), dist,dp);
            minAns = min(minAns, newAns);
        }
    }

    dp[pos][mask] = minAns;
    return dp[pos][mask];
}

int min_travel( const vector<pair<int,int>> &coordinates, int n){
    vector<vector<int>> graph(n,vector<int>(n,0));
    vector<vector<int>> dp(n,vector<int>(1<<n,-1));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int dist = manhattan_dis(coordinates[i],coordinates[j]);
            graph[i][j]=dist;
            graph[j][i]=dist;
        }
    }

    int result = tsp(0,1,graph,dp);

    return result;
}

int main(){

    for(int i=1;i<=10;i++){

        int n;
        cin>>n;
        int x,y;
        vector<pair<int,int>> coordinates(n+2);
        cin>>x>>y;
        coordinates[0]={x,y};
        cin>>x>>y;
        coordinates[n+1]={x,y};

        for(int i=1;i<=n;i++){
            cin>>x>>y;
            coordinates[i]={x,y};
        }

        int ans = min_travel(coordinates,n+2);

        cout << "# " << i << " " << ans << endl;
    }
    return 0;
}
