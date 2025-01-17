#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

int main(){

    int t;
    cin>>t;
    for(int i=1;i<=t;i++){

        int n,ans=0;
        cin>>n;
        vector<vector<int>> a(n,vector<int>(5,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin>>a[i][j];
            }
        }

        queue<vector<int>> q;
        q.push({0,n,2,-1}); // score,row,col,bomb_used

        while(!q.empty()){
            auto it=q.front();
            q.pop();

            int score = it[0], r=it[1], c=it[2], bomb_used=it[3];
            ans = max(ans,score);

            for(int j=-1;j<=1;j++){
                int row = r-1;
                int col = c+j;

                if(row<0 || col<0 || col>5){
                    continue;
                }

                if(a[row][col]<=1){
                   if(bomb_used == -1 || (bomb_used-row)<=4){
                     q.push({a[row][col]+score,row,col,bomb_used});
                   }
                }

                else{
                    if(bomb_used == -1 ){
                        q.push({score,row,col,row});
                    }
                   
                }
            }
        }

        cout<<"#"<<i<<" "<<ans<<endl;
    }

    return 0;
}