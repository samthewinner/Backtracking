 void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int >  ds)
    {
  
  if (target == 0) 
  {
    ans.push_back(ds);
    return;
  }
  
  for (int i = ind; i < arr.size(); i++)
  {
    if (i > ind && arr[i] == arr[i - 1]) continue;
    if (arr[i] > target) break;
    ds.push_back(arr[i]);
    findCombination(i , target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}

    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
         sort(A.begin(), A.end());
  vector < vector < int >> ans;
  vector < int > ds;
  findCombination(0, B, A, ans, ds);
  return ans;
    }
