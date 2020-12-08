void dfs(vector< vector<int> >& g, int v, vector<bool>& vis,stack<int>& st){
    vis[v] = 1;
    for(int u : g[v]){
        if(!vis[u]){
            dfs(g,u,vis,st);
        }
    }
    st.push(v);
}
string findOrder(string dict[], int n, int k) {
    vector< vector<int> > g(26,vector<int>());
    for(int i = 1; i < n; i++){
        string s1 = dict[i-1];
        string s2 = dict[i];
        for(int j = 0; j < min(s1.size(),s2.size()); j++){
            if(s1[j] != s2[j]){
                g[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }
    stack<int> st;
    vector<bool> vis(26,0);
    for(int i = 0; i < 26; i++){
        if(!vis[i] && g[i].size() > 0){
            dfs(g,i,vis,st);
        }
    }
    string ans = "";
    while(!st.empty()){
        char c = 'a' + st.top();
        ans += c;
        st.pop();
    }
    return ans;
}