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
typedef pair<ll,ll> PLL;
const ll INFTY=1000000000000000000LL;
const int MAX=300100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
struct E{
	int v, i;
	ll c;
};
vector<vector<E> > G(MAX);
int last[MAX];
int lasti[MAX];
ll d[MAX];
int k;
int n;
void dijkstra(int w){
	priority_queue<PLL,vector<PLL >,std::greater<PLL > > Q;
	Q.push({0,w});
	d[0]=0;
	loop(i,1,n) d[i]=INFTY;
	while(!Q.empty()){
		PLL v=Q.top();
		Q.pop();
		if(d[v.ss]==v.ff){
			loop(i,0,G[v.ss].size()){
				if(v.ff+G[v.ss][i].c<d[G[v.ss][i].v]){
					d[G[v.ss][i].v]=v.ff+G[v.ss][i].c;
					last[G[v.ss][i].v]=v.ss;
					lasti[G[v.ss][i].v]=G[v.ss][i].i;
					Q.push({d[G[v.ss][i].v],G[v.ss][i].v});
				}
			}
		}
		
	}
}
int ak=0;
void print(vector<vector<E> > & T,int v,int l){
	if(last[v]!=-1) ps(lasti[v]+1);
	loop(i,0,SIZE(T[v])){
		if(T[v][i].v!=l&&ak<k){
			ak++;
			print(T,T[v][i].v,v);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	int m;
	cin>>n>>m>>k;;
	int a,b;
	ll c;
	loop(i,0,n) lasti[i]=-1;
	loop(i,0,n) last[i]=-1;
	loop(i,0,m){
		cin>>a>>b>>c;
		G[a-1].pb({b-1,i,c});
		G[b-1].pb({a-1,i,c});
	}
	dijkstra(0);
	G.clear();
	//loop(i,0,n) ps(last[i]); entr;
	vector<vector<E> > T(MAX);
	loop(i,1,n){
		T[i].pb({last[i],lasti[i],0});
		T[last[i]].pb({i,lasti[i],0});
	}
	pln(min(k,n-1));
	print(T,0,-1);
}
