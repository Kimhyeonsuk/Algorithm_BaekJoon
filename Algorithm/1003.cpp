#include <iostream>
using namespace std;
int t;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		int d[41][2];
		int n;
		cin >> n;
		d[0][0] = 1;
		d[0][1] = 0;
		d[1][0] = 0;
		d[1][1] = 1;
		for (int i = 2; i <= n; i++) {
			d[i][0] = d[i - 1][0] + d[i - 2][0];
			d[i][1] = d[i - 1][1] + d[i - 2][1];

		}

		cout << d[n][0] << " " << d[n][1] << "\n";
	}
	return 0;
}