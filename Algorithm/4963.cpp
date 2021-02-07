#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int t, w, h;
int map[51][51];
bool chk[51][51];
int res = 0;
int dx[8] = { -1,0,0,1 ,-1,1,1,-1};
int dy[8] = { 0,-1,1,0 ,-1,-1,1,1};
queue<pair<int, int>>q;
void bfs() {
	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
			if (chk[nx][ny])continue;
			if (map[nx][ny] == 0)continue;
			chk[nx][ny] = true;
			q.push({ nx,ny });
		}
		
	}
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0)break;
		res = 0;
		memset(map, 0, sizeof(map));
		memset(chk, false, sizeof(chk));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j]==1&&!chk[i][j]) {
					q.push({ i,j });
					chk[i][j] = true;
					bfs();
					res++;
				}
			}
		}

		cout << res << "\n";
		
	}

	return 0;
}