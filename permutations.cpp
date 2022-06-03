void solve(string s,set<string> &ans,int idx){
	        //base case
	        if(idx == s.size()){
	            ans.insert(s);
	            return;
	        }
	        //body
	        for(int i=idx;i<s.size();i++){
	           // if(i!=0 && s[i] == s[i-1]) continue;
	            swap(s[i],s[idx]);
	            solve(s,ans,idx+1);
	            swap(s[i],s[idx]);
	        }
	        
	    }
	    
		vector<string>find_permutation(string S)
		{
		    set<string> ans;
		    vector<string> final;
		    solve(S,ans,0);
		    while(!ans.empty()){
		        auto it = ans.begin();
		        final.push_back(*it);
		        ans.erase(ans.begin());
		    }
		    return final;
		}
