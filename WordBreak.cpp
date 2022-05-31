void solve(string s,set<string> ds, string temp,vector<string>&ans){
        if(s==""){
            ans.push_back(temp.substr(0,temp.size()-1));
            return;
        }
        string wc = ""; //word check - 'wc'
        // char t = s[0];
        // wc+=t;
        for(int i=0;i<s.size();i++){
            wc+=s[i];
            if(ds.find(wc) != ds.end()){
                wc+=' ';
                //recursive call
                solve(s.substr(i+1),ds,temp+wc,ans);
                //backtrack
                wc=wc.substr(0,wc.size()-1);
            }
        }
        return;
    }

    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        set<string>ds;//dictionary set
        vector<string> ans;
        // if(s.size() < 2 ) return ans;
        for(int i=0;i<n;i++){
            ds.insert(dict[i]);
        }
        solve(s,ds,"",ans);
        return ans;
    }
