#include<bits/stdc++.h>
#define loop(i,j,n) for(int i=j;i<n;i++)
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"
#define pb push_back
#define SIZE(c) c.size()
#define ll long long
using namespace std;
typedef vector<int> VI;
const int MAX=1000100;
const ll MOD=1000000007;

int n;
template<class V,class E> struct Graph{
	struct Ed : E{
		int v;
		Ed(int w, E ee) : v(w), E(ee) {};
	};
	
	struct Ve : V, vector<Ed> {};
	vector<Ve> g;
	Graph(int n=0) : g(n){};
	
	void EdgeU(int a, int b, E e=E()){
		g[a].pb(Ed(b,e));
		g[b].pb(Ed(a,e));
	}
	void clearMatch(){
		loop(i,0,SIZE(g)){
			g[i].matching=-1;
			g[i].visited=0;
		}
	}
	void match(int v){
		if(v<n){
			loop(i,0,SIZE(g[v])){
				if(g[g[v][i].v].matching==-1){
					g[g[v][i].v].matching=v;
					g[v].matching=g[v][i].v;
					match(g[v][i].v);
				}
			}
		}else{
			loop(i,0,SIZE(g[v])){
				if(g[g[v][i].v].matching==-1){
					match(g[v][i].v);
				}
			}
		}
	}
	void coutG(){
		loop(i,0,SIZE(g)){
			ps(i+1);
			loop(j,0,SIZE(g[i])) ps(g[i][j].v+1);
			entr;
		}
	}
	void coutVis(){
		pln("visited");
		loop(i,0,SIZE(g)){
			ps(g[i].visited);
		}
		entr;
	}
	void matchRest(int v){
		if(v<n){
			loop(i,0,SIZE(g[v])){
				if(g[g[v][i].v].matching==-1){
					matchRest(g[v][i].v);
				}
			}
		}else{
			int c=0;
			loop(i,0,SIZE(g[v])){
				if(g[g[v][i].v].matching==-1) c++;
			}
			if(c==1){
				loop(i,0,SIZE(g[v])){
					if(g[g[v][i].v].matching==-1){
						g[g[v][i].v].matching=v;
						g[v].matching=g[v][i].v;
						matchRest(g[v][i].v);
					}
				}
			}
		}
	}
	ll countRes(int v){
		
		if(v<n){
			loop(i,0,SIZE(g[v])){
				if(!g[g[v][i].v].visited&&g[g[v][i].v].matching==-1){
					g[g[v][i].v].visited=1;
					return countRes(g[v][i].v);
				}
				return 1;
			}
		}else{
			ll res=1,c=0;
			loop(i,0,SIZE(g[v])){
				if(!g[g[v][i].v].visited&&g[g[v][i].v].matching==-1) c++;
			}
			loop(i,0,SIZE(g[v])){
				if(!g[g[v][i].v].visited&&g[g[v][i].v].matching==-1){
					
					g[g[v][i].v].visited=1;
					res=(res*countRes(g[v][i].v))%MOD;
				}
			}
			if(c==0) c=1;
			//ps(v);ps(c);pln(res);
			return (res*c)%MOD;
		}
	}
};
struct V{
	int matching;
	bool visited;
};
struct E{};
Graph<V,E> G;
bool precheck(){
	loop(i,n,2*n){
		if(SIZE(G.g[i])==0) return 0;
	}
	return 1;
}
bool check(){
	loop(i,0,n){
		if(G.g[i].matching==-1) return 0;
	}
	return 1;
}
void prog(){
	if(!precheck()){
		pln("NIE");
		pln(0);
		return;
	}
	G.clearMatch();
	loop(i,0,n){
		if(SIZE(G.g[i])==1) G.match(i);
	}
	if(check()){
		pln("TAK");
		loop(i,0,n){
			pln(G.g[i].matching-n+1);
		}
	}else{
		loop(i,n,2*n){
			if(SIZE(G.g[i])==1&&G.g[i].matching==-1){
				G.matchRest(i);
			}
		}
		loop(i,0,n){
			if(SIZE(G.g[i])==2){
				if(SIZE(G.g[G.g[i][0].v])==1&&SIZE(G.g[G.g[i][1].v])==1){
					pln("NIE");
					pln("0");
					return;
				}
			}
		}
		pln("NIE");
		ll res=1;
		loop(i,n,2*n){
			if(G.g[i].matching==-1&&!G.g[i].visited){ 
				G.g[i].visited=1;
				res=(res*G.countRes(i))%MOD;
			}
		}
		if(res==1) res--;
		pln(res);
	}
}
//-----------------------------------
int z[MAX][2];
VI perm,bestperm;
ll fact(int n){
	ll p=1;
	loop(i,2,n+1) p*=i;
	return p;
}
bool checkPerm(){
	loop(i,0,n){
		if(z[perm[i]][0]!=i&&z[perm[i]][1]!=i) return 0;
	}
	return 1;
}
int pos[MAX];

void brute(){
	loop(i,0,n){
		perm.pb(i);
	}
	int c=0;
	loop(i,0,fact(n)){
		if(checkPerm()){
			c++;
			bestperm=perm;
			
		}
		next_permutation(perm.begin(),perm.end());
	}
	if(c==1){
		pln("TAK");
		loop(i,0,n){
			pos[bestperm[i]]=i;
		}
		loop(i,0,n){
			pln(pos[i]+1);
		}
	}else{
		pln("NIE");
		pln(c);
	}

}
//--------------------------------------
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	G=Graph<V,E>(2*n);
	char t;
	int a,b;
	loop(i,0,n){
		cin>>t;
		if(t=='N'){
			cin>>a>>b;
			G.EdgeU(i,b-1+n);
			G.EdgeU(i,a-1+n);
			z[i][0]=a-1;
			z[i][1]=b-1;
		}else{
			cin>>a;
			G.EdgeU(i,a-1+n);
			z[i][0]=a-1;
			z[i][1]=-1;
		}
	}
	//G.coutG();
	if(n<10) brute();
	else prog();
	return 0;
}

