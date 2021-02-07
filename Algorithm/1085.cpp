#include <iostream>
#include <algorithm>
using namespace std;
int x, y, z, w, h;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> x >> y >> w >> h;

	int res = min(x, y);
	res = min(res, w - x);
	res = min(res, h - y);

	cout << res << "\n";
}