#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        
        vector<vector<int>> a(n,vector<int>(5,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin >> a[i][j];
            }
        }
        
        int ans=0;
        queue<vector<int>> q;
        q.push({0,n,2,-1}); // score, row, col, bomb_used
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int score = it[0], x=it[1], y=it[2], bomb_used= it[3];
            ans = max(ans,score);
            
            for(int j=-1;j<=1;j++){
                int xx=x-1;
                int yy= y+j;
                if(xx<0 || yy<0 || yy>=5){
                    continue;
                }
                
                if(a[xx][yy] <=1){
                    if(bomb_used == -1 || bomb_used - xx <=4){
                        q.push({score+a[xx][yy],xx,yy,bomd_used});
                    }
                }
                else{
                    if(bomb_used = -1){
                        q.push({score,xx,yy,xx});
                    }
                    else if(bomb_used - xx <=4){
                        q.push({score,xx,yy,bomb_used});
                    }
                }
            }
        }
        
        cout << "#" << i << " " << ans << "\n";
    }
    
    
}