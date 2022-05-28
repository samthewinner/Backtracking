bool isPal(string s){
      if(s.size() == 1) return true;
      int n=s.size();
      for(int i=0;i<n/2;i++){
          if(s[i] != s[n-i-1])return false;
      }
      return true;
  }
  
  void solve(string s,vector<vector<string>> &ans, string temp){
      //base case
      if(s==""){
          temp=temp.substr(0,temp.size()-1);
          vector<string> a;
          a.push_back(temp);
          ans.push_back(a);
          return;
      }
      string word ="";
      for(int i=0;i<s.size();i++){
          word+=s[i];
          if(isPal(word)){
            //   temp+=word;
              solve(s.substr(i+1),ans,temp+word+' ');
            //   temp=temp
          }
      }
      return;
  }
  
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>> ans;
        solve(S,ans,"");
        return ans;
    }
