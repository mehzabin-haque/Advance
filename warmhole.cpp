#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct point{
    int x,y;
};
struct wormhole{
    point source,destination;
    int value;
};



int manhattan_dist(point a,point b){
    return abs(a.x-b.x)+abs(a.y-b.y);
}

int solve(point source, int cost, point final_destination, const vector<wormhole> &wormholes, vector<int> &visited){
    
    int ans= cost+manhattan_dist(source,final_destination);
    
    for(int i=0;i<wormholes.size();i++){
        if(!visited[i]){
            visited[i]=1;
            
            //forward direction
            ans=min(ans,solve(wormholes[i].destination, cost+manhattan_dist(source,wormholes[i].source)+wormholes[i].value, final_destination,wormholes,visited));
             ans=min(ans,solve(wormholes[i].source, cost+manhattan_dist(source,wormholes[i].destination)+wormholes[i].value, final_destination,wormholes,visited));
            
            visited[i]=0;
        }
    }
    
    //  cout<<"("<<source.x<<","<<source.y<<") -> ("<<final_destination.x<<","<<final_destination.y<<") ="<<ans<<endl;
    return ans;
}
int min_cost_to_travel(point source,point destination,const vector<wormhole> &wormholes){
    
    int n = wormholes.size();
    vector<int> visited(n,0);
    
    return solve(source,0,destination,wormholes,visited);
}

int main(){
    
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int num_of_wormholes;
        cin>>num_of_wormholes;
        
        point source,destination;
        cin>>source.x>>source.y>>destination.x>>destination.y;
        
        vector<wormhole> wormholes(num_of_wormholes);
        
        for(int i=0;i<num_of_wormholes;i++){
            cin>>wormholes[i].source.x>> wormholes[i].source.y;
            cin>>wormholes[i].destination.x>> wormholes[i].destination.y;
            cin>>wormholes[i].value;
        }
        
        cout<< min_cost_to_travel(source,destination,wormholes) <<endl;
        
    }
    return 0;
}