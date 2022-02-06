#include<bits/stdc++.h>
using namespace std;

int dp[505][3];
int st[505];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &st[i]);
	}
	
	dp[1][1] = st[1];
	dp[1][2] = st[1];
	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[2][1] = st[2];
	dp[2][2] = st[1] + st[2];

	for (int i = 3; i <= n; i++) {
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + st[i];
		dp[i][2] = dp[i - 1][1] + st[i];
	}

	printf("%d", max(dp[n][1], dp[n][2]));
	return 0;
}
