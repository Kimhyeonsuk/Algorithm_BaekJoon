//����
//���̻� �迭�� ���ڿ� S�� ��� ���̻縦 ���������� ������ ���� �迭�̴�.
//
//baekjoon�� ���̻�� baekjoon, aekjoon, ekjoon, kjoon, joon, oon, on, n ���� �� 8������ �ְ�, �̸� ���������� �����ϸ�, aekjoon, baekjoon, ekjoon, joon, kjoon, n, on, oon�� �ȴ�.
//
//���ڿ� S�� �־����� ��, ��� ���̻縦 ���������� ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//�Է�
//ù° �ٿ� ���ڿ� S�� �־�����.S�� ���ĺ� �ҹ��ڷθ� �̷���� �ְ�, ���̴� 1, 000���� �۰ų� ����.
//
//���
//ù° �ٺ��� S�� ���̻縦 ���������� �� �ٿ� �ϳ��� ����Ѵ�.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string s;
vector<string> vec;
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> s;
	vec.push_back(s);
	for (int i = 1; i < s.length(); i++) {
		string tmp = s.substr(i, s.length() - i);
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << "\n";
	}
	return 0;
}