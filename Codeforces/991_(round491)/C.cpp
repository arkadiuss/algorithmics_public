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
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
ll eat(ll n,ll k){
	ll rem=n;
	ll e=0;
	while(rem>0){
		e+=min(rem,k);
		rem-=min(rem,k);
		rem-=rem/10;
	}
	return e;
}
ll fnd(ll n){
	ll s=1;
	ll e=n;
	while(s<e){
		ll k=(s+e)/2;
		//ps(s);ps(e);cout<<k<<endl;
		if(eat(n,k)>=(n+1)/2){
			e=k;
		}else{
			s=k+1;
		}
	}
	return s;
}
int main(){
	ios_base::sync_with_stdio(0);
	ll n,k;
	cin>>n;
	pln(fnd(n));
}
