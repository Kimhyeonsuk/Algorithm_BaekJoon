#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int V, E, m1,m2;
vector<pair<int, int>>vec[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int dist[801];
void init() {
	for (int i = 0; i <= V; i++) {
		dist[i] = 1e9;
	}
}
int solve(int start, int dest, int val) {
	init();
	pq.push({ val, start });
	dist[start] = val;
	if (start == dest)
		return val;
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = pq.top().first;

		pq.pop();
		int s = vec[here].size();
		for (int i = 0; i < s; i++) {
			int next = vec[here][i].first;
			int ncost = vec[here][i].second;

			if (dist[next] > ncost + cost) {
				dist[next] = cost + ncost;
				if (next != dest) {

					pq.push({ cost + ncost, next });
				}
			}
		}
	}

	return dist[dest];

}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		vec[from].push_back({ to,val });
		vec[to].push_back({ from,val });
	}
	cin >> m1 >> m2;
	int case1, case2;
	case1 = 0;
	case2 = 0;


	int n1 = solve(1, m1, 0);
	if (dist[m1] == 1e9)
	{
		case1=-1;
	}
	int n2 = solve(m1, m2, dist[m1]);
	if (dist[m2] == 1e9) {
		case1 = -1;
	}
	int n3 = solve(m2, V, dist[m2]);
	if (dist[V] == 1e9) {
		case1 = -1;
	}


	n1 = solve(1, m2, 0);
	if (dist[m2] == 1e9)
	{
		case2 = -1;
	}
	n2 = solve(m2, m1, dist[m2]);
	if (dist[m1] == 1e9) {
		case2 = -1;
	}
	int last = solve(m1, V, dist[m1]);
	if (dist[V] == 1e9) {
		case2 = -1;
	}


	if (case1 == -1 && case2 == -1) {
		cout << -1;
	}
	else
		cout << min(n3, last);

	return 0;
}