#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        
        int n;
        cin>>n;
        
        vector<vector<int>> a(n,vector<int>(5,-1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin >> a[i][j];
            }
        }
        
        queue<vector<int>> q;
        q.push({0,n,2,-1}); //score,row,col,bomb_used
        int ans=0;
        
        while(!q.empty()){
           auto first_input = q.front();
           
           q.pop();
           int score = first_input[0], r = first_input[1], c = first_input[2], bomb_used = first_input[3];
           ans = max(ans,score);
           
           for(int j=-1;j<=1;j++){
               int row = r-1;
               int col = c+j;
               
               if(row<0 || col<0 || col>5) continue;
               
               if(a[row][col]<=1){
                   if(bomb_used==-1 || bomb_used - row<=4){
                       q.push({score+a[row][col],row,col,bomb_used});
                   }
               }
               
               else{
                   if(bomb_used == -1){
                       q.push({score,row,col,row});
                   }
                   // else if(bomb_used - row <=4){
                   //      q.push({score,row,col,bomb_used});
                   // }
               }
           }
        }
        
        cout << "#" << i << " " << ans << endl;
    }
}
