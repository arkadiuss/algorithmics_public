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

const int MAX = 100010;
const int SQR = 320;
int N,E,P;
bool visited[MAX];
vector<set<int> > G(MAX);
set<int> cur;
void dfs(int v) {
	visited[v] = 1;
	if(G[v].size() >= SQR) {
		for(int c : cur) {
			if(!visited[c] && G[v].find(c) != G[v].end()) dfs(c);
		}
	} else {
		for(int c : G[v]) {
			if(!visited[c] && cur.find(c) != cur.end()) dfs(c);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin>>N>>E>>P;
	int a,b;
	loop(i,0,E) {
		cin>>a>>b;
		G[a].insert(b);
		G[b].insert(a);
	}
	loop(p,0,P) {
		int m,w;
		cin>>m;
		for(int c:cur) visited[c] = 0;
		cur.clear();
		loop(i,0,m) {
			cin>>w;
			cur.insert(w);
		}
		int ss = 0;
		for(int c : cur) {
			if(!visited[c]) {
				ss++;
				dfs(c);
			}
		}
		pln(ss);
	}
	return 0;
}

