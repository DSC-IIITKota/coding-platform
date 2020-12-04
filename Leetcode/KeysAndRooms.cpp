class Solution {
public:
    void ans(vector<bool> &vis,int i,vector<vector<int>> in)
    {
        for(auto j:in[i])
        {
            if(!vis[j])
            {
                vis[j]=true;
                ans(vis,j,in);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& in) {
        int n=in.size();
        vector<bool> vis(n,false);vis[0]=true;
        ans(vis,0,in);
        for(int i=0;i<n;i++)
            if(!vis[i])return false;
        return true;
    }
};