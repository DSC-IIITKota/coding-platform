bool DFS(int g[][MAX], int V, int u, vector<int> &color, int cr){
    if(color[u]!=-1)
        return (color[u] == cr);
    
    color[u] = cr;
    
    for(int i=0;i<V;i++){
        if(g[u][i] && !DFS(g,V,i,color,1-cr))
            return false;
    }
    return true;
}

bool isBipartite(int g[][MAX],int V)
{
    vector<int> color(V, -1);
    for(int i=0;i<V;i++){
        if(color[i] == -1 && !DFS(g,V,i,color,1))
            return false;
    }
    return true;
}