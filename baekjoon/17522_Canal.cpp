#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
#define INF 1e9

using namespace std;

int n;
long long pre_max[300005], pre_min[300005];
long long suf_max[300005], suf_min[300005];
pair<long long, long long> cord[300005];


int main() {

	//input 
	scanf("%d", &n);

	if (n == 1) {
		printf("0.0\n");
		return 0;

	}

	for (int i = 1; i < n + 1; i++) {

		scanf("%lld %lld", &cord[i].first, &cord[i].second);
	
	}

	// main

	sort(cord + 1, cord + n + 1);
	pre_max[0] = -INF - 1;
	pre_min[0] = INF + 1;
	suf_min[n+1] = INF + 1;
	suf_max[n+1] = -INF - 1;

	// sort with y-axis

	for (int i = 1; i < n+1; i++) {
		pre_max[i] = max(cord[i].second, pre_max[i - 1]);
		pre_min[i] = min(cord[i].second, pre_min[i - 1]);
	}

	for (int i = n; i; i--) {
		suf_max[i] = max(cord[i].second, suf_max[i + 1]);
		suf_min[i] = min(cord[i].second, suf_min[i + 1]);
	}

	long long hi = ((long long)2e9) + 1;
	long long low = 0;

	while (low + 1 < hi ) {

		bool is_able = false;
		long long mid = (low + hi) / 2;
		int start = 1, end = 1;

		while (end <= n) {

			while (cord[end].first - cord[start].first >= mid && start < end) {
				start++;
			}

			long long mmax = -INF - 1;
			long long mmin = INF + 1;

			if (start > 1) {
				mmax = max(pre_max[start - 1], mmax);
				mmin = min(pre_min[start - 1], mmin);
			}

			if (end < n) {
				mmax = max(suf_max[end + 1], mmax);
				mmin = min(suf_min[end + 1], mmin);
			}

			// able case
			if (mmax < mid + mmin) {
				is_able = true;
				break;
			}
			
			end++;

		}

		if (is_able) {
			hi = mid;
		}

		else {
			low = mid;
		}


	}


	// output

	if (n == 1) {
	
		printf("0.0");
	
	}

	printf("%.1lf", low * 0.5);


	return 0;
}
