#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int N;
int map[125][125];
int dist[15625];
vector<pair<int, int>>vec[15625];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int pcnt = 0;
	while (true) {
		pcnt++;
		cin >> N;
		if (N == 0)break;
		for (int i = 0; i < 15625; i++) {
			vec[i].clear();
			dist[i] = 1e9;
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < 4; k++) {
					int nx = dx[k] + i;
					int ny = dy[k] + j;
					if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;

					vec[i * N + j].push_back({ nx * N + ny , map[nx][ny] });
				}
			}
		}


		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
		pq.push({ map[0][0],0 });
		dist[0] = map[0][0];

		while (!pq.empty()) {
			int here = pq.top().second;
			int cost = pq.top().first;

			pq.pop();
			int s = vec[here].size();
			for (int i = 0; i < s; i++) {
				int nx = vec[here][i].first;
				int ncost = vec[here][i].second;

				if (dist[nx] > cost + ncost) {
					dist[nx] = cost + ncost;
					pq.push({ cost + ncost,nx });
				}
			}
		}

		cout <<"Problem "<<pcnt<<": "<< dist[N * N-1] << "\n";

	}
}