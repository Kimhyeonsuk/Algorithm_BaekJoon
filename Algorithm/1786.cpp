#include <iostream>
#include <string>
#include <vector>
using namespace std;
string T, P;
int res = 0;
vector<int>loc;
vector<int> getPi() {
	vector<int> pi(P.size(), 0);
	int j = 0;
	for (int i = 1; i < P.size(); i++) {
		while (j > 0 && P[i] != P[j]) {
			j = pi[j - 1];
		}
		if (P[i] == P[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}
void KMP() {
	vector<int> pi = getPi();
	int j = 0;
	for (int i = 0; i < T.size(); i++) {
		while (j > 0 && T[i] != P[j]) {
			j = pi[j - 1];
		}
		if (T[i] == P[j]) {
			if (j == P.size() - 1) {//문자 찾았을대
				j = pi[j];
				res++;
				loc.push_back(i-P.size()+1);
			}
			else {
				j++;
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	getline(cin,T);
	getline(cin, P);

	

	KMP();
	cout << res << "\n";
	for (int i = 0; i < loc.size(); i++) {
		cout << loc[i]+1 << " ";

	}
}