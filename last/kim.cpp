#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;

int manhattan_dist(pair<int,int> A, pair<int,int> B){
    return abs(A.first-B.first)+abs(A.second-B.second);
}

int tsp(int pos, int mask, vector<vector<int>> &graph,vector<vector<int>> &dp){
    int n=graph.size();

    if(mask == (1<<n)-1){
        return graph[pos][n-1];
    }

    if(dp[pos][mask]!=-1){
        return dp[pos][mask];
    }

    int minAns = INT_MAX;

    for(int next=0;next<n;next++){
        if((mask & (1<<next))==0){
            int newAns = graph[pos][next]+tsp(next,mask | (1<<next), graph,dp);
            minAns = min(minAns,newAns);
        }
    }

    dp[pos][mask]=minAns;
    return dp[pos][mask];
}

int min_travel(vector<pair<int,int>> &coordinates, int n){

    vector<vector<int>> graph(n,vector<int>(n,0));
    vector<vector<int>> dp(n,vector<int>((1<<n),-1));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int dist = manhattan_dist(coordinates[i],coordinates[j]);
            graph[i][j]=dist;
            graph[j][i]=dist;
        }
    }

    int res = tsp(0,1,graph,dp);
    return res;

}
int main(){
    for(int i=1;i<=10;i++){
        int n;
        cin>>n;
        vector<pair<int,int>> coordinates(n+2);
        int x,y;
        cin>>x>>y;
        coordinates[0]={x,y};
        cin>>x>>y;
        coordinates[n+1]={x,y};
        for(int i=1;i<=n;i++){
            cin>>x>>y;
            coordinates[i]={x,y};
        }

        cout << "# "<<i<<" "<< min_travel(coordinates,n+2) <<endl;
    }
}