bool solve(int *arr ,int n,set<vector<int>> &ans , vector<int> temp, int target,int idx){
      //base case
     if(target < 0 ) return false;
     if(target == 0) 
     {
        sort(temp.begin(),temp.end());
        if(ans.find(temp) != ans.end()) return false;
        ans.insert(temp);
        return true;
     }
     if(idx == n) return false;
     
      //body
     
     temp.push_back(arr[idx]);
     
     if(solve(arr,n,ans,temp,target-arr[idx],idx+1))
            return true;
     //backtrack
     temp.pop_back();
     
     if(solve(arr,n,ans,temp,target,idx+1)) return true;
     
     
     return false;
      
      
      
  }
  
    bool isKPartitionPossible(int a[], int n, int k)
    {
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum += a[i];
        }
        if(sum%k != 0) return false;
        
        set<vector<int>> ans;
        
        vector<int> temp;
        for(int i=0;i<k;i++){
            if(!solve(a,n,ans,temp,sum/k,0))
                return false;
         }
         
         return true;
    }
