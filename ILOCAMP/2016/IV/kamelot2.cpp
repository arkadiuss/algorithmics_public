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
int n;
ll k;
struct E{
	int v;
	ll cost;
	ll tmin;
	ll undertreesize;
};
vector< vector<E> >G(MAX);
ll countLens(int v,int l){
	if(G[v].size()==1&&l!=-1){
		return 0;
	}
	ll maxlen=0;
	loop(i,0,G[v].size()){
		if(G[v][i].v!=l){
			ll tmplen=countLens(G[v][i].v,v);
			G[v][i].undertreesize=tmplen;
			maxlen=max(maxlen,tmplen+G[v][i].cost);
		}
	}
	return maxlen;
}
void coutLens(){
	loop(i,0,n){
		ps(i);
		ps(":");
		loop(j,0,G[i].size()){
			cout<<G[i][j].undertreesize<<" ";
		}
		entr;
	}
}
ll current;
bool check(int v, ll act_size, ll x, int l){
	if(act_size>x) return 0;
	bool can=1;
	//cout<<v<<" ";
	loop(i,0,G[v].size()){
		if(G[v][i].v!=l){
			//cout<<"|"<<G[v][i].v<<"|"<<G[v][i].undertreesize+G[v][i].cost+act_size<<"| ";
			if(G[v][i].undertreesize+G[v][i].cost+act_size>x){
				
				ll tmpold=current;
				current=current-min(min(current,(G[v][i].undertreesize+G[v][i].cost+act_size)-x), (G[v][i].cost-G[v][i].tmin));
				//cout<<tmpold<<"-";ps(current);
				if(G[v][i].undertreesize+G[v][i].cost-(tmpold-current)+act_size>x){
					if(current<=0) return 0;
					else can=can&&check(G[v][i].v, act_size+G[v][i].cost-(tmpold-current), x, v);
				}else{
					can=can&&true;
				}	 
			}else{
				can=can&&true;
			}
		}
	}
	return can;
}
ll  maxlen;
ll bind(){
	ll s=0;
	ll e=maxlen*10;
	ll mid=(s+e)/2;
	while(s<e){
		//cout<<mid<<" ";
		current=k;
		if(check(0, 0, mid, -1)){
			e=mid;
		}else
			s=mid+1;
		mid=(s+e)/2;	
	}
	return s;
} 
ll brutally(){
	int x=1;
	current=k;
	while(!check(0,0,x,-1)){
		//entr;
		x++;
		current=k;
		//cout<<x<<": ";
	}
	return x;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	ll a,b,t,tmin;
	loop(i,0,n-1){
		cin>>a>>b>>t>>tmin;
		E e;
		e.cost=t;
		e.tmin=tmin;
		e.v=a-1;
		G[b-1].push_back(e);
		e.v=b-1;
		G[a-1].push_back(e);
	}
	maxlen=countLens(0,-1);
	//coutLens();
	cout<<bind();//<<" "<<brutally();
}
