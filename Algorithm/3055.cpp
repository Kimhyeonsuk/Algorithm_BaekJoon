#include <iostream>
#include <queue>
using namespace std;
#define KAKTUS "KAKTUS";
int R, C;
char map[51][51];
bool chk[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct homi {
	int x;
	int y;
	int cnt;
};
queue<homi>q;
queue<pair<int, int>>waterq;
int res = 0;

void waterMove() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '*')
				waterq.push({ i,j });
		}
	}

	while (!waterq.empty()) {
		int tx = waterq.front().first;
		int ty = waterq.front().second;
		waterq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C)continue;
			if (map[nx][ny] == 'X'||map[nx][ny]=='D'||map[nx][ny]=='*')continue;
			map[nx][ny] = '*';
		}
	}
}
void bfs() {
	int curcnt = 0;
	while (!q.empty()) {
		int tx = q.front().x;
		int ty = q.front().y;
		int tcnt = q.front().cnt;
		if (curcnt < tcnt) {
			waterMove();
			curcnt = tcnt;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C)continue;
			if ((chk[nx][ny]) || (map[nx][ny] == '*') || (map[nx][ny] == 'X'))continue;
			if (map[nx][ny] == 'D') {
				res = tcnt + 1;
				return;
			}
			chk[nx][ny] = true;
			q.push({ nx,ny,tcnt + 1 });
		}
	}
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> R >> C;


	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				q.push({ i,j ,0 });
				chk[i][j] = true;
			}
			else if (map[i][j] == '*')
				waterq.push({ i,j });
		}
	}
	
	waterMove();
	bfs();
	if (res == 0) {
		cout << KAKTUS;
		cout << "\n";
	}
	else {
		cout << res << "\n";
	}


	return 0;
}