#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dist[300001];
vector<pair<int, int>>vec[300001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
int N, M, K, X, A, B;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M >> K >> X;
	for (int i = 0; i < M; i++) {

		int from, to;
		cin >> from >> to;
		vec[from].push_back({ to,1 });
	}
	for (int i = 1; i <= N; i++) {
		dist[i] = 1e9;
	}

	dist[X] = 0;
	pq.push({ 0,X });
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

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
			cnt++;
			cout << i << "\n";
		}
	}
	if (cnt == 0)
		cout << -1 << "\n";
	return 0;
}