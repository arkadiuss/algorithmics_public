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
#define pcnt __builtin_popcount
using namespace std;
const int MAX=1100;
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
template<class V, class E> struct Tree{
	struct Ed : E{
		int v;
		Ed(E e,int w) : E(e), v(w) {};
	};
	struct Ve : V, vector<Ed> {};
	vector<Ve> g;
	Tree(int n=0) : g(n) {};
 	void EdgeU(int a, int b, E e=E()){
 		g[a].pb(Ed(e,b));
 		g[b].pb(Ed(e,a));
 	}
 	void coutT(){
 		loop(i,0,SIZE(g)){
 			ps(i+1);ps(":");
 			foreach(it,g[i]){
 				cout<<it->v+1<<":"<<it->w<<" ";
 			}
 			entr;
 		}
 	}
 	int dfs(int v, int l){
 		int s=0;
 		foreach(it,g[v]){
 			if(it->v!=l){
 				s=s+dfs(it->v,v);
 				if((g[v].hasB&&!g[it->v].hasB)||(g[it->v].hasB&&!g[v].hasB))
 					s=s+it->w;
 			}
 		}
 		return s;
 	}
};
int n;
struct Vv {
	int hasB;
};
struct Ee {
	int w;
};
Tree<Vv,Ee> T;
int k;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	T=Tree<Vv,Ee>(n);
	int a,b,w;
	int S=0;
	loop(i,0,n-1){
		cin>>a>>b>>w;
		S=S+w;
		Ee ed;
		ed.w=w;
		T.EdgeU(a-1,b-1,ed);
	}
	//T.coutT();
	int best=INFTY;
	loop(mask,0,1<<n){
		if(pcnt(mask)==k){
			loop(i,0,n){
				if(1<<i&mask)
					T.g[i].hasB=1;
				else
					T.g[i].hasB=0;	
			}
			//ps(mask);
			best=min(best,S-T.dfs(0,-1));
			//entr;
		}
	}
	pln(best);
}
