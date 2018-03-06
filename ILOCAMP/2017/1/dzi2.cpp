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
 			ps(i+1);ps(g[i].ws);ps(g[i].ts);ps(g[i].maxk);pln(":");
 			loop(j,0,g[i].maxk+1){
 				ps(g[i].dpi[j]);
 			}
 			entr;
 			loop(j,0,g[i].maxk+1){
 				ps(g[i].dpo[j]);
 			}
 			entr;
 			foreach(it,g[i]){
 				cout<<it->v+1<<":"<<it->w<<"  ";
 			}
 			entr;
 			pln("----------------------");
 		}
 	}
 	int dfssize(int v, int l){
 		int s=0;
 		g[v].ts=0;
 		g[v].ws=0;
 		foreach(it,g[v]){
 			if(it->v!=l){
 				s=s+dfssize(it->v,v)+it->w;
 				g[v].ts+=g[it->v].ts;
 			}
 		}
 		g[v].ws=s;
 		g[v].ts++;
 		return s;
 	}
 	void dfs(int v, int l){
 		loop(i,0,g[v].ts+1){
 			g[v].dpi[i]=-1;
 			g[v].dpo[i]=-1;
 		}
 		int si=0;
 		foreach(it,g[v]){
 			if(it->v!=l) si+=it->w;
 		}
 		//g[v].dpi[0]=INFTY;
 		
 		g[v].dpi[0]=0;
 		g[v].dpo[0]=0;
 		g[v].maxk=max(1,g[v].ts);
 		//g[v].dpo[g[v].ts]=INFTY;
 		foreach(it,g[v]){
 			if(it->v!=l){
 				dfs(it->v,v);
 				loop(k,0,g[it->v].maxk+1){
	 				loopback(i,g[v].maxk,0){
						if(g[v].dpo[i]!=-1){
							if(k!=g[it->v].maxk&&i+k<g[v].maxk-1) g[v].dpo[i+k]=max(g[v].dpo[i+k],g[v].dpo[i]+g[it->v].dpo[k]);
							if(k!=0&&i+k<g[v].maxk-1) g[v].dpo[i+k]=max(g[v].dpo[i+k],g[v].dpo[i]+g[it->v].dpi[k]+it->w);
						} 				
	 					if(g[v].dpi[i]!=-1){
	 						
	 						if(k!=g[it->v].maxk&&i+k!=0) g[v].dpi[i+k]=max(g[v].dpi[i+k],g[v].dpi[i]+g[it->v].dpo[k]+it->w);
	 						if(k!=0&&i+k!=0){	
	 							
	 							g[v].dpi[i+k]=max(g[v].dpi[i+k],g[v].dpi[i]+g[it->v].dpi[k]);
	 						}
	 						//if(i+k==3) {ps(v);ps(it->v);ps(i);ps(k);ps(g[it->v].dpi[k]);pln(g[v].dpi[i]);pln(g[v].dpi[i+k]);}
	 					}
	 					ps(v);ps(it->v);ps(i);pln(k);
	 					coutTab(g[v].dpi,g[v].maxk+1);
	 					coutTab(g[v].dpo,g[v].maxk+1);pln("//////////////");
	 				}
	 			}	
 			}
 		}
 		g[v].dpi[1]=si;
 		g[v].dpi[g[v].maxk]=0;
 		g[v].dpo[g[v].maxk-1]=si;
 		g[v].dpo[g[v].maxk]=0;
 	}
};
int n;
struct Vv {
	int dpi[MAX],dpo[MAX];
	int maxk;
	int ts,ws;
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
	T.dfssize(0,-1);
	T.dfs(0,-1);
	T.coutT();
	pln((T.g[0].ws-max(T.g[0].dpi[k],T.g[0].dpo[k])));
}
