#include <bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &a, int n, int m, int x, int y, int val, int k){
    if(x<0 || x>=n || y<0 || y>=m || a[x][y]!=val)
        return ;
    a[x][y] = k;
    solve(a,n,m,x+1,y,val,k);
    solve(a,n,m,x-1,y,val,k);
    solve(a,n,m,x,y+1,val,k);
    solve(a,n,m,x,y-1,val,k);
}

int main() {
    int t;  cin>>t;
    while(t--){
        int n,m;    cin>>n>>m;
        vector<vector<int>> a(n, vector<int>(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        int x,y,k;  cin>>x>>y>>k;
        int val = a[x][y];
        solve(a,n,m,x,y,val,k);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<a[i][j]<<" ";
            }
        }
        cout<<endl;
    }
	return 0;
}