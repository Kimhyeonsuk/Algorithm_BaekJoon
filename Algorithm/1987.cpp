#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int R, C;
char map[21][21];
bool chk[21][21];
int dx[4] = { -1,1,0,0 };
int dy[4]={ 0,0,-1,1 };
struct horse {
	int x;
	int y;
	int cnt;
	bool *alpha;
};
queue<horse>q;
int res;
void bfs() {
	while (!q.empty()) {
		int tx = q.front().x;
		int ty = q.front().y;
		int cnt = q.front().cnt;
		bool* talpah = q.front().alpha;

		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C)continue;
			if (chk[nx][ny])continue;
			if (talpah[map[nx][ny] - 'A'])continue;
			chk[nx][ny] = true;
			talpah[map[nx][ny] - 'A'] = true;

			bool tmparr[28];
			res = max(res, cnt + 1);
			for (int i = 0; i < 28; i++)
				tmparr[i] = talpah[i];
			q.push({ nx,ny,cnt+1,tmparr });
		}
	}
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	res = 0;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> map[i];
	}

	bool al[28] = { false, };
	al[map[0][0] - 'A'] = true;
	q.push({ 0, 0, 1, al });
	bfs();
	cout << res << "\n";
	return 0; 
}