#include <iostream>
#include <algorithm>
using namespace std;
int arr[10010];
int dp[10010];

int n;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int res = 0;
	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = arr[i] + max(dp[i - 2], arr[i - 1] + dp[i - 3]);
		dp[i] = max(dp[i], dp[i - 1]);
	}

	cout << dp[n] ;
}