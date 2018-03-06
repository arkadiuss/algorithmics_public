#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define foreach(i,c) for(VAR(i,c.begin());i!=c.end();i++)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) c.size()
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const int MAX=1000100;
const int MOD=1000000000;
const int INFTY=1000000000;
typedef vector<int> VI;

void coutTab(int * tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------

template<class V, class E> struct Graph{
	int chg[MAX];
	int hmG[MAX];
	int toOk;
	struct Ed : E {
		int v;
		Ed(E e, int w) : E(e), v(w) { };  
	};
	struct Ve : V, vector<Ed> {};
	
	vector<Ve> g;
	
	Graph(int n=0) : g(n) { };
	
	void EdgeU(int a, int b, E e=E()){
		e.rgh=1;
		e.is=1;
		e.rev=SIZE(g[b])+(a==b);
		g[a].pb(Ed(e,b));
		e.rev=SIZE(g[a])-1;
		e.is=0;
		e.rgh=0;
		g[b].pb(Ed(e,a));
	}
	
	void coutG(){
		loop(i,0,3){
			ps(chg[i]);	
		}
		entr;
		loop(i,0,3){
			ps(hmG[i]);
		}
		entr;
		loop(i,0,SIZE(g)){
			ps(i);ps(": ");
			foreach(it, g[i]){
				cout<<it->v<<":"<<it->is<<":"<<it->col<<" ";
			}
			entr;
		}
	}
	void clearTab(){
		toOk=0;
		loop(i,0,SIZE(g)) chg[i]=0;
	}
	void firstDfs(int v, int l){
		foreach(it, g[v]){
			if(it->v!=l){
				if(it->is){
					it->is=0;
					g[it->v][it->rev].is=1;
					if(chg[it->col]==0){
						toOk++;
					}
					chg[it->col]++;
					if(chg[it->col]==hmG[it->col])
						toOk--;
				}
			}
		}
	}
};
struct V{};
struct E{
	int rev;
	bool is,rgh;
	int col;
	E (int r, int c) : rgh(r), col(c) {}; 
};
int n;
Graph<V,E> G;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	G=Graph<V,E>(n);
	int a,b,c;
	loop(i,0,n-1){
		cin>>a>>b>>c;
		G.EdgeU(a-1,b-1,E(1,c));
		G.hmG[c]++;
	}
	G.coutG();
	G.firstDfs(0,-1);
	G.coutG();
}
