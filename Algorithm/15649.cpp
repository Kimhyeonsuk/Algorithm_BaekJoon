#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int>vec;
void solve(int cnt, int val,vector<bool>&chk) {
	
	if (cnt == M) {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (val == i)
			continue;
		if (chk[i-1] == true)
			continue;
		vec.push_back(i);
		chk[i-1] = true;
		solve(cnt + 1, i,chk);
		vec.pop_back();
		chk[i-1] = false;
	}
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;
	vector<bool>chk(N, false);
	solve(0, 0,chk);
	return 0;
}