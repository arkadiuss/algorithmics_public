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
#define mp make_pair
using namespace std;
const int MAX=1000100;
const int MOD=1000000000;
const int INFTY=1000000000;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<bool,int> PBI;
void coutTab(int * tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------
int n;
template<class V, class E> struct Tree{
	
	struct Ed : E{
		int v;
		Ed(E e,int w) : E(e), v(w) { };
	};
	
	struct Ve : V, vector<Ed> { };
	vector<Ve> g;
	Tree(int n=0) : g(n) {};
	
	void EdgeU(int a, int b, E e=E()){
		g[a].pb(Ed(e,b));
		g[b].pb(Ed(e,a));
	}
	
	PBI dfs(int v, int l){
		PBI res,fs;
		res.ff=1;
		res.ss=-1;
		foreach(it,g[v]){
			if(it->v!=l){
				if(res.ss==-1) res=dfs(it->v,v);
				else{
					fs=dfs(it->v,v);
					res.ff=res.ff&&fs.ff;
					if(res.ss!=fs.ss) res.ff=0;
				}
			}
		}
		res.ss++;
		return res;
	}
	bool dfs2(int v,int l,int d){
		g[v].d=d;
		foreach(it,g[v]){
			if(it->v!=l) dfs2(it->v,v,d+1);
		}
	}
};
struct V {
	int d;
};
struct E {};
Tree<V,E> T;
bool was(int a, int b){
	foreach(it,T.g[a]){
		if(it->v==b) return 1;
	}
	return 0;
}
int hm[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	T=Tree<V,E>(n+100);
	int a,b;
	loop(i,0,n-1){
		cin>>a>>b;
		T.EdgeU(a-1,b-1);
	}
	PII AB;
	AB.ff=-1;
	AB.ss=-1;
	loop(i,0,n){
		if(SIZE(T.g[i])>2){
			if(AB.ff!=-1&&AB.ss!=-1){
				pln("NIE");
				return 0;
			}else if(AB.ff!=-1){
				AB.ss=i;
			}else{
				AB.ff=i;
			}
		}
	}
	//ps(AB.ff);pln(AB.ss);
	if(AB.ff==-1&&AB.ss==-1){
		pln("TAK");
		return 0;
	}else if(AB.ff==-1||AB.ss==-1){
		T.dfs2(AB.ff,-1,0);
		int il=0,il2=0;
		loop(i,0,n){
			if(T.g[i].size()==1){ 
				hm[T.g[i].d]++;
				if(hm[T.g[i].d]>1){ 
					il++;
					hm[T.g[i].d]=-INFTY;
					il2++;
				}
				if(il>1){
					pln("NIE");
					return 0;
				}
			}
		}
		loop(i,0,n){
			if(hm[i]>=1){ 
				il2++;
			}
		}
		if(il2>2){
			pln("NIE");
			return 0;
		}
		pln("TAK");
	}else{
		if(!was(AB.ff,AB.ss)){ 
			pln("NIE");
			return 0;
		}
		if(T.dfs(AB.ff,AB.ss).ff&&T.dfs(AB.ss,AB.ff).ff) pln("TAK");
		else pln("NIE");
	}
}
