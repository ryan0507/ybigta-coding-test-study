#include<bits/stdc++.h>
using namespace std;
int n;
int x[1'000'005];
int sort_x[1'000'005];
map<int, int> comp;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		sort_x[i] = x[i];
	}

	sort(sort_x, sort_x + n);
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		if (comp[sort_x[i]] == 0) {
			comp[sort_x[i]] = cnt;
			cnt++;
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", comp[x[i]] - 1);
	}
	return 0;
}
