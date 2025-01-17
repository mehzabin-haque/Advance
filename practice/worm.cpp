#include<cstdio>
#include<queue>
#include<vector>
#include <climits>
#include<iostream>

using namespace std;

int main(){

    int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        n+=2;

        int sourceX, sourceY, destX, destY, cost;
        cin>>sourceX >> sourceY >> destX >> destY;

        vector<vector<int>> portal;
        portal.push_back({sourceX, sourceY,sourceX, sourceY,0});
        portal.push_back({destX, destY,destX, destY,0});

        for(int i=1; i<n-1;i++){
            int intX, intY, outX, outY;
            cin>>intX>>intY>>outX>>outY>>cost;
            portal.push_back({intX, intY, outX, outY,cost});
            portal.push_back({outX, outY,intX, intY, cost});
        }

        int total_nodes = portal.size();
        vector<pair<int,int>> adj[total_nodes];
        vector<bool> visited(total_nodes, false);
        vector<int> distance(total_nodes, INT_MAX);

        for(int i=0;i<total_nodes;i++){
            for(int j=1;i<total_nodes;j++){
                int w1 = abs(portal[j][0]-portal[i][2])+abs(portal[j][1]-portal[i][3])+portal[j][4];
                int w2 = abs(portal[i][0]-portal[j][2])+abs(portal[i][1]-portal[j][3])+portal[i][4];
                adj[i].push_back({j,w2});
                adj[j].push_back({i,w1});
            }
        }

        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> q;

        q.push({0,0}); //dist, node
        distance[0]=0;

        while(!q.empty()){
            int u = q.top().second;
            q.pop();

            if(visited[u]){
                continue;
            }
            visited[u]=true;

            for(auto it : adj[u]){
                int v = it.first;
                int w = it.second;

                if(distance[u]+w<distance[v]){
                    distance[v] = distance[u]+w;
                    q.push({distance[v],v});
                }
            }
        }

        cout << distance[1] <<endl;

    }

    return 0;
}