#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll dp[15][15];
int n;
bool is_used[10];
vector<int> ans;
int lleft;
int tot;

int digit = 1;
int fDigit = 1;
bool ansFind = false;

void nthBackTracking(int d, int p) {
	

	if (d == 1) {
		lleft--;
		if (lleft == 0) {
			ansFind = true;
			return;
		}
		return;
	}


	for (int i = 0; i <= p-1; i++) {
		if (is_used[i]) continue;
		is_used[i] = true; 
		ans.push_back(i);
		nthBackTracking(d - 1, i);
		if (ansFind) break;
		ans.pop_back();
		is_used[i] = false;
	}

}

int main() {
	dp[0][0] = 0;
	dp[0][1] = 1;
	dp[1][0] = 1;
	dp[1][1] = 1;
	scanf("%d", &n);
	lleft = n;
	if (n > 1022) {
		printf("-1");
		return 0;
	}



	//fill all of the combination for cutting
	for (int i = 1; i <= 9; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		}
	}

	bool isFind = false;
	
	for (int i = 0; i <= 9; i++) {
		for (int j = i; j <= 9; j++) {
			if (lleft <= dp[j][i]) {
				isFind = true;
				fDigit = j;
				digit = (i+1);
				break;

			}
			lleft -= dp[j][i];
		}
		if (isFind) break;
	}
	//printf("fDIgit : %d \n Digit : %d\n Left: %d\n", fDigit, digit, lleft);
	is_used[fDigit] = true;
	ans.push_back(fDigit);
	nthBackTracking(digit, fDigit);

	for (int i = 0; i < ans.size(); i++) {
		printf("%d", ans[i]);
	}
	
	return 0;
}
