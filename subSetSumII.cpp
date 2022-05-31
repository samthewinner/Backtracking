#include <bits/stdc++.h>

using namespace std;

void subset(vector<int>a, vector<vector<int>> &ans,vector<int> temp,int k,int n,int idx,int sum){
    
    if(sum > k) return;

     if(sum == k){
        ans.push_back(temp);
    }

    if(idx == n)      
        return ;
    int p=0,i=0;
    while (p<k)
    {
        p=a[idx]*i;
        if(i)temp.push_back(a[idx]);
        subset(a,ans,temp,k,n,idx+1,p+sum);
        i++;
    }
       
    

    return;
}

int main(){
    vector <int> a;
    vector <vector<int>> ans;   
    vector<int> temp; 
    a={2,2,6,4,3};
    int k=9;

    // sort(a.begin(),a.end());
    subset(a,ans,temp,k,a.size(),0,0);
    // sort(ans.begin(),subset.end());
    set<vector<int>> s;
    for (int i = 0; i < ans.size(); i++)
    {
        s.insert(ans[i]);
    }
    ans.clear();
    while(!s.empty()){
        auto it = s.begin();
        ans.push_back(*it);
        s.erase(s.begin());
    }
    for(auto it: ans){
        for(auto jt: it)
        cout<<jt<<" ";
        cout<<endl;
    }
    return 0;
}
