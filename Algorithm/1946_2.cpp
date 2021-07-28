#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int t, n;
bool comp(pair<int, int>a, pair<int, int>b) {
	return a.first < b.first;
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> n;
		vector<pair<int, int>>vec;
		int newNum = 1;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			vec.push_back({ x,y });
		}
		sort(vec.begin(), vec.end(), comp);
		int s = vec.size();
		int minrank = vec[0].second;
		for (int j = 1; j < s; j++) {
			if (vec[j].second > minrank) {
				continue;
			}
			else {
				minrank = vec[j].second;
				newNum++;
			}
		}
		cout << newNum << "\n";
	}
	return 0;
}