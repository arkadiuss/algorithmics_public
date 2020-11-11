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
typedef pair<int, int> PII;
typedef vector<vector<int> > VVI;
const ll INFTY=1e14;
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}

template<class T> void coutVec(vector<T> tab){
	for(T t : tab){
		cout<<t<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
VVI G(MAX);
ll a[MAX];
ll dp[MAX][2];

void count_dp(int v) {
	int m = G[v].size();
	//ps("VVV");ps(v);pln(m);
	if(G[v].size() == 0) {
		dp[v][0]=0;
		dp[v][1]=a[v];
		return;
	}
	vector<vector<ll>> T(m, vector<ll>(2));
	count_dp(G[v][0]);
	T[0][0]=dp[G[v][0]][0];
	T[0][1]=dp[G[v][0]][1];
	loop(i,1,m) {
		int w = G[v][i];
		count_dp(w);
		T[i][0] = max(T[i-1][0], max(T[i-1][1] + dp[w][1], T[i-1][0] + dp[w][0]));
		T[i][1] = max(T[i-1][1], max(T[i-1][0] + dp[w][1], T[i-1][1] + dp[w][0]));
	}
	dp[v][0]=T[m-1][0];
	dp[v][1]=max(T[m-1][1], T[m-1][0]+a[v]);
	//ps(v+1);ps(dp[v][0]);pln(dp[v][1]);
}

int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	int p;
	int st=-1;
	loop(i,0,n) {
		cin>>p>>a[i];
		if(p==-1) {
			st=i;
		} else {
			G[p-1].pb(i);
		}
	}
	count_dp(st);
	pln(max(dp[st][0],dp[st][1]));
}
