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
const int INFTY=20000000;
const int MAX=100100;
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
VVI GT(MAX);
set<int> K;
bool initvisited[MAX];
void initdfs(int v) {
	initvisited[v] = true;
	loop(i,0,GT[v].size()) {
		if(!initvisited[GT[v][i]]) initdfs(GT[v][i]);
	}
}

int col[MAX];

vector<int> Q;
bool dfs(int v) {
	col[v] = 1;
	loop(i,0,G[v].size()) {
		if(initvisited[G[v][i]]) {
			if(col[G[v][i]] == 1) {
				return false;
			}
			if(col[G[v][i]] == 0){
				if(!dfs(G[v][i])) return false;
			}
		}
	}
	Q.pb(v);
	col[v] = 2;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	int a,b;
	loop(i,0,k) {
		cin>>a;
		K.insert(a-1);
	}
	loop(i,0,n) {
		cin>>a;
		loop(j,0,a) {
			cin>>b;
			G[b-1].pb(i);
			GT[i].pb(b-1);
		}
	}
	for(int v: K) {
		initdfs(v);
	}
	loop(i,0,n) {
		if(initvisited[i]&&col[i]==0) {
			if(!dfs(i)) {
				pln(-1);
				return 0;
			}
		}
	}
	//coutVec(Q);
	reverse(ALL(Q));
	pln(Q.size());
	for(auto v : Q) {
		ps(v+1);
	}
	entr;
}
