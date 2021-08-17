#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K;
int dp[101][101];
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N >> M >> K;

	vector<int>vec;
	dp[0][0];
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (i == 0 && j == 0) {
				dp[i][j] = 0;
			}
			else if (i == 0 || j == 0) {
				dp[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			if (dp[i][j] > 1000000000) {
				dp[i][j] = 1000000000;
			}
		}
	}

	if (dp[N][M] < K) {
		cout << -1 << "\n";
		return 0;
	}

	int a_cnt = N;
	int z_cnt = M;
	for (int i = 0; i < N + M; i++) {
		int a_start = dp[a_cnt - 1][z_cnt];
		int z_start = dp[a_cnt][z_cnt - 1];

		if (a_cnt == 0) {
			cout << "z";
			z_cnt--;
			continue;
		}
		else if (z_cnt == 0) {
			cout << "a";
			a_cnt--;
			continue;
		}

		if (K <= a_start) {
			cout << "a";
			a_cnt--;
		}
		else {
			K = K - a_start;
			cout << 'z';
			z_cnt--;
		}

	}
	return 0;
}