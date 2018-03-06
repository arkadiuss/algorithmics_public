#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define ff first
#define ss second
#define mp make_pair
using namespace std;
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
int n,k;
struct E{
	int v, cost;
	int tmin;
};
vector< vector<E> >G(MAX);
int min_cost[MAX];
int depth[MAX];
pair<int,int> bfs(int a){
	loop(i,0,n){
		min_cost[i]=INFTY;
	}
	queue<int> Q;
	Q.push(a);
	min_cost[a]=0;
	depth[a]=0;
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		loop(i,0,G[v].size()){
			if(min_cost[G[v][i].v]>min_cost[v]+G[v][i].cost){
				min_cost[G[v][i].v]=min_cost[v]+G[v][i].cost;
				depth[G[v][i].v]=depth[v]+1;
				Q.push(G[v][i].v);
			}
		}
	}
	int maxcost=0,maxcost2=0;
	loop(i,0,n){
		if(min_cost[i]>=min_cost[maxcost]){
			maxcost2=maxcost;
			maxcost=i;
		}
	}
	return mp(maxcost,maxcost2);
}
int dec(int v,int toDec,int l){
	int left=toDec;
	//ps(v);
	loop(i,0,G[v].size()){
		if(depth[G[v][i].v]==depth[v]-1){
			left=dec(G[v][i].v,toDec,v);
			loop(j,0,G[G[v][i].v].size()){
				if(G[G[v][i].v][j].v==v){
					G[v][i].cost=G[G[v][i].v][j].cost;
				}
			}
		}
	}
	int newleft;
	loop(i,0,G[v].size()){
		if(G[v][i].v==l){
			newleft=left-min(left,G[v][i].cost);
			G[v][i].cost=max(0,G[v][i].cost-left);
		}
	}
	return newleft;
}
void coutTree(){
	loop(i,0,n){
		ps(i);
		ps(": ");
		loop(j,0,G[i].size()){
			cout<<G[i][j].v<<"|"<<G[i][j].cost<<"  "; 	
		}
		entr;
	}
	entr;
}
int lastbfs(int a){
	loop(i,0,n){
		min_cost[i]=INFTY;
	}
	queue<int> Q;
	Q.push(a);
	min_cost[a]=0;
	depth[a]=0;
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		loop(i,0,G[v].size()){
			if(min_cost[G[v][i].v]>min_cost[v]+G[v][i].cost){
				min_cost[G[v][i].v]=min_cost[v]+G[v][i].cost+G[v][i].tmin;
				depth[G[v][i].v]=depth[v]+1;
				Q.push(G[v][i].v);
			}
		}
	}
	int maxcost=0;
	loop(i,0,n){
		maxcost=max(maxcost,min_cost[i]);
	}
	return maxcost;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	int a,b,t,tmin;
	loop(i,0,n-1){
		cin>>a>>b>>t>>tmin;
		E e;
		e.cost=t-tmin;
		e.tmin=tmin;
		e.v=a-1;
		G[b-1].push_back(e);
		e.v=b-1;
		G[a-1].push_back(e);
	}
	bfs(0);
	while(k>0){
		pair<int,int> p = bfs(0);
		dec(p.ff,min(k,min_cost[p.ff]-min_cost[p.ss]+1),-1);
		k=k-(min_cost[p.ff]-min_cost[p.ss]+1);
	}
	cout<<lastbfs(0);
}
