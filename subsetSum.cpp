#include <bits/stdc++.h>

using namespace std;

void subset(vector<int>a, vector<int> &ans,int n,int idx,int sum){
    if(idx == n){
        if(sum == 0) sum = -1;
        ans.push_back(sum);
        return ;
    }
    //include in sum    
    subset(a,ans,n,idx+1,sum + a[idx]);

    //dont include in sum    
    subset(a,ans,n,idx+1,sum);

    return;
}

int main(){
    vector <int> a;
    vector <int> ans;    
    a={1,6,4};
    subset(a,ans,a.size(),0,0);
    
    for(auto it: ans)
        cout<<it<<" ";
    return 0;
}
