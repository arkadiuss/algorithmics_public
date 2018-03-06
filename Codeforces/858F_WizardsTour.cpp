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
vector<VI > G(MAX);
int n;
void coutE(VI & e){
	loop(j,0,3){
		ps(e[j]+1);
	}
	entr;
}
template <class V,class E> struct  Graph{
	struct Ed : E{
		int v;
		Ed(E e, int w) : E(e), v(w){}; 
	};
	struct Ve : V, vector<Ed>{};
	vector<Ve> g;
	Graph(int n=0) : g(n){};
	
	void EdgeU(int a,int b,E e = E()){
		Ed eg=Ed(e,b);
		eg.rev=SIZE(g[b]);
		eg.b=0;
		g[a].pb(eg);
		eg=Ed(e,a);
		eg.b=0;
		eg.rev=SIZE(g[a])-1;
		g[b].pb(eg);
	}
	void coutG(){
		pln("G:");
		loop(i,0,SIZE(g)){
			ps(i+1);ps(":");
			loop(j,0,SIZE(g[i])){
				cout<<g[i][j].v+1<<":"<<g[i][j].rev<<":"<<g[i][j].b<<" ";
			}
			entr;
		}
	}
	int dfs(int v,vector<VI > & ans,int l){
		int lb=-1;
		int lf=-1;
		int ra,il=-1;
		VI eps;
		g[v].visited=1;
		//pln(v+1);
		loop(i,0,SIZE(g[v])){
			eps.erase(ALL(eps));
			if(g[g[v][i].v].visited&&g[v][i].v!=l&&!g[v][i].b){
				if(lb==-1) lb=i;
				else{
					eps.pb(g[v][lb].v);
					eps.pb(v);
					eps.pb(g[v][i].v);
					g[g[v][lb].v][g[v][lb].rev].b=1;
					g[g[v][i].v][g[v][i].rev].b=1;
					g[v][i].b=1;
					g[v][lb].b=1;
					//coutE(eps);
					//coutG();
					lb=-1;
					ans.pb(eps);
				}	
			}else if(!g[g[v][i].v].visited&&!g[v][i].b){
				ra=dfs(g[v][i].v,ans,v);
				//pln(v+1);
				if(ra==1&&lf==-1) lf=i;
				else if(ra==1&&lf!=-1){
					eps.pb(g[v][lf].v);
					eps.pb(v);
					eps.pb(g[v][i].v);
					g[g[v][lf].v][g[v][lf].rev].b=1;
					g[g[v][i].v][g[v][i].rev].b=1;
					g[v][i].b=1;
					g[v][lf].b=1;
					//coutE(eps);
					//coutG();
					lf=-1;
					ans.pb(eps);
				}		
			}else if(g[v][i].v==l){
				il=i;
			}
		}
		eps.erase(ALL(eps));
		if(lb!=-1&&lf!=-1){
			eps.pb(g[v][lb].v);
			eps.pb(v);
			eps.pb(g[v][lf].v);
			g[g[v][lf].v][g[v][lf].rev].b=1;
			g[g[v][lb].v][g[v][lb].rev].b=1;
			g[v][lb].b=1;
			g[v][lf].b=1;
			//coutE(eps);
			//coutG();
			lf=-1;
			lb=-1;
			ans.pb(eps);
		}
		if((lf!=-1||lb!=-1)&&il!=-1){
			if(lf==-1) lf=il;
			else lb=il;
			eps.pb(g[v][lf].v);
			eps.pb(v);
			eps.pb(g[v][lb].v);
			g[g[v][lf].v][g[v][lf].rev].b=1;
			g[g[v][lb].v][g[v][lb].rev].b=1;
			g[v][lb].b=1;
			g[v][lf].b=1;
			//coutE(eps);
			//coutG();
			ans.pb(eps);
			return 0;
		}else return 1;
	}
	
};
struct E{
	int rev;
	bool b;
};
struct V{
	bool visited;
};

int main(){
	ios_base::sync_with_stdio(0);
	int m;
	cin>>n>>m;
	Graph<V,E> g(n);
	int a,b;
	loop(i,0,m){
		cin>>a>>b;
		g.EdgeU(a-1,b-1);
	}
	vector<vector<int> > ans;
	loop(i,0,n){
		if(!g.g[i].visited)g.dfs(i,ans,-1);
	}
	pln(SIZE(ans));
	loop(i,0,SIZE(ans)){
		coutE(ans[i]);
	}
}
