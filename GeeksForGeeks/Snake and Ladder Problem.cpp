#include <bits/stdc++.h>
using namespace std;

int solve(unordered_map<int, int> &m, int src, int dest){
    vector<bool> vis(31, false);
    queue<int> q;
    q.push(src);
    vis[src] = true;
    int ans = 0;
    while(q.size()){
        int size = q.size();
        while(size--){
            int u = q.front();
            q.pop();
            if(u == dest)   return ans;
            for(int i=1;i<=6;i++){
                int d = m[u+i] ? m[u+i] : u+i;
                if(d<=30 && !vis[d]){
                    vis[d] = true;
                    q.push(d);
                }
            }
        }
        ans++;
    }
    return ans;
}

int main() {
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        unordered_map<int, int> m;
        for(int i=0;i<n;i++){
            int x,y;    cin>>x>>y;
            m[x] = y;
        }
        cout<<solve(m,1,30)<<endl;
    }
	return 0;
}