#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define mp make_pair
#define ff first 
#define ss second
using namespace std;
const int INFTY=20000000;
const int MAX=1000100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
;
int n;
struct V{
	int v;
	int cost;
};
vector< vector<V> > G(MAX);
int costs[MAX]={0};
int dijkstra(int a, int b){
	set< pair<int,int> > Q;
	loop(i,0,2*n+1){
		costs[i]=INFTY;
	}
	costs[a]=0;
	Q.insert(mp(0,a));
	while(!Q.empty()){
		pair<int,int> v = (*Q.begin());
		//ps(v.ss);
		Q.erase(Q.begin());
		loop(i,0,G[v.ss].size()){
			
			if(costs[v.ss]+G[v.ss][i].cost<costs[G[v.ss][i].v]){
				Q.erase(mp(costs[G[v.ss][i].v],G[v.ss][i].v));
				costs[G[v.ss][i].v]=costs[v.ss]+G[v.ss][i].cost;
				Q.insert(mp(costs[G[v.ss][i].v],G[v.ss][i].v));
			}
		}
	}
	return costs[b];
}

int main(){
	ios_base::sync_with_stdio(0);
	int mp,mj,p,j;
	cin>>n>>p>>j;
	cin>>mp;
	int a,b;
	loop(i,0,mp){
		cin>>a>>b;
		V tmp;
		tmp.v=b-1;
		tmp.cost=0;
		G[a-1].push_back(tmp);
	}
	cin>>mj;
	loop(i,0,mj){
		cin>>a>>b;
		V tmp;
		tmp.v=b+n-1;
		tmp.cost=0;
		G[a+n-1].push_back(tmp);
	}
	loop(i,0,n){
		V tmp;
		tmp.v=i+n;
		tmp.cost=1;
		G[i].push_back(tmp);
		tmp.v=i;
		G[i+n].push_back(tmp);
	}
	int ans=dijkstra(p-1,j-1+n);
	if(ans==INFTY)	
		cout<<"NIE";
	else
		cout<<ans;	
}
