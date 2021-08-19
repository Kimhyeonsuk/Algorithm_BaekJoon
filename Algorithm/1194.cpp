#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
char map[51][51];
int chk[51][51][64];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int keys[6] = { 1,2,4,8,16,32 };
pair<int, int>minsik;
pair<int, int> exitDoor;
struct node {
	int x;
	int y;
	int key;
	int cnt;
};
int BFS() {
	queue<node>q;
	q.push({ minsik.first,minsik.second,0 ,0});
	chk[minsik.first][minsik.second][0] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int keyVal = q.front().key;
		int cntVal = q.front().cnt;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (map[nx][ny] == '1') {
					return  cntVal + 1;
				}
				else if (map[nx][ny] - 'a' >= 0 && map[nx][ny] - 'a' <= 5) {
					if (chk[nx][ny][keyVal] == false) {
						chk[nx][ny][keyVal] = true;
						int nextKeyVal;
						if ((keyVal & keys[map[nx][ny] - 'a']) == 0) {
							nextKeyVal = keyVal + keys[map[nx][ny] - 'a'];
						}
						else {
							nextKeyVal = keyVal;
						}
						q.push({ nx,ny,nextKeyVal,cntVal + 1 });
					}
				}
				else if (map[nx][ny] - 'A' >= 0 && map[nx][ny] - 'A' <= 5) {
					if ((keyVal & keys[map[nx][ny] - 'A']) != 0) {//문을 열 키가 있음
						if (chk[nx][ny][keyVal] == false) {
							chk[nx][ny][keyVal] = true;
							q.push({ nx,ny,keyVal,cntVal + 1 });
						}
					}
				}
				else if (map[nx][ny] == '.') {
					if (chk[nx][ny][keyVal] == false) {
						chk[nx][ny][keyVal] = true;
						q.push({ nx,ny,keyVal,cntVal + 1 });
					}
				}
				else if (map[nx][ny] == '#')
					continue;
			}
		}
	}
	return -1;
}
//빈곳 .
//별 #
//열쇠 a~f
//문 A~F
//현재 위치 
//출구 1

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				minsik = { i,j };
				map[i][j] = '.';
			}
			else if (map[i][j] == '1') {
				exitDoor = { i,j };
			}
		}
	}
	int res = BFS();
	cout << res << "\n";
	return 0;
}