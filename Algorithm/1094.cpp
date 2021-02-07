#include <iostream>
using namespace std;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int cnt = 0;
	while (n != 0) {
		if (n % 2 == 1) {
			cnt++;
		}
		n /= 2;
	}
	cout << cnt << "\n";
	return 0;
}