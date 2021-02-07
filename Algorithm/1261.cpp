#include <iostream>
#include <vector>
#include <queue>
#include<tuple>
#include <algorithm>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int dist[101][101];
char map[101][101];
struct node {
	int x;
	int y;
};
typedef tuple<int, int, int> P;

priority_queue < P, vector <P>,greater<P> >pq;
int N, M;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> M >> N;

	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
			dist[i][j] = 1e9;
		}
	}
	
	dist[1][1] = 0;
	pq.push({ 0,1,1 });
	while (!pq.empty()) {
		int hx, hy, cost;
		tie(cost,hx, hy) = pq.top();
		//cout << hx << "," << hy << "cost: "<<cost<<"\n";
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = hx + dx[i];
			int ny = hy + dy[i];
			if (nx <= 0 || ny <= 0 || nx > N || ny > M)continue;
			if (map[nx][ny] == '1') {
				if (dist[nx][ny] > 1 + cost) {
					dist[nx][ny] = 1 + cost;
					pq.push({ 1 + cost,nx,ny });
				}
			}
			else {
				if (dist[nx][ny] > cost) {
					dist[nx][ny] = cost;
					pq.push({ cost,nx,ny });
				}
			}
			
			
		}
	}

	cout << dist[N][M] << "\n";
	return 0;
}