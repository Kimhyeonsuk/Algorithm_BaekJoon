#include <iostream>
#include <queue>
using namespace std;
#define SUCCESS "YES"
#define FAIL "NO"
int K, V, E;
vector<int>vec[20001];
char chk[20001];
queue<pair<int,char>>q;
const char* bfs() {
	while (!q.empty()) {
		int val = q.front().first;
		char type = q.front().second;
		int s = vec[val].size();
		q.pop();
		for (int i = 0; i < s; i++) {
			int nval = vec[val][i];
			if (chk[nval] == 'A') {
				if (type == 'A')
					return FAIL;
			}
			else if (chk[nval] == 'B') {
				if (type == 'B')
					return FAIL;
			}
			else {
				chk[nval] = (type == 'A') ? 'B' : 'A';
				q.push({ nval,chk[nval] });
			}
			
			
		}
	}

	return SUCCESS;
}
void qempty() {
	while (!q.empty())
		q.pop();
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> K;
	while (K--) {
		cin >> V >> E;
		


		for (int i = 0; i < E; i++) {
			int a, b;
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		

		bool fail = false;
		for (int i = 1; i <= V; i++) {
			if (chk[i] != 'A' && chk[i] != 'B') {
				q.push({ i,'A' });
				chk[i] = 'A';
				const char* a = bfs();
				if (a == FAIL) {
					fail = true;
					break;
				}

			}
		}

		if (fail) {
			cout << FAIL << "\n";
		}
		else
			cout << SUCCESS << "\n";
		


		qempty();
		for (int i = 1; i <= V; i++) {
			vec[i].clear();
			chk[i] = 'S';
		}
			
	}


}