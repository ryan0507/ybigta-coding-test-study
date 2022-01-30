#include<bits/stdc++.h>
#define INF 1e9
using namespace std;


char board[15][15];
struct ball {
	int rx;
	int ry;
	int bx;
	int by;
	int cnt;
};
queue<ball> q;
int n, m;
int crx, cry, cbx, cby;
bool ffind = false;
int ans = INF;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };


int main() {
	
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &board[i][j]);
			
			if (board[i][j] == 'R') {
				crx = i;
				cry = j;
			}
			
			else if (board[i][j] == 'B') {
				cbx = i;
				cby = j;
			}
		}
	}
	
	q.push({crx,cry,cbx,cby,0});

	while (!q.empty()) {
		ball cur = q.front();
		q.pop();
		crx = cur.rx;
		cry = cur.ry;
		cbx = cur.bx;
		cby = cur.by;
		int cnt = cur.cnt;
		cnt++;
		
		for (int dir = 0; dir < 4; dir++) {
			int nrx = crx + dx[dir];
			int nry = cry + dy[dir];
			int dist_r = 0;
			bool r_end = false, b_end = false;

			while (board[nrx][nry] != 'O' &&  board[nrx][nry] != '#') {
				dist_r++;
				nrx += dx[dir];
				nry += dy[dir];
			}
			if (board[nrx][nry] == '#') {
				nrx -= dx[dir];
				nry -= dy[dir];
			}

			else if (board[nrx][nry] == 'O') {
				r_end = true;
				dist_r++;
			}


			int nbx = cbx + dx[dir];
			int nby = cby + dy[dir];
			int dist_b = 0;
			
			while (board[nbx][nby] != 'O' && board[nbx][nby] != '#') {
				dist_b++;
				nbx += dx[dir];
				nby += dy[dir];
			}

			if (board[nbx][nby] == '#') {
				nbx -= dx[dir];
				nby -= dy[dir];
			}

			else if (board[nbx][nby] == 'O') {
				b_end = true;
				dist_b++;
			}

			if (nrx == nbx && nry == nby) {
				if (board[nrx][nry] == 'O') continue;

				// Update if the ball blocked at the same place
				if (dist_r < dist_b) {
					nbx -= dx[dir];
					nby -= dy[dir];
					dist_b--;
				}

				else {
					nrx -= dx[dir];
					nry -= dy[dir];
					dist_r--;
				}
			}


			//Check what ball is forward

			if (b_end) continue;
			//3. If ball don't move
			if (dist_r == 0 && dist_b == 0) continue;
			if (r_end && !b_end) {
				ffind = true;
				ans = cnt;
				printf("%d", ans);
				return 0;
			}

			if (cnt > 9) continue;
			q.push({ nrx,nry,nbx,nby,cnt});
		}
	}
	
	/*
	Debug
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	*/
	printf("-1");
	return 0;
}
