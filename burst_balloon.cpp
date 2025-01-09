#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<climits>
using namespace std;

int cal_score(vector<int> &b, vector<vector<int>> &dp, int start, int end, int n ){
    
    int max_score = INT_MIN, score=0;
    
    if(start>end){
        return 0;
    }
    
    if(dp[start][end]!=0){
        return dp[start][end];
    }
    
    for(int i=start;i<=end;i++){
        if((start-1)==0 && ((end+1)==n+1)){
            score = b[i]+ cal_score(b,dp,start,i-1,n)+cal_score(b,dp,i+1,end,n);
        }
        else{
             score = b[start-1]*b[end+1] + cal_score(b,dp,start,i-1,n)+cal_score(b,dp,i+1,end,n);
        }
        
         max_score = max(max_score,score);
    }
   
    return dp[start][end] = max_score;
}
int main(){
    int n;
    cin>>n;
    vector<int> b(n+2);
    b[0]=1;
    b[n+1]=1;
    
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    
    cout << cal_score(b,dp,1,n,n) << endl;
    return 0;
}