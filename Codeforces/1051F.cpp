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
typedef vector<ll> VLL;
typedef pair<int,int> PII;
const ll INFTY=200000000000000000;
const int MAX=100100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
struct Ver{
	int v;
	ll d;
	Ver(int _v,ll _d) : v(_v),d(_d){};
	bool operator<(const Ver & b) const{
		return v<b.v;
	}
};
typedef vector<Ver> VV;
vector<VV > G(MAX);
int n,m;
map<int,VLL > fromAdd;
struct Triple{
	ll a,b,c;
	Triple(ll _a,ll _b, ll _c): a(_a),b(_b),c(_c){};
};
set<PII > adds;
vector<Triple> addsT;
int h[MAX];
ll dist[MAX];
vector<ll> dijkstra(int v){
	ll * d=new ll[n];
	loop(i,0,n) d[i]=INFTY;
	d[v]=0;
	priority_queue<Ver> Q;
	Q.push(Ver(v,0));
	while(!Q.empty()){
		int w = Q.top().v;
		Q.pop();
		loop(i,0,SIZE(G[w])){
			if(d[w]+G[w][i].d<d[G[w][i].v]){
				d[G[w][i].v]=d[w]+G[w][i].d;
				Q.push(Ver(G[w][i].v,d[G[w][i].v]));
			}
		}
	}
	vector<ll> res(d,d+n);
	delete [] d;
	return res;
}
bool visited[MAX];
vector<int> ord;
void countAll(int v,int l){
	visited[v]=1;
	ord.pb(v);
	loop(i,0,SIZE(G[v])){
		if(!visited[G[v][i].v]){
			h[G[v][i].v]=h[v]+1;
			dist[G[v][i].v]=dist[v]+G[v][i].d;
			countAll(G[v][i].v,v);
			ord.pb(v);
		}else if(G[v][i].v!=l){
			if(adds.find({min(v,G[v][i].v),max(v,G[v][i].v)})==adds.end()){
				adds.insert({min(v,G[v][i].v),max(v,G[v][i].v)});
				addsT.pb(Triple(min(v,G[v][i].v),max(v,G[v][i].v),G[v][i].d));
				fromAdd[v]=dijkstra(v);
				fromAdd[v].pb(G[v][i].d);
				fromAdd[G[v][i].v]=dijkstra(G[v][i].v);
				fromAdd[G[v][i].v].pb(G[v][i].d);
			}
		}
	}
}
int pos[MAX];
int tree[20*MAX];
int D;
void countD(){
	D=1;
	while(D<=SIZE(ord)){
		D*=2;
	}
}
int minpos(int i,int j){
	if(i>=SIZE(ord)) return j;
	if(j>=SIZE(ord)) return i;
	if(h[ord[i]]<=h[ord[j]]) return i;
	return j;
}
void initTree(){
	loop(i,0,n) pos[i]=-1;
	loop(i,0,SIZE(ord)) if(pos[ord[i]]==-1) pos[ord[i]]=i;
	loop(i,D,2*D) tree[i]=i-D;
	loopback(i,D-1,1) tree[i]=minpos(tree[2*i],tree[2*i+1]);
}
int LCA(int L,int R){
	L+=D;
	R+=D;
	int minp=tree[L];
	while(L<R){
		if(L%2==1) minp=minpos(minp,tree[L]);
		if(R%2==0) minp=minpos(minp,tree[R]);
		L=(L+1)/2;
		R=(R-1)/2;
	}
	if(L==R) minp=minpos(minp,tree[L]);
	return ord[minp];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	int a,b;
	ll c;
	loop(i,0,m){
		cin>>a>>b>>c;
		G[a-1].pb(Ver(b-1,c));
		G[b-1].pb(Ver(a-1,c));
	}
	h[0]=0;
	dist[0]=0;
	countAll(0,-1);
	countD();
	initTree();
	int q,u,v;
	cin>>q;
	while(q--){
		cin>>u>>v;
		u--;
		v--;
		int l = LCA(min(pos[u],pos[v]),max(pos[u],pos[v]));
		ll mind = dist[u]+dist[v]-2*dist[l];
		for(auto i: addsT){
			mind=min(mind,fromAdd[i.a][u]+fromAdd[i.b][v]+i.c);
			mind=min(mind,fromAdd[i.b][u]+fromAdd[i.a][v]+i.c);
		}
		pln(mind);
	}
}
