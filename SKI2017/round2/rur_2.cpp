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
const int MAX=100100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
ll x[MAX],y[MAX];
int n,s,w;
pair<ll,ll> count(ll t[MAX],ll d,ll p){
	ll SL=0,SR=0;
	loop(i,0,n){
		if(t[i]<p) SL+=abs(p-t[i]);
		else if(t[i]>p+d) SR+=abs(p+d-t[i]);
	}
	return mp(SL,SR);
}
ll countBest(ll t[MAX],ll d){
	sort(t,t+n);
	ll mini=INFTY;
	loop(i,t[0],t[n-1]+1){
		pair<ll,ll> ans=count(t,d,i);
		mini=min(mini,ans.ff+ans.ss);
		//ps(i);ps(ans.ff);pln(ans.ss);
	}
	//entr;
	return mini;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>s>>w;
	loop(i,0,n){
		cin>>x[i]>>y[i];
	}
	pln(countBest(x,s)+countBest(y,w));
}
