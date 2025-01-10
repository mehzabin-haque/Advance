#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int cal_max_score(int start, int end,vector<int> &b,vector<vector<int>> &dp, int n){

    if(start>end){
        return 0;
    }

    if(dp[start][end]!=-1){
        return dp[start][end];
    }

    int max_score = INT_MIN, score=0;
    
    for(int i=start;i<=end;i++){
        //you forgot this condition and was confused about the i+1 and i-1 part
        if((start-1)==0 && (end+1)==n+1){
            score = b[i]+ cal_max_score(i+1,end,b,dp,n)+cal_max_score(start,i-1,b,dp,n);
        }
        else{
            score = b[start-1]*b[end+1]+ cal_max_score(i+1,end,b,dp,n)+cal_max_score(start,i-1,b,dp,n);
        }

        max_score = max(max_score,score);
    }

    return dp[start][end]=max_score;
    
}

int main(){

    int n;
    cin>>n;
    vector<int> b(n+2);
    b[0]=1;
    b[n+1]=1;

    for(int i=1;i<=n;i++){
        cin>> b[i];
    }

    vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
    cout << cal_max_score(1,n,b,dp,n)<<endl;
    return 0;
}