#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>>vec[20001];
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
int V, E,K;
int dist[20001];
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> V >> E;
	cin >> K;

	for (int i = 0; i < E; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		vec[from].push_back({ to,val });
	}

	for (int i = 1; i <= V; i++) {
		dist[i] = 1e9;
	}

	dist[K] = 0;
	pq.push({ 0,K });

	while (!pq.empty()) {
		int here = pq.top().second;
		int val = pq.top().first;
		pq.pop();
		int s = vec[here].size();
		for (int i = 0; i < s; i++) {
			int next = vec[here][i].first;
			int cost = vec[here][i].second;

			if (dist[next] > cost + val) {
				dist[next] = cost + val;
				pq.push({ cost + val,next });
			}
		}

	}


	for (int i = 1; i <= V; i++) {
		if (dist[i] != 1e9) {
			cout << dist[i] << "\n";
		}
		else
			cout << "INF\n";
	}

	return 0;
}