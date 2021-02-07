#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#define INF 987654321
using namespace std;
int N, M, A, B;

long long dist[101];
int getM[101];//해당 도시에 도착시 벌수 있는 돈
vector<pair<int, int>>vec[101];
int main() {
	cin >> N >> A >> B >> M;

	for (int i = 0; i < M; i++) {//인접 cost 저장
		int from, to, val;
		cin >> from >> to >> val;
		vec[from].push_back({ to,val });
	}
	
	for (int i = 0; i < N; i++) {//dist초기화, 각 도시에 도착시 벌수있는동 저장.
		dist[i] = -INF;
		int val;
		cin >> val;
		getM[i] = val;
	}
	dist[A] = getM[A];
	queue<int>q;
	bool visit[101] = { false, };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int s = vec[j].size();
			for (int k = 0; k < s; k++) {
				int next = vec[j][k].first;
				int cost = vec[j][k].second;

				if (dist[j] != -INF && (dist[next] < dist[j] + getM[next] - cost)) {
					dist[next] = dist[j] + getM[next] - cost;
					if (i == N - 1) {
						visit[j] = true;
						q.push(j);
					}
				}

			}
		}
	}
	bool chk = false;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (here == B)
		{
			chk = true;
			break;
		}
		int s = vec[here].size();
		for (int i = 0; i < s; i++) {
			int next = vec[here][i].first;
			if (visit[next])continue;
			visit[next] = true;
			q.push(next);
		}
	}


	if (dist[B] == -INF)
		cout << "gg\n";
	else if (chk)
		cout << "Gee\n";
	else
		cout << dist[B];
	

	return 0;
}