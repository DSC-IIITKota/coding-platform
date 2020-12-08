bool helper(int node, int parent, vector<bool> &visited, vector<int> g[]){
    visited[node] = true;
    for(auto i : g[node]){
        if(!visited[i]){
            if(helper(i, node, visited, g))
                return true;
        }
        else if(i!=parent || i==node)
            return true;
    }
    return false;
}

bool isCyclic(vector<int> g[], int V)
{
    vector<bool> visited(V, false);
    for(int i=0;i<V;i++){
        if(!visited[i] && helper(i, -1, visited, g))
            return true;
    }
    return false;
}