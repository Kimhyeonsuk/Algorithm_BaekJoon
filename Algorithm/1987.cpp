#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<bool>checkAlp(28, false);
int R, C;
int res = 0;
void dfs(int x,int y,vector<vector<char>>& map,vector<vector<bool>>&visit,int cnt) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= R || ny >= C)continue;
		if (visit[nx][ny])continue;
		if (checkAlp[map[nx][ny] - 'A'])continue;

		checkAlp[map[nx][ny] - 'A'] = true;
		visit[nx][ny] = true;
		res = max(res, cnt + 1);
		dfs(nx, ny, map, visit,cnt+1);
		visit[nx][ny] = false;
		checkAlp[map[nx][ny] - 'A'] = false;
	}
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> R >> C;
	vector<vector<char>>map(R, vector<char>(C, 'A'));
	vector<vector<bool>>visit(R, vector<bool>(C, false));
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j] = s[j];
		}
	}
	res = 1;
	visit[0][0] = true;
	checkAlp[map[0][0]-'A'] = true;
	dfs(0, 0,map,visit,1);
	
	cout << res << "\n";
	return 0;
}