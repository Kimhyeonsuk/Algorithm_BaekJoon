#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, minval,maxval;
vector<int>vec;
int op[4];
void dfs(int idx,int value) {
	if (idx == vec.size()) {
		minval = min(minval, value);
		maxval = max(maxval, value);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] == 0)continue;
		op[i] -= 1;
		if (i == 0) {
			dfs(idx + 1, value + vec[idx]);
		}
		else if (i == 1) {
			dfs(idx + 1, value - vec[idx]);

		}
		else if (i == 2) {
			dfs(idx + 1, value * vec[idx]);

		}
		else if (i == 3) {
			dfs(idx + 1, value / vec[idx]);

		}
		op[i] += 1;
	}
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	minval = 1e9;
	maxval = -1e9;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	dfs(1,vec[0]);
	cout << maxval << "\n";
	cout << minval << "\n";

	return 0;
}