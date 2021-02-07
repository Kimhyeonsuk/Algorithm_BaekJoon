#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
int n, m, k;
vector<pair<int, int>>vec[1001];
priority_queue<int> dist[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		vec[from].push_back({ to,val });
	}
	
	pq.push({ 0,1 });
	dist[1].push(0);
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = pq.top().first;
		//cout << here << "<" << cost << "\n";
		pq.pop();
		int s = vec[here].size();
		for (int i = 0; i < s; i++) {
			int next = vec[here][i].first;
			int ncost = vec[here][i].second;

			if (dist[next].size() < k) {
				dist[next].push(ncost + cost );
				pq.push({ ncost + cost,next });
			}
			else if(dist[next].top()>ncost+cost){
				dist[next].pop();
				dist[next].push( ncost + cost );
				pq.push({ ncost + cost,next });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i].size() < k) {
			cout << -1 << "\n";
			continue;
		}
			
		cout << dist[i].top() << "\n";
	}
}