#include <iostream>
#include <climits>
using namespace std;

int n;
int gate[3];
int people[3];
int sum;

int ans=INT_MAX;

int abs(int a){
    return a>=0?a:-a;
}

void solve(int index, int val, int count){
    if(count==sum){
        ans=min(ans, val);
        return;
    }
    if(index==n+1){
        return ;
    }
    
    for(int i=0;i<3;i++){
        if(people[i]>0){
            people[i]--;
            solve(index+1, val+abs(gate[i]-index)+1, count+1);
            people[i]++;
        }
    }
    solve(index+1, val, count);
}

int main(){
    cin>>n;
    for(int i=0;i<3;i++){
        cin>>gate[i];
    }
    for(int i=0;i<3;i++){
        cin>>people[i];
        sum+=people[i];
    }
    
    solve(1, 0, 0);
    cout<<ans<<endl;
    return 0;
}

