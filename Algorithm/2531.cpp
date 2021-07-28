#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n, d, k, c;
map<int, int>tmpmap;
vector<int>sushi;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sushi.push_back(x);
		if (i < k) {
			if (tmpmap.find(x) != tmpmap.end()) {
				tmpmap[x] += 1;
			}
			else {
				tmpmap.insert({ x,1 });
			}
		}
		
	}

	int res;
	if (tmpmap.find(c) != tmpmap.end()) {
		res = tmpmap.size();
	}
	else
		res = tmpmap.size() + 1;
	for (int i = 1; i < sushi.size(); i++)
	{
		if (tmpmap[sushi[i - 1]] == 1) {
			tmpmap.erase(sushi[i - 1]);
		}
		else {
			tmpmap[sushi[i - 1]] -= 1;
		}

		if (i + k > sushi.size()) {
			int next = ((i + k) % sushi.size()) - 1;
			if (tmpmap.find(sushi[next]) != tmpmap.end()) {
				tmpmap[sushi[next]] += 1;
			}
			else {
				tmpmap.insert({ sushi[next], 1 });
			}
		}
		else {
			if (tmpmap.find(sushi[i + k - 1]) != tmpmap.end()) {
				tmpmap[sushi[i + k - 1]] += 1;
			}
			else {
				tmpmap.insert({ sushi[i + k - 1], 1 });
			}
		}
		int tmps = tmpmap.size();
		if (tmpmap.find(c) != tmpmap.end()) {
			res = max(res, tmps);
		}
		else
			res =max(res, tmps+1);
	}
	cout << res << "\n";
	return 0;
}