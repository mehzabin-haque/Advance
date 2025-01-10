#include<vector>
#include<cmath>
#include<iostream>
using namespace std;

bool isBipartite = true;

void checkBipartite(int cv, int cc, vector<vector<int>> &graph, vector<int> &color){

    if(color[cv]!=-1){
        if(color[cv]!=cc){
            isBipartite = false;
        }
        return;
    }

    color[cv]=cc;

    for(int i=0;i<graph.size();i++){
        if(graph[cv][i]==1){
            checkBipartite(i,abs(1-cc),graph,color);
        }
    }
}

int main(){

    int v,e;
    cin>>v>>e;

    vector<vector<int>> graph(v,vector<int>(v,0));

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1;
    }

    vector<int> color(v,-1);
    checkBipartite(0,1,graph,color);
    if(isBipartite){
        cout<< "Bipartite"<<endl;
    }
    else{
        cout<< "Not Bipartite"<<endl;
    }
    return 0;
}