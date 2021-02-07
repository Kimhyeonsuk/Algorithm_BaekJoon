#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dp[5001];
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n;

	dp[3] = 1;
	dp[5] = 1;

	for (int i = 6; i <= n; i++) {

		if (dp[i - 3] != 0) {
			dp[i] = dp[i - 3] + 1;
		}

		if (dp[i - 5] != 0) {
			if (dp[i] == 0)
				dp[i] = dp[i - 5] + 1;
			else
				dp[i] = min(dp[i], dp[i - 5] + 1);
			
		}
	}

	if (dp[n] == 0)
		cout << -1;
	else
		cout << dp[n] << "\n";
	return 0;
}