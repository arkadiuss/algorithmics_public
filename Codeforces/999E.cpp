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
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------

void dfs(vector<VI > & G,int * visited,int v,int c){
	visited[v]=c;
	loop(i,0,SIZE(G[v])){
		if(visited[G[v][i]]<c){
			dfs(G,visited,G[v][i],c);
		}
	}
}
int solve(vector<VI > & G, int n,int s){
	int visited[n];
	loop(i,0,n) visited[i]=-1;
	dfs(G,visited,s,n+1);
	loop(i,0,n){
		if(visited[i]==-1)
			dfs(G,visited,i,i);
	}
	set<int> S;
	loop(i,0,n) S.insert(visited[i]);
	return S.size()-1;	
}
int main(){
	ios_base::sync_with_stdio(0);
	int n,m,s;
	cin>>n>>m>>s;
	vector<VI > G(n);
	int a,b;
	loop(i,0,m){
		cin>>a>>b;
		G[a-1].pb(b-1);		
	}
	pln(solve(G,n,s-1));
}
