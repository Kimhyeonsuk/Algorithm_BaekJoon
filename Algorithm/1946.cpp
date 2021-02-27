#include<iostream>
#include <vector>
using namespace std;
int T, N;

vector<pair<int, int>>applicants;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			int pScore, mScore;//paper score, meet score
			cin >> pScore >> mScore;
			applicants.push_back({ pScore,mScore });
		}
	}
	return 0;
}