#include <iostream>
#include <queue>
#include <deque>
#define  RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3
#define APPLE 2
#define SNAKE 1
using namespace std;
int n,k,l,dir,day;
int board[101][101];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, char>>dirq;
queue<pair<int, int>>snake;
//dir 0,1,2,3 µ¿, ¼­ , ³² ºÏ
int changedir(int curdir,char spin) {
	if (curdir == RIGHT) {
		if (spin == 'L') {
			return UP;
		}
		else {
			return DOWN;
		}
	}
	else if (curdir == LEFT) {
		if (spin == 'L') {
			return DOWN;
		}
		else {
			return UP;
		}
	}
	else if (curdir == UP) {
		if (spin == 'L') {
			return LEFT;
		}
		else {
			return RIGHT;
		}
	}
	else if (curdir == DOWN) {
		if (spin == 'L') {
			return RIGHT;
		}
		else {
			return LEFT;
		}
	}
}
int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		board[x - 1][y - 1] = APPLE;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int sec;
		char d;
		cin >> sec >> d;
		dirq.push({ sec,d });
	}
	day = 0;
	dir = 0;
	board[0][0] = SNAKE;
	snake.push({ 0,0 });
	while (true) {
		day++;
		int x = snake.back().first;
		int y = snake.back().second;

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		
		if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
			snake.push({ nx,ny });
			if (board[nx][ny] == APPLE) {
				board[nx][ny] = SNAKE;
			}
			else if (board[nx][ny]==SNAKE){
				break;
			}
			else {
				board[snake.front().first][snake.front().second] = 0;
				snake.pop();
				board[nx][ny] = SNAKE;
			}
		}
		else {
			break;
		}

		if (!dirq.empty() && dirq.front().first == day) {
			dir = changedir(dir, dirq.front().second);
			dirq.pop();
		}
	}

	cout << day;
}