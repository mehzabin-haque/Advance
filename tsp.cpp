#include<cstdio>
#include<cmath>
#include<vector>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int solve(int n,vector<vector<int>> &matrix, int idx, int ini_mask, int total_mask){
    if(ini_mask==total_mask){
        return matrix[idx][0];
    }
    
    int ans = INT_MAX;
    
    for(int i=0;i<n;i++){
        if((ini_mask & (1<<i))==0){
            int y = (ini_mask | (1<<i));
            int temp = matrix[idx][i]+ solve(n,matrix,i,y,total_mask);
            ans = min(ans,temp);
        }
    }
    
    return ans;
}

int main(){
    
    int t;
    cin>>t;
    
   
    
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<vector<int>> matrix(n,vector<int>(n));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>matrix[i][j];
            }
        }
        
        int ini_mask=0;
        int total_mask=(1<<n)-1;
        cout<<solve(n,matrix,0,ini_mask,total_mask)<<endl;
    }
    
   
    return 0;
}