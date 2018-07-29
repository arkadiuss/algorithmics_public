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
const ll MOD=1000000007;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
ll powerMod(ll a,ll n){
	if(n==0) return 1;
	else if(n==1) return a;
	else if(n%2==0){
		ll tmp=powerMod(a,n/2);
		return (tmp*tmp)%MOD;
	}
	else return (a*powerMod(a,n-1))%MOD;
}
struct mem{
	ll i;
	ll w;
	
};
bool operator<(const mem & a,const mem & b){
	return a.i<b.i;
}
mem mm(ll i,ll w){
	mem m;
	m.i=i;
	m.w=w;
	return m;
}
set<mem> mems;
ll f(ll x){
	if(x==1) return 1;
	VAR(it,mems.find(mm(x,0)));
	if(it!=mems.end()) return it->w;
	ll res=powerMod(2,x-1);
	for(ll d=2;d<=sqrt(x);d++){
		if(x%d==0){ 
			res-=f(x/d);
			if(d!=x/d) res-=f(d);
			while(res<0) res+=MOD;
		}
	}
	mems.insert(mm(x,res-1));
	return res-1;
}
int main(){
	ios_base::sync_with_stdio(0);
	ll x,y;
	cin>>x>>y;
	if(y%x==0){
		pln(f(y/x));
	}
	else pln(0);
}
