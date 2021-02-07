#include <iostream>
#include <algorithm>
using namespace std;
int box[1001];
int dp[1001];

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> box[i];


	int res = 0;
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		int val = box[i];
		for (int j = 0; j < i; j++) {
			if (box[j] < val&&dp[j]+1>dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
		res = max(res, dp[i]);
	}

	cout << res << "\n";

}