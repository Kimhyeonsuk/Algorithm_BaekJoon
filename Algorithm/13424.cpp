#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int T, N, M, K;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		vector<pair<int,int>> vec[101];
		vector<int>roomvec;
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int s, d, c;
			cin >> s >> d >> c;
			vec[s].push_back({ d,c });
			vec[d].push_back({ s,c });
		}
		cin >> K;
		for (int i = 0; i < K; i++) {
			int room;
			cin >> room;
			roomvec.push_back(room);
		}

		int distsum[101] = { 0, };
		int roomsize = roomvec.size();
		for (int i = 0; i < roomsize; i++) {
			priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
			int dist[101];
			for (int j = 0; j <= N; j++) {
				dist[j] = 1e9;
			}
			dist[roomvec[i]] = 0;
			pq.push({ 0,roomvec[i] });

			while (!pq.empty()) {
				int dcost = pq.top().first;
				int here = pq.top().second;
				pq.pop();
				for (int j = 0; j < vec[here].size(); j++) {
					if (dist[vec[here][j].first] > dcost + vec[here][j].second) {
						dist[vec[here][j].first] = dcost + vec[here][j].second;
						pq.push({ dcost + vec[here][j].second,vec[here][j].first });
					}
				}
			}
			for (int j = 1; j <= N; j++) {
				distsum[j] += dist[j];
			}
		}

		int res = 1e9;
		int resroom;
		for (int i = 1; i <= N; i++) {
			if (distsum[i] < res) {
				res = distsum[i];
				resroom = i;
			}
		}
		cout << resroom << "\n";
	}
	return 0;
}