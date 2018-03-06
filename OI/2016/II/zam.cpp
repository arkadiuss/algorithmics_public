#include<bits/stdc++.h>
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define VAR(i,c) __typeof(c) i=(c)
#define foreach(it,c) for(VAR(it,c.begin());it!=c.end();it++)
#define SIZE(c) c.size()
#define ALL(c) c.begin(), c.end()
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"
#define ll long long
#define pb push_back
using namespace std;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MAX=1000100;
template<class V, class E> struct Graph{
	int strt,ed;
	struct Ed : E{
		int v;
		Ed(int w,E ee) : v(w), E(ee) {};
	};
	struct Ve : V, vector<Ed>{};
	vector<Ve> g;
	Graph(int n=0) : g(n){};
	void EdgeU(int a, int b, E e=E()){
		g[a].pb(Ed(b,e));
		g[b].pb(Ed(a,e));
	}
	void clearB(){
		loop(i,0,SIZE(g)){ 
			g[i].blocked=0;
			g[i].d=-1;	
		}
	}
	void coutG(){
		ps(strt);pln(ed);
		loop(i,0,SIZE(g)){
			ps(i);ps(g[i].blocked);ps(":");
			loop(j,0,SIZE(g[i])){
				ps(g[i][j].v);
			}
			entr;
		}
		
	}
	int bfs(int s, int e){
		queue<int> Q;
		Q.push(s);
		g[s].d=0;
		while(!Q.empty()){
			int v=Q.front();
			Q.pop();
			//ps(v);
			loop(i,0,SIZE(g[v])){
				if(!g[g[v][i].v].blocked&&g[g[v][i].v].d==-1){
					g[g[v][i].v].d=g[v].d+1;
					Q.push(g[v][i].v);
				}
			}
		}
		return g[e].d;
	}
};
struct V{
	bool blocked;
	int d;
};
struct E{};
int w,h,n,m;
Graph<V,E> G;
struct rec{
	int x1,y1;
	int x2,y2;
	int id;
};
rec mr(int x1,int y1,int x2,int y2,int id){
	rec r;
	r.x1=x1;
	r.x2=x2;
	r.y1=y1;
	r.y2=y2;
	r.id=id;
	return r;
}
struct p{
	int x,y;
};
p mp (int x,int y){
	p pi;
	pi.x=x;
	pi.y=y;
	return pi;
}
p st,en;
vector<rec> rs;
vector<p> ps;
bool checkRec(rec a, rec b){
	if((min(a.x1,a.x2)<b.x1&&max(a.x1,a.x2)>b.x1)||
		(min(a.x1,a.x2)<b.x2&&max(a.x1,a.x2)>b.x2)||
		(min(a.x1,a.x2)==min(b.x1,b.x2)&&
		max(a.x1,a.x2)==max(b.x1,b.x2))){
		if(a.y1==b.y1||
			a.y1==b.y2||
			a.y2==b.y1||
			a.y2==b.y2){
				return 1;
		}	
	}
	if((min(a.y1,a.y2)<b.y1&&max(a.y1,a.y2)>b.y1)||
		(min(a.y1,a.y2)<b.y2&&max(a.y1,a.y2)>b.y2)||
		(min(a.y1,a.y2)==min(b.y1,b.y2)&&
			max(a.y1,a.y2)==max(b.y1,b.y2))){
		if(a.x1==b.x1||
			a.x1==b.x2||
			a.x2==b.x1||
			a.x2==b.x2){
				return 1;
		}		
	}
	return 0;
}
void createGraph(){
	loop(i,0,n){
		loop(j,0,n){
			if(i!=j&&checkRec(rs[i],rs[j])){
				G.EdgeU(rs[i].id,rs[j].id);
			}
		}
	}
}
bool checkRecP(rec a, p b){
	//ps(a.x1);ps(a.x2);pln(b.x);
	//ps(a.y1);ps(a.y2);pln(b.y);
	//entr;
	if(min(a.x1,a.x2)<b.x&&max(a.x1,a.x2)>b.x&&
		min(a.y1,a.y2)<b.y&&max(a.y1,a.y2)>b.y)
			return 1;
	return 0;		
}
void blockPoints(){
	loop(i,0,n){
		loop(j,0,m){
			if(checkRecP(rs[i],ps[j])) 
				G.g[rs[i].id].blocked=1;
		}
	}
}
void findStEn(){
	loop(i,0,n){
		if(checkRecP(rs[i],st)) G.strt=rs[i].id;
		if(checkRecP(rs[i],en)) G.ed=rs[i].id;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>w>>h>>n>>m;
	G=Graph<V,E>(n);
	cin>>st.x>>st.y;
	cin>>en.x>>en.y;
	int x1,x2,y1,y2;
	loop(i,0,n){
		cin>>x1>>y1>>x2>>y2;
		rs.pb(mr(x1,y1,x2,y2,i));
	}
	loop(i,0,m){
		cin>>x1>>y1;
		ps.pb(mp(x1,y1));
	}
	G.clearB();
	createGraph();
	blockPoints();
	findStEn();
	//G.coutG();
	pln(G.bfs(G.strt,G.ed)+1);
	return 0;
}

