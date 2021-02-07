#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dp[1001][3];
int home[1001][3];
int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> home[i][0] >> home[i][1] >> home[i][2];
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    dp[1][0] = home[1][0];
    dp[1][1] = home[1][1];
    dp[1][2] = home[1][2];

    for (int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + home[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + home[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + home[i][2];
    }

    int result = min(dp[n][0], dp[n][1]);
    cout << min(result, dp[n][2]);

    return 0;
}