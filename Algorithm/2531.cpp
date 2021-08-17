#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int n, d, k, c, res;
map<int, int>sushiList;
vector<int>sushi;
void chkeckSushiList() {//������ ���� ������ Ȯ���Ͽ� �� ����
	int tmpsize = sushiList.size();
	if (sushiList.find(c) != sushiList.end()) {
		res = max(res,tmpsize);
	}
	else
		res = max(res, tmpsize + 1);
}
void eraseSushi(int idx) {//�����츦 �̵���Ŵ������ ������ �ʹ��� ������ �ʿ��� ����
	if (sushiList[sushi[idx - 1]] == 1) {
		sushiList.erase(sushi[idx - 1]);
	}
	else {
		sushiList[sushi[idx - 1]] -= 1;
	}
}
void addSushi(int idx) {
	if (idx > sushi.size()) {//�̵���Ų �������� ������ �ε����� �迭�� ����� ��� 0�� �ε������� �ٽ� ���Խ��Ѿ� �ϴ� ���
		idx = ((idx) % sushi.size()) ;//�������� �ε��� ã��
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
		if (i < k) {//�ε��� 0�� �������� k���� �ʹ� �ʿ� ����
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
	for (int i = 1; i < sushi.size(); i++)//��ĭ�� �����츦 �̵��ϴ� ���ÿ� kũ�⸦ ������Ű�� ���� ����
	{
		eraseSushi(i);
		int next = i + k;
		addSushi(next);
		chkeckSushiList();
	}
	cout << res << "\n";
	return 0;
}