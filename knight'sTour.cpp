
bool solve(vector<vector<int>> &ans,int n,int m,int x,int y,int step){
    if(step == (n*m)) {ans[x][y] == step;return true;}
    int nx,ny;bool flag=true;
    int dx[4] = {-2,-1,1,2};
    for(int i=0;i<4;i++){
        nx = x + dx[i];
        for(int j=0;j<2;j++){
            //sets the value of nx && ny
            if(dx[i] == 2 || dx[i] == -2){
                if(flag){
                    flag=false;
                    ny=y -1;                    
                }
                else {flag=true;ny=y+1;}
            }
            else{
                if(flag){
                    flag=false;
                    ny=y-2;
                }
                else{flag=true;ny=y+2;}
            }
            //call the solve function recursively for the valid nx and ny values
            if((nx >= 0 && nx <n && ny >= 0 && ny<m) && ans[nx][ny] == -1){
                        ans[x][y]=step;
                        if(solve(ans,n,m,nx,ny,step+1)){
                            return true;
                        }
                        ans[x][y] = -1;
                    }
        }
    }
    return false;
}

vector<vector<int>> knightTour(int n, int m) {
    /* 
        Return matrix of size n*m where integer
        at cell(i, j) represent move number of knight to reach that
        cell. Move number start from 0.

        It may be possible that there is no possible order to visit each cell
        exactly once. In that case, return a matrix of size n*m having all the values
        equal to -1.
    */

    // Write your code here.
    
    vector<vector<int>> b(n,vector<int>(m,-1));    
    if(n==1 && m == 1) {b[0][0]=0; return b;}
    if(solve(b,n,m,0,0,0))
    for(auto it : b){
        for(auto j : it)
               cout<<j<<"   ";
        cout<<endl;
    }
    return b;
}
