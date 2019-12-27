#include <bits/stdc++.h>
#define st first
#define nd second
#define fi first
#define se second
#define pb push_back
#define loop(i,j,n) for(int i=j;i<n;i++)
#define ps(v) cout << v << " "
#define pln(v) cout << v << "\n"
#define entr cout << "\n"

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const int MAX = 300010;

vector<vector<int> > G(MAX);

int count(int v, int l) {
	int res = 0;
	int c = 0;
	loop(i,0,G[v].size()) {
		if(G[v][i] != l) {
			c++;
			res += count(G[v][i],v);
		}
	}
	res += max(c-1,0);
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	int a,b;
	loop(i,0,n-1) {
		cin>>a>>b;
		G[a-1].pb(b-1);
		G[b-1].pb(a-1);
	}
	int j=0;
	while(G[j].size() != 1 && j < n) j++;
	pln(count(j, -1));
	return 0;
}

