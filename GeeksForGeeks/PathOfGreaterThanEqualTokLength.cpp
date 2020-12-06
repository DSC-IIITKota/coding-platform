#include<iostream>
#include<vector>
using namespace std;

int dfs(vector<vector<int>> &g, int& v, int k, int& cur, vector<bool>& vis){
    if (k <= 0) return 1;
    
    vis[cur] = true;
    
    for (int i=0; i<v; i++){
        if (g[cur][i] && !vis[i]){
            if (dfs(g, v, k-g[cur][i], i, vis)) return 1;
        }
    }
    
    vis[cur] = false;
    return 0;
}

int main(){
    int T;
    cin >> T;
    for (int t=0; t<T; t++){
        string str;
        int v, e, k;
        cin >>v >> e >> k;
        
        vector<vector<int>> g(v, vector<int>(v, 0));
        
        for (int i=0; i<e; i++){
            int x, y, z;
            cin >> x >> y >> z;
            g[x][y] = z;
            g[y][x] = z;
        }
        vector<bool> vis(v);
        int root = 0;
        cout << dfs(g, v, k, root, vis) << endl;
    }
	return 0;
}