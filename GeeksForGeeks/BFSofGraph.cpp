
vector <int> bfs(vector<int> g[], int N) {
    queue<int> q;
    vector<bool> visited(N+1, false);
    vector<int> ans;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(auto i : g[node]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return ans;
}