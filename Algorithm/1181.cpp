#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int N;
vector<string>vec;
set<string>stringList;
bool comp(string a, string b) {
	if (a.size() == b.size()) {
		return a < b;
	}
	return a.size() < b.size();
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		vec.push_back(s);
	}
	sort(vec.begin(), vec.end(), comp);
	
	string tmp = "";
	for (int i = 0; i < vec.size(); i++) {
		if (tmp == vec[i])
			continue;
		cout << vec[i] << "\n";
		tmp = vec[i];
	}
	return 0;
}