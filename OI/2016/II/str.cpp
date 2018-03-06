#include<bits/stdc++.h>
#define loop(i,j,n) for(int i=j;i<n;i++)
#define ll long long
#define VAR(i,n) __typeof(n) i = (n)
#define foreach(i,c) for(VAR(i,c.begin());i!=c.end();i++)
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define SIZE(c) c.size()
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"
using namespace std;

const int MAX=1000010;
//------------------
template<class V, class E> struct Graph{
	int S;
	struct Ed : E{
		int v;
		Ed(int w, E ee) : v(w), E(ee) {};
	};
	struct Ve : V, vector<Ed>{};
	vector<Ve> g;
	Graph(int n=0) : g(n) {};
	
	void EdgeU(int a, int b, E e=E()){
		g[a].pb(Ed(b,e));
		g[b].pb(Ed(a,e));
	}
	void clearB(){
		foreach(it,g){
			it->blocked=0;
		}
	}
	void rmv(int v){
		int c=0;
		loop(i,0,SIZE(g[v])){
			if(!g[g[v][i].v].blocked) c++;
		}
		c--;
		S+=c;
	}
	void add(int v){
		int c=0;
		loop(i,0,SIZE(g[v])){
			if(!g[g[v][i].v].blocked) c++;
		}
		c--;
		S=S-c;
	}
};
struct V{
	bool blocked;
};
struct E{};
int n;
Graph<V,E> G;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	G=Graph<V,E>(n);
	int a,b;
	G.S=1;
	loop(i,0,n-1){
		cin>>a>>b;
		G.EdgeU(a-1,b-1);
	}
	int q,z;
	G.clearB();
	cin>>q;
	loop(i,0,q){
		cin>>z;
		if(z<0){ 
			G.g[abs(z)-1].blocked=0;
			G.add(abs(z)-1);
		}else{ 
			G.g[z-1].blocked=1;
			G.rmv(z-1);
		}	
		pln(G.S);
	}
	return 0;
}
