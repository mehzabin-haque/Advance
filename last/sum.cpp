#include<cmath>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int k, current_level=-1,ans=0;
    cin>>k;
    string s;
    cin>>s;
    int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            current_level++;
        }
        else if(s[i]==')'){
            current_level--;
        }
        else if(current_level==k){
            string num_string="";
            while(i<n && s[i]!='(' && s[i]!=')'){
                num_string +=s[i];
                i++;
            }
            ans += stoi(num_string);
            i--;
        }
       
    }
     cout <<ans;
}