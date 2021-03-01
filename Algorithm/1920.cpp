#include <iostream>
#include <vector>
using namespace std;
int N, M;


void binary(vector<int>& vec,int start, int high) {
	int min = (start + high) / 2;

	while (start <= high) {

	}
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	cin >> N >> M;
	vector<int>nArr(N, 0);
	vector<int>mArr(M, 0);
	for (int i = 0; i < N; i++) {
		cin >> nArr[i];
	}

	for (int i = 0; i < M; i++) {
		cin >> mArr[i];
	}
	return 0;
}