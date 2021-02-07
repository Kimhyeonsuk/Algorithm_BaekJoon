#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001];
int arr[101];
int n, k;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= k; i++) {
		dp[i] = 10000000;
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (arr[i] <= j) {
				dp[j] = min(dp[j], dp[j-arr[i]]+1);
			}
		}
	}

	if (dp[k] == 10000000)
		cout << -1 << "\n";
	else
		cout << dp[k] << "\n";

}