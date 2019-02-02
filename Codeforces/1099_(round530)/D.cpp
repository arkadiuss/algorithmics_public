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
const ll INFTY=20000000000;
const int MAX=100100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
vector<VI > G(MAX);
ll s[MAX];
int p[MAX];
int n;
ll dfs(int v, int l, ll lv){
	ll sum = 0;
	ll mini = INFTY;
	loop(i,0,G[v].size()){
		mini=min(mini, s[G[v][i]]);
	}
	if(G[v].size()==0) mini=s[l];
	if(s[v]==-1) s[v]=mini;
	loop(i,0,G[v].size()){
		ll res = dfs(G[v][i], v, s[v]);
		if(res==-1) return -1;
		sum += res;
	}
	if(lv>s[v]) return -1;
	return sum + s[v] - lv;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	p[0]=-1;
	loop(i,1,n){
		cin>>p[i];
		p[i]--;
		G[p[i]].pb(i);
	}
	loop(i,0,n){ 
		cin>>s[i];
	}
	ll res = dfs(0,-1,0);
	pln(res);
}
