#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dist[1001];
vector<pair<int, int>>vec[1001];
vector<int>road[1001];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int n, m,A,B;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, d, cost;
		cin >> s >> d >> cost;
		vec[s].push_back({ d,cost });
	}
	cin >> A >> B;

	for (int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}

	dist[A] = 0;
	pq.push({ 0,A });
	while (!pq.empty()) {
		int tCost = pq.top().first;
		int here = pq.top().second;
		pq.pop();

		int s = vec[here].size();
		for (int i = 0; i < s; i++) {
			int next = vec[here][i].first;
			int val = vec[here][i].second;

			if (dist[next] > val + tCost) {
				dist[next] = val + tCost;
				pq.push({ val + tCost,next });
				
				if (road[next].empty()) {
					road[next].push_back(here);
				}
				else {
					road[next][0] = here;
				}
			}

		}
	}

	vector<int>res;
	int val = B;
	res.push_back(B);
	while (1) {
		res.push_back(road[val][0]);
		if (road[val][0] == A)
			break;
		val = road[val][0];
	}

	cout << dist[B] << "\n";
	cout << res.size() << "\n";
	for (int i = res.size()-1; i>=0; i--) {
		cout << res[i] << " ";
	}
}