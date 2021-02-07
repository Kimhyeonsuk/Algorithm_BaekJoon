#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
long long arr[4][4001];
vector<long long > v;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[j][i];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v.push_back(arr[2][i] + arr[3][j]);
		}
	}

	sort(v.begin(), v.end());

	long long res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			long long val = arr[0][i] + arr[1][j];

			long long low = lower_bound(v.begin(), v.end(), -val) - v.begin();
			long long upper = upper_bound(v.begin(), v.end(), -val) - v.begin();

			if (-val == v[low])
				res += upper - low;
		}
	}

	cout << res << "\n";

}