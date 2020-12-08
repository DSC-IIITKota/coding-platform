void dfs_helper(vector<int> g[], vector<bool> &visited, vector<int> &ans, int src){
    visited[src] = true;
    for(auto i : g[src]){
        if(!visited[i]){
            ans.push_back(i);
            dfs_helper(g, visited, ans, i);
        }
    }
}

vector <int> dfs(vector<int> g[], int N)
{
    vector<int> ans;
    vector<bool> visited(N+1, false);
    ans.push_back(0);
    dfs_helper(g, visited, ans, 0);
    return ans;
}

