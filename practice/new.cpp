#include<cstdio>
#include<vector>
#include<queue>
#include<climits>
#include<iostream>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(5));
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin>>a[i][j];
            }
        }
        int ans=0;

        queue<vector<int>> q;
        q.push({0,n,2,-1}); //score,row,col,bomb
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int score = it[0], r = it[1], c=it[2],bomb_used=it[3];

            
            for(int j=-1;j<=1;j++){
                int row=r-1;
                int col=c+j;
                ans= max(ans,score);
                if(a[row][col]==1){
                    if(bomb_used==-1 || bomb_used - row <=4){
                        q.push({score+a[row][col],row,col,bomb_used});
                    }
                }
                else{
                     if(bomb_used==-1){
                        q.push({score,row,col,row});
                     }
                }
            }
        }

        cout << ans << endl;
    }
}