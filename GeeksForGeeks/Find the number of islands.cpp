void solve(vector<int> a[], int i, int j, int N, int M){
    if(i >= N || j >= M || i<0 || j<0 || a[i][j] == 0)
        return;
    
    a[i][j] = 0;
    solve(a,i+1,j,N,M);
    solve(a,i-1,j,N,M);
    solve(a,i,j+1,N,M);
    solve(a,i,j-1,N,M);
    solve(a,i+1,j+1,N,M);
    solve(a,i+1,j-1,N,M);
    solve(a,i-1,j+1,N,M);
    solve(a,i-1,j-1,N,M);
}

int findIslands(vector<int> a[], int N, int M) {
    int ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(a[i][j] == 1){
                solve(a, i, j, N, M);
                ans++;
            }
        }
    }
    return ans;
}
