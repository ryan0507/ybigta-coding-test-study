#include<bits/stdc++.h>
using namespace std;

int t, n, k, m;
int T;

struct Team {
	int id;
	map<int, int> score;
	int cntSub = 0;
	int lastSub = -1;
	int tot = 0;
};

bool cmp(Team a, Team b) {
	if (a.tot == b.tot) {
		if (a.cntSub == b.cntSub) {
			return a.lastSub < b.lastSub;
		}
		return a.cntSub < b.cntSub;
	}
	return a.tot > b.tot;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d %d", &n, &k, &t, &m);
		Team team[105];
		for (int i = 0; i < m; i++) {
			int tmpID, tmpNum, tmpScore;
			scanf("%d %d %d", &tmpID, &tmpNum, &tmpScore);
			team[tmpID - 1].score[tmpNum] = team[tmpID - 1].score[tmpNum] < tmpScore ? tmpScore : team[tmpID - 1].score[tmpNum];
			team[tmpID - 1].id = tmpID;
			team[tmpID - 1].cntSub += 1;
			team[tmpID - 1].lastSub = i;
		}

		for (int i = 0; i < n; i++) {
			for (auto p = team[i].score.begin(); p != team[i].score.end(); p++) {
				team[i].tot += p->second;
			}
		}
		sort(team, team + n, cmp);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (team[i].id == t) ans = i + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
