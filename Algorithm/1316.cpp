#include <iostream>
#include <string>
#include <vector>
using namespace std;

//�׷� �ܾ�� �ܾ �����ϴ� ��� ���ڿ� ���ؼ�, �� ���ڰ� �����ؼ� ��Ÿ���� ��츸�� ���Ѵ�.���� ���, ccazzzzbb�� c, a, z, b�� ��� �����ؼ� ��Ÿ����, kin�� k, i, n�� �����ؼ� ��Ÿ���� ������ �׷� �ܾ�������, aabbbccb�� b�� �������� ��Ÿ���� ������ �׷� �ܾ �ƴϴ�.
//
//�ܾ� N���� �Է����� �޾� �׷� �ܾ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//�Է�
//ù° �ٿ� �ܾ��� ���� N�� ���´�.N�� 100���� �۰ų� ���� �ڿ����̴�.��° �ٺ��� N���� �ٿ� �ܾ ���´�.�ܾ�� ���ĺ� �ҹ��ڷθ� �Ǿ��ְ� �ߺ����� ������, ���̴� �ִ� 100�̴�.
//
//���
//ù° �ٿ� �׷� �ܾ��� ������ ����Ѵ�.
int N, res;
bool chk(string s) {

	vector<bool>exist(28, false);
	char tmp = s[0];
	exist[tmp - 'a'] = true;
	for (int i = 1; i < s.length(); i++) {
		char n = s[i];
		if (n == tmp)
			continue;
		else {
			if (exist[n - 'a'] == true)//�̹� �ѹ� ���Դ� ����
			{
				return false;
			}
			else {
				tmp = n;
				exist[n - 'a'] = true;
			}
		}
	}
	return true;
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	res = 0;
	cin >> N;
	while (N--) {
		string s;
		cin >> s;
		if (chk(s))
			res++;
	}

	cout << res << "\n";
	return 0;
}