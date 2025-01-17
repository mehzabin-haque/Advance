#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void printCycle( vector<int> &parent, int start, int end){
    vector<int> cycle;
    cycle.push_back(end);
    int current = start;

    while(current != end){
        cycle.push_back(current);
        current = parent[current];
    }

    cycle.push_back(end);
    reverse(cycle.begin(),cycle.end());
    for(int node:cycle){
        cout << node << " ";
    }
    cout << endl;
}

bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited,  vector<bool> inStack, vector<int> &parent){
    visited[node]=true;
    inStack[node]=true;

    for(int neighbour : adj[node]){
        if(!visited[neighbour]){
            parent[neighbour]=node;
            if(dfs (neighbour, adj, visited, inStack, parent)){
                return true;
            }
        }

        else if(inStack[neighbour]){
            printCycle(parent,node,neighbour);
            return true;
        }
    }

    inStack[node]=false;
    return false;
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;i++){
        int from,to;
        cin>>from>>to;
        adj[from].push_back(to);
    }

    vector<bool> visited(n+1,false);
    vector<bool> inStack(n+1,false);
    vector<int> parent(n+1,-1);

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(dfs(i,adj,visited,inStack,parent)){
                return 0;
            }
        }
    }

    cout << 0 << endl; // no cycle

    return 0;
}