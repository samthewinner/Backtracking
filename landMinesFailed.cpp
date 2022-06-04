
bool isSafe(vector<vector<int >> f, int x,int y){
    if(f[x][y] == -1) return false;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || ny<0 ||  nx>=f.size() || ny>=f[0].size() || (f[nx][ny] == 0 ) ) return false;
    }
    return true;
}

int  solve(vector<vector<int>> f,int x,int y ,int path){
    //base case
    if(y == f[0].size()-1) return path;
    //body
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    int ans=INT_MAX;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isSafe(f,nx,ny)){
            f[nx][ny]= -1;
            int l = solve(f,nx,ny,path+1);
            f[nx][ny] = 1;
            if(l==INT_MAX)continue;
            ans = min(ans,l);
        }
    }
    if(ans == INT_MAX)
        return -1;
    return ans;
}

int shortestPath(vector<vector<int>> &field)
{
    int i;
    for( i=0;i<field.size();i++){
        if(isSafe(field,i,0)) break;
    }    
	return solve(field,i,0,0);
}
