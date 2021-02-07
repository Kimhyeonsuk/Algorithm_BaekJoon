#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int W, H, G, E;

int map[901];
vector<pair<int,int>>vec[901];
int dist[901];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	while (1) {
		
		memset(map, 0, sizeof(map));

		cin >> W >> H;
		if (W == 0 && H == 0)
			break;
		cin >> G;

		for (int i = 0; i < G; i++) {
			int x, y;
			cin >> x >> y;
			map[y * W + x] = 1;
		}

		for (int i = 0; i < 901; i++) {

			dist[i] = 1e9;
			vec[i].clear();
		}


		cin >> E;
		for (int i = 0; i < E; i++) {
			int x1, y1, x2, y2, t;
			cin >> x1 >> y1 >> x2 >> y2 >> t;
			vec[y1 * W + x1].push_back({ y2 * W + x2,t });
		}

		for (int x = 0; x < W; x++) {
			for (int y = 0; y < H; y++){
				if (map[y * W + x] == 1)
					continue;
				if (!vec[y * W + x].empty())
					continue;
				if (y * W + x == H * W - 1)
					continue;
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx < 0 || ny < 0 || nx >= W || ny >= H)continue;
					if (map[ny * W + nx] == 1)continue;

					vec[y * W + x].push_back({ ny * W + nx,1 });
				}
			}
		}

		

		dist[0] = 0;
		bool loop = false;
		for (int i = 0; i < H * W; i++) {
			for (int j = 0; j < H * W; j++) {
				int s = vec[j].size();
				for (int k = 0; k < s; k++) {
					int next = vec[j][k].first;
					int cost = vec[j][k].second;

					if (dist[j] != 1e9 && dist[next] > dist[j] + cost) {
						dist[next] = dist[j] + cost;
						if (i == H * W - 1)
							loop = true;
					}
				}
			}
		}
		


		if (loop)
			cout << "Never\n";
		else if (dist[H * W - 1] == 1e9)
			cout << "Impossible\n";
		else
			cout << dist[H * W - 1] << "\n";
	
	}

	return 0;
}