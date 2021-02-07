#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int tc, N, M, W;

int dist[501];
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> tc;
	while (tc--) {
		vector<pair<int, int>>vec[501];
		cin >> N >> M >> W;
		for (int i = 0; i < M; i++) {
			int from, to, val;
			cin >> from >> to >> val;
			vec[from].push_back({ to,val });
			vec[to].push_back({ from,val });
		}
		for (int i = 0; i < W; i++) {
			int from, to, val;
			cin >> from >> to >> val;
			vec[from].push_back({ to, -val });
		}

		memset(dist, 2 * 1e9, sizeof(dist));
		dist[1] = 0;
		bool loop = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int s = vec[j].size();
				for (int k = 0; k < s; k++) {
					int next = vec[j][k].first;
					int cost = vec[j][k].second;
					if (dist[next] > cost + dist[j]) {
						dist[next] = cost + dist[j];
						if (i == N)
							loop = true;
					}
				}
			}
		}
		
		if (loop) {
			cout << "YES\n";
		}
		else
			cout << "NO\n";

		
		
	}
	
	return 0;
}