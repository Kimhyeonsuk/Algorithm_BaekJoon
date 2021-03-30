#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int N;
bool comp(char a, char b) {
	return a > b;
}
char ch[10];
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> ch;
	sort(ch, ch+strlen(ch),greater<int>());
	for (int i = 0; i < strlen(ch); i++) {
		cout << ch[i];
	}
	return 0;
}