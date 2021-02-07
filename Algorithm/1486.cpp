#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int map[700];
int fw[700][700];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int N, M,T,D;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);


	cin >> N >> M;
	cin >> T >> D;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			char h;
			cin >> h;
			if (h >= 'A' && h <= 'Z') {
				map[i * M + j] = h-'A';
			}
			else {
				map[i * M + j] = (h - 'a')+26;
			}
		}
	}
	for (int i = 0; i < N * M; i++) {
		for (int j = 0; j < N * M; j++) {
			if (i == j)
				fw[i][j] = 0;
			else
				fw[i][j] = 1e9;
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
		{
			int height = map[i * M + j];
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M)continue;
				int nHeight = map[nx * M + ny];

				if (abs(height - nHeight) > T) {
					continue;
				}
				else if (height >= nHeight) {
					fw[i * M + j][nx * M + ny] = 1;
				}
				else {
					int differ = nHeight - height;
					differ *= differ;
					fw[i * M + j][nx * M + ny] = differ;
				}
			}
		}
	}
	


	for (int cnt = 0; cnt < N * M; cnt++) {
		for (int i = 0; i < N*M; i++) {
			for (int j = 0; j < N*M; j++) {
				fw[i][j] = min(fw[i][j], fw[i][cnt] + fw[cnt][j]);
			}
		}
	}

	


	int maxval =map[0];
	int dest = 0;;
	for (int i = 0; i < N * M; i++) {
		int time = fw[0][i];
		time += fw[i][0];
		if (time <= D) {
			if (maxval < map[i]) {
				maxval = map[i];
			}
		}
	}

	cout << maxval << "\n";
	return 0;
}