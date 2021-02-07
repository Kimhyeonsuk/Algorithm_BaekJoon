#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int dp[1001];
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i + 1];
	}
	dp[0] = 1;
	dp[1] = 1;
	int f = 1;
	for (int i = 2; i <= n; i++) {
		int val = arr[i];
		int res = 0;
		int resindex = 0;
		for (int j = i-1; j >= 1; j--) {
			int val2 = arr[j];
			if (val2 > val)continue;
			if (dp[j] > res) {
				resindex = j;
				res = dp[j];
			}
		}

		if (res == 0)
			dp[i] = 1;
		else if (arr[resindex] == arr[i]) {
			dp[i] = dp[resindex];
		}
		else
			dp[i] = dp[resindex] + 1;


		f = max(f, dp[i]);
	}

	cout << f<<"\n";

	return 0;
}