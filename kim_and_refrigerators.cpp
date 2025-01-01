#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int min_dist(vector<pair<int,int>> &coord, int n){

    int dist=0;

    vector<vector<int>> graph(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            graph[i][j] = abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second);
            graph[j][i] = graph[i][j];
        }
    }

    return dist;
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        n+=2;
        vector<pair<int,int>> coord(n);
        int x,y;
        cin>>x,y;
        coord[0] = {x,y};
        int a,b;
        cin>>a>>b;
        coord[n-1]={a,b};

        for(int i=1;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            coord[i] = {x,y};
        }

        cout<< min_dist(coord,n) << endl;

    }
}