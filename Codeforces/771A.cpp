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
const int MAX=150100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
vector< VI > G(MAX);
int n,m;
bool visited[MAX];
ll l=0;
void dfs(int a){
	l++;
	visited[a]=1;
	loop(i,0,SIZE(G[a])){
		if(!visited[G[a][i]]) dfs(G[a][i]);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	int a,b;
	loop(i,0,m){
		cin>>a>>b;
		G[a-1].pb(b-1);
		G[b-1].pb(a-1);
	}
	loop(i,0,n) visited[i]=0;
	ll S=0;;
	loop(i,0,n){
		if(!visited[i]){
			l=0;
			dfs(i);
			S+=(l*(l-1)/2);
		}
	}
	if(S==m) pln("YES");
	else pln("NO");
}
