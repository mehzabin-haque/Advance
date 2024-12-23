#include <cmath>
#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int n, vector<vector<int>>&arr, int index, int ini_mask, int total_mask){
    if(ini_mask==total_mask){
        return arr[index][0];
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if((ini_mask & (1<<i))==0){
            int y=(ini_mask | (1<<i));
            int temp = arr[index][i]+solve(n, arr, i, y , total_mask);
            ans=min(ans, temp);
        }
    }
    return ans;
}


int main() {
     
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>arr;
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                int x;
                cin>>x;
                temp.push_back(x);
            } arr.push_back(temp);
        }
        int ini_mask=1;
        int total_mask=(1<<n)-1;
        cout<<solve(n, arr, 0, ini_mask, total_mask)<<endl;
    }
    return 0;
}
