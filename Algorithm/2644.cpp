#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n,m;
int a, b;
vector<int>vec[101];
bool chk[101];
queue<pair<int,int>>q;
int res = 0;
bool fnd = false;
void bfs() {
	while (!q.empty()) {
		int tval = q.front().first;
		int cnt = q.front().second;
		q.pop();

		int s = vec[tval].size();
		for (int i = 0; i < s; i++) {
			int n = vec[tval][i];
			if (chk[n])continue;
			chk[n] = true;
			if (n == b) {
				res = cnt + 1;
				fnd = true;
				return;
			}
			q.push({ n,cnt + 1 });
		}
	}
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n;
	cin >> a >> b;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		vec[y].push_back(x);
		vec[x].push_back(y);
	}
	chk[a] = true;
	q.push({ a,0 });
	bfs();
	if (!fnd) {
		cout << -1 << "\n";
	}
	else
		cout << res << "\n";
	return 0;
}