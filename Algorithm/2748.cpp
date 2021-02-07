#include <iostream>
using namespace std;
int n;
long long dp[101];
int main() {
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    cout << dp[n] << "\n";
    return 0;
}