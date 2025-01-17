#include<cstdio>
#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;

    unordered_map<string,int> freq;

    int ans=0;

    for(int i=0;i<n;i++){
        string temp = "";
        int zeros=0;
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            if(x==0){
                zeros++;
            }
            temp +='0'+x;
        }

        if((zeros<=k)&&((k-zeros)%2==0)){
            freq[temp]++;
        }
    }

    for(auto it: freq){
        if(it.second>ans){
            ans = it.second;
        }
    }

    cout<<ans<<endl;
}