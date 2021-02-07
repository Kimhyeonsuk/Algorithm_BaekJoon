#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, Q;
pair<int,int> dog[501];
int dist[501][501];
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> dog[i].first;
		dog[i].second = i;
	}
	sort(dog + 1, dog + N + 1);
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			if (i == j) {
				dist[i][j] = 0;
				continue;
			}
			dist[i][j] = 1e9;
		}
	}

	for (int i = 0; i < M; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		dist[from][to] = val;
		dist[to][from] = val;
	}

	int map[501][501];
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			map[i][j] = dist[i][j];
		}
	}



	for (int cnt = 1; cnt <= N; cnt++) {
		int k = dog[cnt].second;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (k == i || j == k) {
					map[i][j] = dist[i][k] + dist[k][j] + dog[cnt].first;
				}
				else {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
					map[i][j] = min(map[i][j], dist[i][k] + dist[k][j] + dog[cnt].first);
				}
			}
		}
	}


	for (int q = 0; q < Q; q++) {
		int S, T;
		cin >> S >> T;

		if (dist[S][T] != 1e9) {
			cout << map[S][T] << "\n";
		}
		else
			cout << -1 << "\n";
	}
}