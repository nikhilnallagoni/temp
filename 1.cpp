#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod9 = 1e9 + 7;
const ll mod5 = 1e5 + 5;
#define all(v) v.begin(),v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(x...);
#endif
#define hello ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template<class T>istream& operator>>(istream &in, vector<T> &a) {for (auto &i : a) {in >> i;} return in;}
template<class T>ostream& operator<<(ostream &os, vector<T> &a) {for (auto &i : a) {os << i << " ";} return os;}
//______________________________________solution__________________________________________________________________
void solve(int Testcase)
{
	int n, m, k; cin >> n >> m >> k;
	vector<vector<int>>v(n + 1, vector<int>(m + 1, 0));
	vector<vector<int>>pf(n + 1, vector<int>(m + 1, 0));
	ll sum = 0;
	for (auto i = 1; i <= n; i++) {
		for (auto j = 1; j <= m; j++) {
			cin >> v[i][j];
			sum += v[i][j];
			pf[i][j] = v[i][j] + pf[i - 1][j] + pf[i][j - 1] - pf[i - 1][j - 1];
		}
	}
	if (sum < k + 1) {
		cout << -1; return;
	}
	int l = 0, r = n + m;
	int ans = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		bool found = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (v[i][j] != 0) {
					int l1 = max(i - mid , 1);
					int l2 = min(i + mid , n);
					int r1 = max(j - mid , 1);
					int r2 = min(j + mid , m);
					if (pf[l2][r2] - pf[l1 - 1][r2] - pf[l2][r1 - 1] + pf[l1 - 1][r1 - 1] > k) {
						found = true;
					}
				}
			}
		}
		if (found) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;

}
//______________________________________main______________________________________________________________________
int32_t main()
{
	hello; int Testcase = 1 , i = 1;
	cin >> Testcase;
	while (i <= Testcase) {solve(i++); cout << endl;} return 0;
}
