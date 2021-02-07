#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, k, s, d;
struct info {
	int val, loc, cnt;//해당 위치까지의 통행료
	//int loc;//위치
	//int cnt;//세금이 몇번재 인상되어있는지
};
bool operator<(info a, info b) {
	return a.val < b.val;
}
vector<pair<int, int>>vec[1001];
priority_queue < info>q;
int dist[1001][1001];


int tax[30001];
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	cin >> s >> d;
	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		vec[a].push_back({ b,w });
		vec[b].push_back({ a,w });
	}
	for (int i = 1; i <= k; i++) {
		int a;
		cin >> a;
		tax[i] = a + tax[i - 1];
	}

	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++)
			dist[i][j] = 1e9;
	

	dist[0][s] = 0;
	q.push({ 0,s,0 });
	
	while (!q.empty()) {
		int here = q.top().loc;
		int val = q.top().val;
		int taxcnt = q.top().cnt;
		q.pop();
		int s = vec[here].size();
		for (int i = 0; i < s; i++) {
			int next = vec[here][i].first;
			int cost = vec[here][i].second;

			int minval = 1e9;
			for (int i = 0; i <= taxcnt; i++) {
				minval = min(minval, dist[i][next]);
			}

			if (minval > cost + val) {
				if (dist[taxcnt + 1][next] >= cost + val) {
					dist[taxcnt + 1][next] = cost + val;
					q.push({ cost + val,next,taxcnt + 1 });
				}
			}
		}
	}

	for (int i = 0; i <= k; i++) {
		int minval = 1e9;
		for (int j = 1; j <= n; j++) {
			int val = dist[j][d];
			minval = min(minval, val+tax[i]*j);
		}
		cout << minval << "\n";
	}
	return 0;
}