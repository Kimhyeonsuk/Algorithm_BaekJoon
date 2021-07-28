#include <iostream>
using namespace std;
int N, K;
int arr[201];
void spin() {
	int num = arr[N * 2];
	for (int i = N * 2; i > 1; i--) {
		arr[i] = arr[i - 1];
	}
	arr[1] = num;
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);


	cin >> N >> K;
	for (int i = 1; i <= N * 2; i++) {
		cin >> arr[i];
	}

	while (K != 0) {
		
	}
	return 0;
}