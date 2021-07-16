#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int N = 1e5 + 5, M = 1e6 + 6, OO = 0x3f3f3f3f;

int n, m;
vector<int> adj[N];

bool vis[N];
void DFS(int u) {
	vis[u] = 1;
	for (int v : adj[u])
		if (!vis[v]) DFS(v);
}

int u, v;

int main() {
	scanf_s("%d %d", &n, &m);
	if (m != n - 1) {
		puts("NO");
		return 0;
	}
	for (int i = 0; i < m; ++i) {
		scanf_s("%d %d", &u, &v);
		--u;
		--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int comps = 0;
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			++comps;
			DFS(i);
		}
	}
	if (comps == 1)  puts("YES");
	else puts("NO");
	return 0;
}