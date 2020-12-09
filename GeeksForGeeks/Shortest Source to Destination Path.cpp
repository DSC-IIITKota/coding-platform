#include <bits/stdc++.h>
using namespace std;

int x[4] = {0,1,0,-1};
int y[4] = {1,0,-1,0};

void solve(int src, int end, vector<vector<int>> &a, int n, int m, int &ans, int count, int &flag){
    if(a[src][end] == 2){
        ans = min(ans, count);
        flag=1;
        return;
    }
    if(a[src][end] == 0 || a[src][end] == -1){
        return;
    }
    a[src][end] = -1;
    if(src < n-1) solve(src+1, end, a, n, m, ans, count+1,flag);
    if(src > 0) solve(src-1, end, a, n, m, ans, count+1,flag);
    if(end < m-1) solve(src, end+1, a, n, m, ans, count+1,flag);
    if(src > 0) solve(src, end-1, a, n, m, ans, count+1,flag);
    a[src][end] = 1;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, m;   cin>>n>>m;
        vector<vector<int>> a(n, vector<int>(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        
        int s,e;    cin>>s>>e;
        if(a[s][e] == 0)
            cout<<"-1"<<endl;
        else if(a[s][e] == 1){
            a[s][e] = 2;
        int ans = INT_MAX, count = 0;
        int flag = 0;
        solve(0,0,a,n,m,ans,count,flag);
        if(flag==0)
            cout<<"-1"<<endl;
        else
            cout<<ans<<endl;
    }
    }
	return 0;
}