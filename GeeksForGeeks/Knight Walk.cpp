#include <bits/stdc++.h>
using namespace std;

int min(int a[],int n)
{
    int m=a[0];
    for(int i=1;i<n;i++)
        if(a[i]<m)
            m=a[i];
    return m;
}

int solve(int s1, int s2, int d1, int d2, int n, int m, vector<vector<int>> &dist, int curr){
    if(s1<=0 || s2<=0 || d1<=0 || d2<=0 || s1>n || s2>m || d1>n || d2>m){
        return INT_MAX;
    }
    if(dist[s1][s2]!=INT_MAX && dist[s1][s2] <= curr+1 && !(s1==d1 && s2 == d2)){
        return INT_MAX;
    }
    if(s1==d1 && s2==d2)
        return curr+1;
    
    if(dist[s1][s2] > curr+1){
        dist[s1][s2]=curr+1;
        
        int a[8];
        a[0]=solve(s1-1,s2-2,d1,d2,n,m,dist,curr+1);
        a[1]=solve(s1+1,s2-2,d1,d2,n,m,dist,curr+1);
        a[2]=solve(s1-2,s2-1,d1,d2,n,m,dist,curr+1);
        a[3]=solve(s1+2,s2-1,d1,d2,n,m,dist,curr+1);
        a[4]=solve(s1-1,s2+2,d1,d2,n,m,dist,curr+1);
        a[5]=solve(s1+1,s2+2,d1,d2,n,m,dist,curr+1);
        a[6]=solve(s1-2,s2+1,d1,d2,n,m,dist,curr+1);
        a[7]=solve(s1+2,s2+1,d1,d2,n,m,dist,curr+1);
        return min(a,8);
    }
        
}

int main() {
    int t;  cin>>t;
    while(t--){
        int n,m;    cin>>n>>m;
        int s1,s2,d1,d2;    cin>>s1>>s2>>d1>>d2;
        vector<vector<int>> dist(26, vector<int> (26));
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                dist[i][j] = INT_MAX;
        int ans = solve(s1,s2,d1,d2,n,m,dist,0);
        if(ans == INT_MAX)
            cout<<"-1"<<endl;
        else
            cout<<ans-1<<endl;
    }
	return 0;
}