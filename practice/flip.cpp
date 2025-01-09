#include<cstdio>
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){

    int n,m,k,ans=0;
    cin>>n>>m>>k;

    unordered_map<string,int> freq;

    for(int i=0;i<n;i++){

        string temp="";
        int zeros=0;

        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            if(x==0){
                zeros++;
            }
            temp +='0'+x;
        }

        //you forgot where to use this and what was the condition
        if(zeros<=k && (k-zeros)%2==0){
            freq[temp]++;
        }
    }

    for(auto it:freq){
        //also forgot was the condition less than or greater than
        if(ans<it.second){
            ans=it.second;
        }
    }

    cout<<ans<<endl;

    return 0;
}