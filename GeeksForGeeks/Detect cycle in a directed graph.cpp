bool cyclic(int i, int V, vector<int> adj[],bool visited[], bool stack[])
{
    visited[i]=true;
    stack[i]=true;
    for(int j =0;j<adj[i].size();j++)
    { 
        if(!visited[adj[i][j]] &&  cyclic(adj[i][j],V,adj,visited,stack))
        {
            return true;
        }
        else{
            if(stack[adj[i][j]])
            return true;
        }
    }
    stack[i]=false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    bool visited[V];
    bool stack[V];
    for(int  i=0;i<V;i++)
    {
        visited[i]=false;
        stack[i]= false;
    }
    
    for(int i =0;i<V;i++)
    {  if(!visited[i]){
      if(cyclic(i,V,adj,visited,stack))
      return true;
    }
    }
    return false;
}