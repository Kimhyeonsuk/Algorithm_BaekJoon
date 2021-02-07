#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n, d, c;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> d >> c;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
		vector<pair<int,int>> vec[10001];
		int dist[10001];
		for (int i = 0; i <= n; i++)
			dist[i] = 1e9;
		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			vec[b].push_back({ a,s });
		}

		dist[c] = 0;
		pq.push({ 0,c });
		while (!pq.empty()) {
			int here = pq.top().second;
			int val = pq.top().first;
			pq.pop();
			int s = vec[here].size();
			for (int i = 0; i < s; i++) {
				int next = vec[here][i].first;
				int cost = vec[here][i].second;
				if (dist[next] > cost + val) {
					pq.push({ cost + val, next });
					dist[next] = cost + val;
				}
			}
		}


		int cnt = 0;
		int time = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] != 1e9) {
				cnt++;
				time = max(time, dist[i]);
			}
		}
		cout << cnt << " " << time << "\n";
	}
	return 0;
}