#include <bits/stdc++.h>

using namespace std;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

struct edge {
	int to;
	int cost;
	edge(int _t, int _c) : to(_t), cost(_c) {}
};
int32_t main()
{
	cin.tie(0)->sync_with_stdio(false);
	cout << setprecision(10) << fixed;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		unordered_map<string, int> id;
		vector<vector<edge>> g(n);
		for (int i = 0; i < n; ++i) {
			string name;
			cin >> name;
			id[name] = i;
			int totalNeighbour;
			cin >> totalNeighbour;
			for (int j = 0; j < totalNeighbour; ++j) {
				int v, cost;
				cin >> v >> cost;
				v--;
				g[i].emplace_back(edge(v, cost));
			}
		}
		auto dijkstra = [&] (int s, int des) {
			minpq<pair<int, int>> pq;
			const int inf = 1e9;
			vector<int> d(n, inf);
			d[s] = 0;
			pq.push(make_pair(0, s));
			while (!pq.empty()) {
				auto [cost, u] = pq.top();
				pq.pop();
				// if (d[u] != cost) continue;
				for (auto [to, c] : g[u]) {
					if (d[to] > c + cost) {
						d[to] = c + cost;
						pq.push(make_pair(d[to], to));
					}
				}
			}
			return d[des] == inf ? -1 : d[des];
		};
		int r;
		cin >> r;
		for (int i = 0; i < r; ++i) {
			string s1, s2;
			cin >> s1 >> s2;
			int x = id[s1], y = id[s2];
			cout << dijkstra(x, y) << '\n';
		}
	}
	return 0;
}