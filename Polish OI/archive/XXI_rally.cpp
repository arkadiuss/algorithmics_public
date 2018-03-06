#include<bits/stdc++.h>
#define VAR(v,n) __typeof(n) v = (n)
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define foreach(i,c) for(VAR(i,c.begin());i!=c.end();i++)
#define ps( v ) cout<<v<<" "
#define pln( v ) cout<<v<<"\n"
#define entr cout<<"\n"
#define pb( v ) push_back( v );
#define ff first
#define ss second
#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ((int) (x).size())

using namespace std;
typedef vector<int> VI;

const int MAX=621000;
const int INFTY=1001000;


void coutTab(int* tab,int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//------------------------

template<class V, class E> struct Graph{
	
	struct Ed : E{
		int v;
		Ed(E e, int w) : E(e), v(w) { }
	};
	
	struct Ve : V, vector<Ed> { };
	
	vector<Ve> g;
	
	Graph(int n=0) : g(n) { };
	
	void EdgeD(int a, int b, E e = E()){
		g[a].pb(Ed(e,b));
	}
	
	void EdgeU(int a,int b,E e = E()){
		g[a].pb(Ed(e,b));
		g[b].pb(Ed(e,a));
	}
	
	void coutG(){
		pln("Couting graph");
		loop(i,0,SIZE(g)){
			ps(g[i].nr);
			ps(g[i].top_nr);
			ps(g[i].longestStart);
			ps(g[i].longestEnd);
			ps(g[i].longestAfter);
			ps(g[i].longestBefore);
			ps(": ");
			foreach(j,g[i]){
				ps(j->v+1);
			}
			entr;
		}
	}
	
	stack<int> S;
	void topological_dfs_numering(int v){
		g[v].top_col=1;
		foreach(it,g[v]){
			if(g[it->v].top_col==0){
				topological_dfs_numering(it->v);
			}
		}
		g[v].top_col=2;
		S.push(v);
	}
	static bool toSortTopological(Ve a, Ve b){
		return a.top_nr<b.top_nr;
	}
	static bool toSortTopological2(Ve a, Ve b){
		return a.nr<b.nr;
	}
	void topological_numering(){
		int num=0;
		foreach(it,g)
		{
			it->top_nr=0;
			it->nr=++num;
		}
		loop(i,0,SIZE(g)){
			if(g[i].top_col==0)
				topological_dfs_numering(i);
		}
		num=0;
		
		while(!S.empty()){
			g[S.top()].top_nr=num++;
			S.pop();
		}
		loop(i,0,SIZE(g)){
			foreach(it,g[i]){
				it->v=g[it->v].top_nr;
			}
		}
		sort(ALL(g),toSortTopological);
	}
	void countLongest(){
		foreach(i,g){
			i->longestStart=0;
			i->longestEnd=0;
		}
		loopback(i,SIZE(g)-1,0){
			foreach(j,g[i]){
				g[i].longestStart=max(g[i].longestStart,g[j->v].longestStart+1);
			}
		}
		int best=g[SIZE(g)-1].longestStart;
		loopback(i,SIZE(g)-1,0){
			g[i].longestAfter=best;
			best=max(best,g[i].longestStart);
		}
		loop(i,0,SIZE(g)){
			foreach(j,g[i]){
				g[j->v].longestEnd=max(g[j->v].longestEnd,g[i].longestEnd+1);
			}
		}
		best=g[0].longestEnd;
		loop(i,0,SIZE(g)){
			g[i].longestBefore=best;
			best=max(g[i].longestEnd,best);
		}
		//coutG();
		//sort(ALL(g),toSortTopological2);
	}  
};
struct V{
	int nr;
	int top_nr;
	int top_col;
	
	int longestStart,longestEnd,longestBypass;
	int longestBefore, longestAfter;
};

struct E{

};
int d;
int n,m;
int tree[2*MAX];
void countD(){
	d=1;
	while(d<n){
		d=d*2;
	}
}
void createTree(){
	loop(i,0,2*d){
		tree[i]=0;
	}
}
void setMax(int L,int R, int v){
	L=L+d;
	R=R+d;
	while(L<R){
		if(L%2==1) tree[L]=max(tree[L],v);
		if(R%2==0) tree[R]=max(tree[R],v);
		L=(L+1)/2;
		R=(R-1)/2;
	}
	if(L==R) tree[L]=max(tree[L],v);
}
int readMax(int v){
	v=v+d;
	int val=0;
	while(v>0){
		val=max(val,tree[v]);
		v=v/2;
	}
	return val;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	Graph<V,E> G(n);
	int a,b;
	loop(i,0,m){
		cin>>a>>b;
		G.EdgeD(a-1,b-1);
	}
	G.topological_numering();
	G.countLongest();
	//G.coutG();
	countD();
	createTree();
	loop(i,0,n){
		foreach(it,G.g[i]){
			//cout<<G.g[i].top_nr+1<<" "<<G.g[it->v].top_nr-1<<" "<<G.g[i].longestEnd+1+G.g[it->v].longestStart<<"\n";
			setMax(i+1,it->v-1,G.g[i].longestEnd+1+G.g[it->v].longestStart);
			//coutTab(tree,2*d);
		}
		
	}
	
	int besti=0,minway=INFTY;
	loop(i,0,n){
		
		int tmp=max(G.g[i].longestBefore,max(G.g[i].longestAfter,readMax(G.g[i].top_nr)));
		//cout<<i+1<< " "<<readMax(i)<<"\n";
		if(tmp<minway){
			besti=i;
			minway=tmp;
		}
	}
	ps(G.g[besti].nr);
	pln(minway);
}

