#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &a,int &s,int i,int j,int m,int n)
{
    s++; a[i][j]=0;
    
    if(i-1>=0 && a[i-1][j])  
        solve(a,s,i-1,j,m,n);
    if(i+1<m && a[i+1][j])   
        solve(a,s,i+1,j,m,n);
    if(j-1>=0 && a[i][j-1])  
        solve(a,s,i,j-1,m,n);
    if(j+1<n && a[i][j+1])   
        solve(a,s,i,j+1,m,n);
    if(i-1>=0 && j-1>=0 && a[i-1][j-1])  
        solve(a,s,i-1,j-1,m,n);
    if(i-1>=0 && j+1<n && a[i-1][j+1])   
        solve(a,s,i-1,j+1,m,n);
    if(i+1<m && j-1>=0 && a[i+1][j-1])   
        solve(a,s,i+1,j-1,m,n);
    if(i+1<m && j+1<n && a[i+1][j+1])    
        solve(a,s,i+1,j+1,m,n);
    
}
int main()
{
	int t,m,n; cin>>t;
	while(t--)
	{
	    cin>>m>>n; vector<vector<int>> a(m,vector<int>(n,0));
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++)
	        {int x;  cin>>x; a[i][j]=x;}
	    }
	    int ans=0;
	   int s=0;
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(a[i][j]){
	                solve(a,s,i,j,m,n);
	                ans=max(ans,s);
	                s=0;
	            }
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}