#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;  
    cin>>t;
    while(t--){
        
        int n,x,p,k;    cin>>n>>x>>p>>k;
        int in[n];
        for(int i=0;i<n;i++){ cin>>in[i]; }
        sort(in, in+n);
        
        int res = 0;
        if(in[p-1] == x){cout<<"0"<<endl;}
        else if(p>=k && in[p-1]<=x){
                for(int i=p-1;i<n;i++){
                    if(in[i]<x)
                        res++;
                }
                cout<<res<<endl;
        }
        
        else if(k>=p && in[p-1]>=x){
                for(int i=p-1;i>=0;i--){
                    if(in[i]>x)
                        res++;
                }
                cout<<res<<endl;
        }
        
        else{
            cout<<"-1"<<endl;
        }
    }
	return 0;
}