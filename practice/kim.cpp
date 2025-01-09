#include<cstdio>
#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
using namespace std;

int manhattan_dis(pair<int,int> A, pair<int,int> B){
    // i messed up the equation
    return abs(A.first-B.first) + abs(A.second-B.second);
}

int tsp(int pos,int mask, vector<vector<int>> &graph,vector<vector<int>> &dp){
    
    int n= graph.size();
   

    if(mask==(1<<n)-1){
        return graph[pos][n-1];
    }

    if(dp[pos][mask]!=-1){
        return dp[pos][mask];
    }

    int ans=INT_MAX;
    for(int next=1;next<n;next++){
        if((mask & (1<<next))==0){
            //again same mistake
            int newAns = graph[pos][next]+tsp(next,mask | (1<<next), graph,dp);
            ans = min(newAns,ans);
        }
    }

    return dp[pos][mask]=ans;
}

int min_travel(const vector<pair<int,int>> &coordinates, int n){
    vector<vector<int>> graph(n,vector<int>(n,0));
    vector<vector<int>> dp(n,vector<int>(1<<n,-1));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int dis = manhattan_dis(coordinates[i],coordinates[j]);
            graph[i][j]=dis;
            graph[j][i]=dis;
        }
    }

    int result = tsp(0,1,graph,dp);
    return result;
}


int main(){

    for(int i=1;i<=10;i++){
        int n;
        cin>>n;
        // n=n+2;
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

        cout << "# "<<i<< " "<< min_travel(coordinates,n+2) << endl;
    }

    return 0;

}