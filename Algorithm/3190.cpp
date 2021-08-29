#include <iostream>
#include <queue>
#define EAST 0
#define WEST 1
#define SOUTH 2
#define NORTH 3
using namespace std;
int board[101][101];
queue<pair<int, int>>snake;
queue<pair<int, char>>rotateInfo;
int N, K, L;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int changeDir(int dir, char c) {
	if (dir == EAST) {
		if (c == 'D') {
			return SOUTH;
		}
		else {
			return NORTH;
		}
	}
	else if (dir == WEST) {
		if (c == 'D') {
			return NORTH;
		}
		else {
			return SOUTH;
		}
	}
	else if (dir == SOUTH) {
		if (c == 'D') {
			return WEST;
		}
		else {
			return EAST;
		}
	}
	else if (dir == NORTH) {
		if (c == 'D') {
			return EAST;
		}
		else {
			return WEST;
		}
	}
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		board[x-1][y-1] = 2;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int sec;
		char c;
		cin >> sec >> c;
		rotateInfo.push({ sec,c });
	}
	board[0][0] = 1;
	snake.push({ 0,0 });
	int curDir = EAST;
	int curx = 0, cury = 0;
	int sec = 0;
	while (true) {
		sec++;
		int nx = curx + dx[curDir];
		int ny = cury + dy[curDir];
		if (nx < 0 || ny < 0 || nx >= N || ny >= N)break;
		if (board[nx][ny] == 1)break;
		if (board[nx][ny] == 0) {
			pair<int, int> tail = snake.front();
			snake.pop();
			board[tail.first][tail.second] = 0;
			board[nx][ny] = 1;
			snake.push({ nx,ny });
			curx = nx;
			cury = ny;
		}
		else if (board[nx][ny] == 2) {
			board[nx][ny] = 1;
			snake.push({ nx,ny });
			curx = nx;
			cury = ny;
		}

		if (!rotateInfo.empty() &&rotateInfo.front().first == sec) {
			int nextDir = changeDir(curDir, rotateInfo.front().second);
			curDir = nextDir;
			rotateInfo.pop();
		}

	}
	cout << sec << "\n";
	return 0;
}



//#include <iostream>
//#include <queue>
//#include <deque>
//#define  RIGHT 0
//#define LEFT 1
//#define UP 2
//#define DOWN 3
//#define APPLE 2
//#define SNAKE 1
//using namespace std;
//int n,k,l,dir,day;
//int board[101][101];
//int dx[4] = { 0,0,-1,1 };
//int dy[4] = { 1,-1,0,0 };
//queue<pair<int, char>>dirq;
//queue<pair<int, int>>snake;
////dir 0,1,2,3 µ¿, ¼­ , ³² ºÏ
//int changedir(int curdir,char spin) {
//	if (curdir == RIGHT) {
//		if (spin == 'L') {
//			return UP;
//		}
//		else {
//			return DOWN;
//		}
//	}
//	else if (curdir == LEFT) {
//		if (spin == 'L') {
//			return DOWN;
//		}
//		else {
//			return UP;
//		}
//	}
//	else if (curdir == UP) {
//		if (spin == 'L') {
//			return LEFT;
//		}
//		else {
//			return RIGHT;
//		}
//	}
//	else if (curdir == DOWN) {
//		if (spin == 'L') {
//			return RIGHT;
//		}
//		else {
//			return LEFT;
//		}
//	}
//}
//int main() {
//	cin.tie(NULL);
//	std::ios::sync_with_stdio(false);
//	cin >> n;
//	cin >> k;
//	for (int i = 0; i < k; i++) {
//		int x, y;
//		cin >> x >> y;
//		board[x - 1][y - 1] = APPLE;
//	}
//	cin >> l;
//	for (int i = 0; i < l; i++) {
//		int sec;
//		char d;
//		cin >> sec >> d;
//		dirq.push({ sec,d });
//	}
//	day = 0;
//	dir = 0;
//	board[0][0] = SNAKE;
//	snake.push({ 0,0 });
//	while (true) {
//		day++;
//		int x = snake.back().first;
//		int y = snake.back().second;
//
//		int nx = x + dx[dir];
//		int ny = y + dy[dir];
//		
//		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
//			snake.push({ nx,ny });
//			if (board[nx][ny] == APPLE) {
//				board[nx][ny] = SNAKE;
//			}
//			else if (board[nx][ny]==SNAKE){
//				break;
//			}
//			else {
//				board[snake.front().first][snake.front().second] = 0;
//				snake.pop();
//				board[nx][ny] = SNAKE;
//			}
//		}
//		else {
//			break;
//		}
//
//		if (!dirq.empty() && dirq.front().first == day) {
//			dir = changedir(dir, dirq.front().second);
//			dirq.pop();
//		}
//	}
//
//	cout << day;
//}