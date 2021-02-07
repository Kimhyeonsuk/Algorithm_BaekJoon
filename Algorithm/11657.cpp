#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int N, M;
long long dist[501];
vector<pair<int, int>>vec[501];
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);


	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to, val;
		cin >> from >> to >> val;
		vec[from].push_back({ to,val });
	}


	for (int i = 0; i <= N; i++) {
		dist[i] = 1e9;
	}

	dist[1] = 0;

	bool loop = false;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int s = vec[j].size();

			for (int k = 0; k < s; k++) {
				int next = vec[j][k].first;
				long long cost = vec[j][k].second;

				if (dist[j] != 1e9 && dist[next] > dist[j] + cost) {
					dist[next] = dist[j] + cost;
					if (i == N) {
						loop = true;
					}
				}
			}
		}
	}

	
	if (loop) {
		cout << -1 << "\n";
	}
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == 1e9)
				cout << -1 << "\n";
			else
				cout << dist[i] << "\n";
		}
	}
	return 0;
}