vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> s;
    dist[src] = 0;
    vector<bool> visited(V, false);
    s.push(make_pair(dist[src], src));
    while(s.size()){
        int node = s.top().second;
        s.pop();
        if(visited[node])
            continue;
        visited[node] = 1;
        for(int i=0;i<V;i++){
            if(g[node][i] && dist[node] + g[node][i] < dist[i]){
                dist[i] = dist[node] + g[node][i];
                s.push(make_pair(dist[i], i));
            }
        }
    }
    return dist;
}