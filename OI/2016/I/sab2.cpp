/*
*Arkadiusz Kraus
*/
#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
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
vector< vector<int> > G(MAX);
int sizeOfUndertree[MAX];
int linemanager[MAX];
void prepareToCountSOU(){
	loop(i,0,n){
		sizeOfUndertree[i]=0;
	}
}
int countSOU(int v, int l){
	if(G[v].size()==1&&v!=0) return 0;
	loop(i,0,G[v].size()){
		if(G[v][i]!=l){
			sizeOfUndertree[v]+=countSOU(G[v][i],v)+1;
		}
	}
	return sizeOfUndertree[v];
}
int check(int v,int l,double x){
	if(G[v].size()==1&&v!=0)
		return 1;
	int maxrebel=0;
	double m;
	
	loop(i,0,G[v].size()){
		m=maxrebel;
		m=m/sizeOfUndertree[v];
		if(G[v][i]!=l&&m<x)
			maxrebel=max(maxrebel,check(G[v][i],v,x));
	}
	m=maxrebel;
	m=m/sizeOfUndertree[v];
	if(m>=x){
		maxrebel=sizeOfUndertree[v]+1;
	}
	return maxrebel;		
}
double morale(){
	ll prec=100000000;
	ll s=0,e=prec;
	double x;
	double m;
	while(s<e){
		m=(s+e)/2;
		x=m;
		x=x/prec;
		
		if(check(0,-1,x)<=k){
			e=m;		
		}else{
			s=m+1;
		}
		//entr;
	}
	return e/(1.0*prec);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	int a;
	loop(i,1,n){
		cin>>a;
		G[i].pb(a-1);
		G[a-1].pb(i);
		linemanager[i]=a-1;
	}
	prepareToCountSOU();
	countSOU(0,-1);
	//coutTab(sizeOfUndertree,n);
	//coutTab(linemanager,n);
	//cout<<check(0,-1,0.67)<<"\n";
	cout<<fixed<<setprecision(8)<<morale();
}
