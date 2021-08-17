#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m,low,high;
vector<int>vec;
bool canDivide(int blueray) {
	int maxsum = 0;
	int sum = 0;
	int cnt = 0;
	int i = 0;
	while (i < vec.size()) {
		if (sum + vec[i] <= blueray) {
			sum += vec[i];
			i++;
		}
		else {
			maxsum = max(maxsum, sum);
			sum = 0;
			cnt++;
			if (cnt > m)
				return 0;
		}
	}
	cnt++;
	if (cnt > m)
		return 0;
	return true;
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
		sum += x;
	}
	low = 0;
	high = sum;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (canDivide(mid)) {
			high= mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << low << "\n";
	return 0;
}