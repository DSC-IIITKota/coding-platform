vector<int> topoSort(int v, vector<int> adj[]) {
    int inDegree[v] = {0};
    for(int i=0;i<v;i++){
        for(int j=0;j<adj[i].size();j++){
            inDegree[adj[i][j]]++;
        }
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto i : adj[node]){
            inDegree[i]--;
            if(inDegree[i] == 0)
                q.push(i);
        }
    }
    return ans;
}
