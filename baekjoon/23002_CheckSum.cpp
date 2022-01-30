#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int t; 
int n;
int a[505][505], b[505][505];
int r[505], c[505];
int par[1500], sz[1500];
struct Edge {
	int w;
	int to;
	int from;
};

int find(int node) {
	if (par[node] == -1) return node;
	return par[node] = find(par[node]);
}
void merge(int a, int b) {
	int va = find(a);
	int vb = find(b);
	if (va != vb) {
		if (sz[va] > sz[vb]) {
			sz[va] += sz[vb];
			par[vb] = va;
		}

		else {
			sz[vb] += sz[va];
			par[va] = vb;
		}
	}
}

bool cmp(Edge e1, Edge e2) {
	if (e1.w == e2.w) {
		if (e1.to == e2.to) {
			return e1.from < e2.from;
		}
		
		return e1.to < e2.to;
	}
	return e1.w < e2.w;
}

int main() {
	scanf("%d", &t);
	for(int tc = 1; tc<=t; tc++) {
		scanf("%d", &n);
		vector<Edge> e;
		ll tot_cost = 0;
		ll mst = 0;
		fill(par, par + 1010, -1);
		fill(sz, sz + 1010, 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d",&a[i][j]);
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &b[i][j]);
				e.push_back({ b[i][j], n +j , i });
				tot_cost += b[i][j];
			}
		}

		sort(e.rbegin(), e.rend(),cmp);


		for (int i = 0; i < n; i++) {
			scanf("%d", &r[i]);
		}

		for (int i = 0; i < n; i++) {
			scanf("%d", &c[i]);
		}

		for (auto edge : e) {
			int w = edge.w;
			int to = edge.to;
			int from = edge.from;
			if (find(to) == find(from)) continue;
			mst += w;
			merge(to, from);
		}
		printf("Case #%d: %lld\n", tc, tot_cost - mst);
	}


	return 0;
}
