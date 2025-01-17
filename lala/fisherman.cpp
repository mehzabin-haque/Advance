#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<cstring>
using namespace std;

vector<int> gates(3);
vector<int> people(3);
static int dp[101][11][11][11];
int n;

int min_dist(int index, int p0,int p1, int p2){

    if(p0+p1+p2==0){
        return 0;
    }

    if(index>n){
        return INT_MAX;
    }

    int &res = dp[index][p0][p1][p2];

    if(res != -1){
        return res;
    }
    int best = min_dist(index+1,p0,p1,p2);

    if(p0>0){
        int cost = abs(gates[0]-index)+1;
        int rec = min_dist(index+1,p0-1,p1,p2);
        
        if(rec!=INT_MAX){
            best = min(best,cost+rec);
        }
    }

    if(p1>0){
        int cost = abs(gates[1]-index)+1;
        int rec = min_dist(index+1,p0,p1-1,p2);
        
        if(rec!=INT_MAX){
           best = min(best,cost+rec);
        }
    }

    if(p2>0){
        int cost = abs(gates[2]-index)+1;
        int rec = min_dist(index+1,p0,p1,p2-1);
        
        if(rec!=INT_MAX){
            best = min(best,cost+rec);
        }
    }

    res = best;

    return res;
}

int main(){

    cin>>n;

    for(int i=0;i<3;i++){
        cin>>gates[i];
    }

    for(int i=0;i<3;i++){
        cin>>people[i];
    }

    memset(dp,-1,sizeof(dp));

    cout << min_dist(1,people[0],people[1],people[2])<<endl;

}