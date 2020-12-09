typedef pair<int,int> iPair;
int spanningTree(vector <pair<int,int> > g[], int MAX)
{   int V=MAX;
    priority_queue<iPair,vector<iPair>,greater<iPair> > pq;
    vector<int> key(V+1,INT_MAX);
    vector<bool>isMst(V+1,0);
    vector<int>parent(V+1,-1);
    int src=1;
    int sum=0;
    pq.push(make_pair(0,src));
    key[src]=0;
    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        isMst[u]=1;
        vector<pair<int,int>>::iterator i;
        for(i=g[u].begin();i!=g[u].end();i++){
            int v=(*i).second;
            int w=(*i).first;
            if(isMst[v]==0&&key[v]>w){
                key[v]=w;
                pq.push(make_pair(w,v));
                parent[v]=u;
               // sum+=w;
            }
            
        }
    }
    for(int i=1;i<=V;i++){if(key[i]!=INT_MAX){sum+=key[i];}//cout<<key[i]<<" ";
    }
    return sum;
	//Your code here
}