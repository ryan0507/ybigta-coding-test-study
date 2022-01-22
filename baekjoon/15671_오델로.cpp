#include<bits/stdc++.h>
using namespace std;

char board[10][10];
int n;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int main() {
	scanf("%d", &n);
	fill(&board[0][0], &board[9][10], '.');
	board[3][3] = 'W';
	board[4][4] = 'W';
	board[3][4] = 'B';
	board[4][3] = 'B';

	for (int i = 0; i < n; i++) {
		int cx, cy;
		scanf("%d %d", &cx, &cy);
		//Black Turn
		if (i % 2 == 0) {
			board[cx][cy] = 'B';
			for (int dir = 0; dir < 8; dir++) {
				stack<pair<int, int>> s;
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];
				while (nx > 0 && nx < 7 &&
					ny > 0 && ny < 7 &&
					board[nx][ny] == 'W') {
					s.push({ nx,ny });
					nx += dx[dir];
					ny += dy[dir];
				}
				if (board[nx][ny] == 'B') {
					while (!s.empty()) {
						pair<int, int> tmp = s.top();
						board[tmp.first][tmp.second] = 'B';
						s.pop();
					}
				}
			}
		}

		//White Turn

		else {
			board[cx][cy] = 'W';
			for (int dir = 0; dir < 8; dir++) {
				stack<pair<int, int>> s;
				int nx = cx + dx[dir];
				int ny = cy + dy[dir];
				while (nx > 0 && nx < 7 &&
					ny > 0 && ny < 7 &&
					board[nx][ny] == 'B') {
					s.push({ nx,ny });
					nx += dx[dir];
					ny += dy[dir];
				}
				if (board[nx][ny] == 'W') {
					while (!s.empty()) {
						pair<int, int> tmp = s.top();
						board[tmp.first][tmp.second] = 'W';
						s.pop();
					}
				}
			}
		}
	}

	int b = 0;
	int w = 0;

	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			if (board[i][j] == 'B') b += 1;
			else if (board[i][j] == 'W') w += 1;
			printf("%c", board[i][j]);
		}
		printf("\n");
	}

	if (b > w) printf("Black");
	else printf("White");
	return 0;
}
