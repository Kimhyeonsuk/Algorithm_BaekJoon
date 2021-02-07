#include <iostream>
#include <algorithm>
using namespace std;
int T[1001];
int P[1001];
int dp[1001];
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> T[i];
		cin >> P[i];
	}
	int result = 0;
	for (int i = 1; i <= n; i++) {
		//i번째 날에 일을 한경우
		if (i + T[i] <= n + 1) {
			dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
			result = max(result, dp[i + T[i]]);
		}
		dp[i + 1] = max(dp[i + 1], dp[i]);
		result = max(result, dp[i + 1]);
	}
	cout << result << "\n";
}