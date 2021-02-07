#include <iostream>
#include <queue>
using namespace std;
int N, K;
int dist[100001];
priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
vector<pair<int, int>>vec[100001];
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < 100001; i++) {
		int back = i - 1;
		int front = i + 1;
		int jump = i * 2;

		if (back >= 0)
			vec[i].push_back({ back,1 });
		if (front <= 100000)
			vec[i].push_back({ front,1 });
		if (jump <= 100000)
			vec[i].push_back({ jump,0 });
		dist[i] = 1e9;
	}
	dist[N] = 0;
	pq.push({ 0,N });
	while (!pq.empty()) {
		int here = pq.top().second;
		int cTime = pq.top().first;

		pq.pop();
		int s = vec[here].size();
		for (int i = 0; i < s; i++) {
			int next = vec[here][i].first;
			int cost = vec[here][i].second;
			if (dist[next] > cTime + cost) {
				dist[next] = cTime + cost;
				pq.push({ cTime + cost,next });
			}
		}
	}
	cout << dist[K] << "\n";
	return 0;
}