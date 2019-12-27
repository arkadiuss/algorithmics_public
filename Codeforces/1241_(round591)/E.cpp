#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define foreach(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define SIZE(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
using namespace std;
typedef vector<int> VI;
const int INFTY=20000000;
typedef vector<vector<int> > VVI;
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
struct E {
	int u;
	ll w;
	E(int _u, ll _w) : u(_u), w(_w) {};
};

typedef vector<vector<E> > VVE;
typedef pair<ll, ll> PLL;

VVE G(MAX);
ll dp[MAX][2];
int k;
void dfs(int v, int l) {
	vector<ll> cres0;
	ll res = 0;
	//pln(v);
	loop(i,0,G[v].size()) {
		if(G[v][i].u != l){
			dfs(G[v][i].u, v);
			if(dp[G[v][i].u][0] + G[v][i].w > dp[G[v][i].u][1])
				cres0.pb(dp[G[v][i].u][0] + G[v][i].w - dp[G[v][i].u][1]);
			res += dp[G[v][i].u][1];
		}
	}
	sort(ALL(cres0), std::greater<ll>());
	dp[v][0] = res;
	dp[v][1] = res;
	loop(i,0,cres0.size()) {
		if(i < k-1)
			dp[v][0] += cres0[i]; 
		if(i < k)
			dp[v][1] += cres0[i];
	} 
}

int main(){
	ios_base::sync_with_stdio(0);
	int q;
	cin>>q;
	while(q--) {
		int n;
		cin>>n>>k;
		loop(i,0,n) G[i].clear();
		int a,b;
		ll w;
		loop(i,0,n-1){
			cin>>a>>b>>w;
			G[a-1].pb(E(b-1,w));
			G[b-1].pb(E(a-1,w));
		}
		
		dfs(0,-1);
		pln(max(dp[0][0], dp[0][1]));
	}
}
