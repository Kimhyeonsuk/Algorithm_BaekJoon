#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n, d, k, c, res;
map<int, int>sushiList;
vector<int>sushi;
void chkeckSushiList() {//쿠폰과 맵의 정보를 확인하여 값 도출
	int tmpsize = sushiList.size();
	if (sushiList.find(c) != sushiList.end()) {
		res = max(res,tmpsize);
	}
	else
		res = max(res, tmpsize + 1);
}
void eraseSushi(int idx) {//윈도우를 이동시킴에따라 이전의 초밥의 정보를 맵에서 갱신
	if (sushiList[sushi[idx - 1]] == 1) {
		sushiList.erase(sushi[idx - 1]);
	}
	else {
		sushiList[sushi[idx - 1]] -= 1;
	}
}
void addSushi(int idx) {
	if (idx > sushi.size()) {//이동시킨 윈도우의 마지막 인덱스가 배열의 사이즈를 벗어나 0번 인덱스부터 다시 포함시켜야 하는 경우
		idx = ((idx) % sushi.size()) ;//돌았을때 인덱스 찾기
	}
	if (sushiList.find(sushi[idx - 1]) != sushiList.end()) {
		sushiList[sushi[idx - 1]] += 1;
	}
	else {
		sushiList.insert({ sushi[idx - 1], 1 });
	}
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sushi.push_back(x);
		if (i < k) {//인덱스 0을 기준으로 k개의 초밥 맵에 저장
			if (sushiList.find(x) != sushiList.end()) {
				sushiList[x] += 1;
			}
			else {
				sushiList.insert({ x,1 });
			}
		}
		
	}
	res = 0;
	chkeckSushiList();
	for (int i = 1; i < sushi.size(); i++)//한칸씩 윈도우를 이동하는 동시에 k크기를 유지시키며 맵을 갱신
	{
		eraseSushi(i);
		int next = i + k;
		addSushi(next);
		chkeckSushiList();
	}
	cout << res << "\n";
	return 0;
}