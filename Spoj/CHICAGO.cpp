#include<bits/stdc++.h>
using namespace std;
 
vector< vector< pair<int, double> > > graph;
vector<double> dis;
 
double dijkstra(int s, int d){
	queue<int> q;
	fill(dis.begin(), dis.end(), -1);
	dis[s] = 1;
	q.push(s);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		int n = graph[node].size();
		for(int i=0;i<n;i++){
			int nextNode = (graph[node][i]).first;
			if(dis[nextNode] < dis[node] * (graph[node][i]).second){
				q.push(nextNode);
				dis[nextNode] = dis[node] * (graph[node][i]).second;
			}
		}
	}
	return dis[d] * 100;
}
int main(){
	int n, m, x, y;
	double cost;
	pair<int, int> tmpPair;
	while(true){
		cin>>n;
		if(n == 0)
			break;
		cin>>m;
		graph.clear();
		graph.resize(n);
		dis.clear();
		dis.resize(n);
		for(int i=0;i<m;i++){
			cin>>x>>y>>cost;
			x--;
			y--;
			graph[y].push_back(make_pair(x, cost / 100));
			graph[x].push_back(make_pair(y, cost / 100));
		}
		//display();
		double ans = dijkstra(0, n-1);
		printf("%.6lf percent\n", ans);
	}
	return 0;
} 