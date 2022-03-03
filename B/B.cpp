#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
	cin.tie(0)->sync_with_stdio(false);
	cout << setprecision(10) << fixed;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<int, int> id;
		bool ok = false;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			if (id.count(x))
				ok |= (i - id[x]) > 1;
			else
				id[x] = i;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}
	return 0;
}