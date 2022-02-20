#include<bits/stdc++.h>
using namespace std;

char s1[1005];
char s2[1005];
int ans = 0;

int dp[1005][1005];
int main() {
	
	//input
	fgets(s2, 10000, stdin);
	fgets(s1, 10000, stdin);

	//main
	memset(dp, 0, 1005 * 1005);

	int n1 = string(s1).length();
	int n2 = string(s2).length();

	if (s1[n1-1] == '\n') {
		s1[n1 - 1] = NULL;
		n1--;
	}

	if (s1[n2 - 1] == '\n') {
		s1[n2 - 1] = NULL;
		n2--;
	}
	

	// initialize
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			if (s1[i - 1] == s2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}

			// different table 
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	//main dp

	
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n2; j++) {
			ans = max(dp[i][j], ans);
		}
	}
	
	//output
	printf("%d\n", ans);
	return 0;
}
