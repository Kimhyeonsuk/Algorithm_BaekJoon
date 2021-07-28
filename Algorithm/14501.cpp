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
//		//i번째 날에 일을 한경우
//		if (i + T[i] <= n + 1) {
//			dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
//			result = max(result, dp[i + T[i]]);
//		}
//		dp[i + 1] = max(dp[i + 1], dp[i]);
//		result = max(result, dp[i + 1]);
//	}
//	cout << result << "\n";
//}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int N;
//int T[16];
//int P[16];
//int main() {
//	cin.tie(NULL);
//	std::ios::sync_with_stdio(false);
//	cin >> N;
//	for (int i = 1; i <= N; i++) {
//		cin >> T[i];
//		cin >> P[i];
//	}
//
//	vector<int>dp(N+1, 0);
//
//	int res = 0;
//	for (int i = 1; i <= N; i++) {
//
//		if (i + T[i] <= N + 1) {
//			dp[i + T[i]] = max(dp[i + T[i]], dp[i] + T[i]);
//			res = max(res, dp[i + T[i]]);
//		}
//	}
//
//
//	cout << res << "\n";
//
//	return 0;
//}

#include <iostream>
#include <algorithm>
using namespace std;
int t[17];
int p[17];
int dp[17];
int n,day;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tval,pval;
		cin >> tval >> pval;
		t[i + 1] = tval;
		p[i + 1] = pval;
	}
	day = 0;
	for (int i = 1; i <= n; i++) {
		if (i + t[i] <= n + 1) {
			dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
		}
		if (i + 1 <= n + 1) {
			dp[i + 1] = max(dp[i + 1], dp[i]);
		}
	}

	int res = dp[n + 1];
	cout << res << endl;
}