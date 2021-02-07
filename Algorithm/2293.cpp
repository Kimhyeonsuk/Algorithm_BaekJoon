#include <iostream>
using namespace std;
int coins[101];
int dp[10001];
int n, k;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coins[i];
	}

	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j < coins[i])continue;
			dp[j] += dp[j - coins[i]];
		}
	}


	cout << dp[k];
}