#include<bits/stdc++.h>
using namespace std;
#define lli long long int
int main()
{
	int t;	cin>>t;
	while(t--){
		int n,k;	cin>>n>>k;
		string a, b;	cin>>a>>b;
		int freqa[27] = {0};
		int freqb[27] = {0};
		for(int i=0;i<n;i++)
			freqa[a[i]-'a']++;
		for(int i=0;i<n;i++)
			freqb[b[i]-'a']++;
		int flag=0;
		for(int i=0;i<26;i++){
			if(freqb[i] > freqa[i]  || (freqa[i]-=freqb[i])%k){
				flag = 1;
				break;
			}
			freqa[i+1] += freqa[i];
		}
		cout<<(flag ? "NO" : "YES")<<endl;
	}
	return 0;
}