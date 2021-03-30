#include <iostream>
#include <stack>
using namespace std;
int T;

bool chkVPS(string s) {
	stack<char> st;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(s[i]);
		}
		else if (s[i] == ')') {
			if (st.empty())
				return false;
			else if (st.top() == '(')
				st.pop();
		}
	}

	if (!st.empty())
		return false;

	return true;
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		if (chkVPS(s)) {
			cout << "YES" << "\n";
		}
		else {
			cout << "NO" << "\n";
		}
	}
	return 0;
}