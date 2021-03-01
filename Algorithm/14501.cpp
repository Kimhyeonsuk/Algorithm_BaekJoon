//#include <iostream>
//#include <algorithm>
//using namespace std;
//int T[1001];
//int P[1001];
//int dp[1001];
//int main() {
//	cin.tie(NULL);
//	std::ios::sync_with_stdio(false);
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cin >> T[i];
//		cin >> P[i];
//	}
//	int result = 0;
//	for (int i = 1; i <= n; i++) {
//		//i��° ���� ���� �Ѱ��
//		if (i + T[i] <= n + 1) {
//			dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
//			result = max(result, dp[i + T[i]]);
//		}
//		dp[i + 1] = max(dp[i + 1], dp[i]);
//		result = max(result, dp[i + 1]);
//	}
//	cout << result << "\n";
//}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int T[16];
int P[16];
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i];
		cin >> P[i];
	}

	vector<int>dp(N+1, 0);

	int res = 0;
	for (int i = 1; i <= N; i++) {

		if (i + T[i] <= N + 1) {
			dp[i + T[i]] = max(dp[i + T[i]], dp[i] + T[i]);
			res = max(res, dp[i + T[i]]);
		}
	}


	cout << res << "\n";

	return 0;
}