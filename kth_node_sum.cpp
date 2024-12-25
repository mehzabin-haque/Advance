#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;

    int n=s.size();
    int current_level = -1;
    int sum=0;

    for(int i=0;i<n;i++){
        if(s[i]=='('){
            current_level++;
        }
        else if(s[i]==')'){
            current_level--;
        }
        else if(current_level==k){
            string num_str = "";
            while(i<n && s[i]!='(' && s[i]!=')'){
                num_str = num_str + s[i];
                i++;
            }
            sum += stoi(num_str);
            i--;
        }
    }

    cout<<sum<<endl;
}