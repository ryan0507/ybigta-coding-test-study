#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n, p;
ll t[1010][1010];
ll fib[1010][1010];
bool same = true;
ll ans;

int main() {
	scanf("%lld %lld", &n, &p);
	ll x = n - p + 1;

	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			scanf("%lld", &t[i][j]);
		}
	}

	fib[0][0] = 1;
	fib[0][1] = 1;

	// Make fib array
	for (int i = 2; i <= 200; i++) {
		fib[0][i] = fib[0][i - 1] + fib[0][i - 2];
	}
	//printf("MAXIDX: %d\n", max_idx);

	for (int i = 1; i <= 200; i++) {
		for (int j = 0; j < 200; j++) {
			if (j == 0) fib[i][j] = fib[i - 1][j + 1] - fib[i - 1][j];
			else fib[i][j] = fib[i - 1][j - 1];
		}
	}

	if (p >= 100) {
		printf("0");
		return 0;
	}

	/*
	for (int i = 0; i < max_idx; i++) {
		for (int j = 0; j < max_idx; j++) {
			printf("%lld ", fib[i][j]);
		}
		printf("\n");
	}
	*/

	// Compare the arrary, Check whether input is correct
	int diff1 = 0;
	int diff2 = 0;
	bool same1 = true;
	bool same2 = true;
	ll cur_idx = min((ll)90, x);
	for (ll i = 0; i <= cur_idx; i++) {
		same1 = true;
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < p; k++) {
				same1 = t[j][k] == fib[i + j][k] ? same1 && true : same1 && false;
			}
		}
		if (same1) { diff1 = i; 	break; }
	}

	for (ll i = 0; i <= cur_idx; i++) {
		same2 = true;
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < p; k++) {
				same2 = t[j][k] == fib[j][k + i] ? same2 && true : same2 && false;
			}
		}
		if (same2) { diff2 = i; break; }
	}
	//printf("diff1 : %d\n", diff1);
	//printf("diff2 : %d\n", diff2);
	if (same1) ans += (x - diff1);
	if (same2) ans += (x - diff2);
	if (same1 && same2) ans -= x;
	if (t[0][0] == 1 && p == 1) ans = 3 * x - 3;
	if (t[0][0] == 1 && p == 1 && n == 1) ans = 1;
	printf("%lld\n", ans);

	return 0;
}
