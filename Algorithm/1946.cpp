#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int T, N;


bool comp(pair<int, int>a, pair<int, int>b) {
	return a.first < b.first;
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> T;
	while (T--) {
		cin >> N;
		vector<pair<int, int>>applicants;
		for (int i = 0; i < N; i++) {
			int pScore, mScore;//paper score, meet score
			cin >> pScore >> mScore;
			applicants.push_back({ pScore,mScore });
		}

		sort(applicants.begin(), applicants.end(), comp);
		int res = 1;
		int tmp = applicants[0].second;
		for (int i = 1; i < applicants.size(); i++) {
			if (applicants[i].second > tmp)
				continue;
			tmp = applicants[i].second;
			res++;
		}


		cout << res << "\n";
	}
	return 0;
}