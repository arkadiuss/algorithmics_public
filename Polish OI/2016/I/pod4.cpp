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
const int MAX=1000100;
const int MOD=10000000;

void coutTab(ll* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
ll mod;
int B;
ll a[MAX];
ll pref[MAX];
void countMod(){
	mod=0;
	ll p=1;
	//ll p2=1;
	for(ll i=0;i<B;i++){
		ll tmp=(a[i]*i);
		tmp=tmp%(B-1);
		mod=(mod+(tmp)*p)%(B-1);
		p=(p*B)%(B-1);
		//p2=p2*B;
	}
}
void remA(ll v){
	if(v>0){
		remA(v/B);
		cout<<v%B<<" ";
		a[v%B]--;
	}
}
void countPref(){
	pref[0]=0;
	loop(i,1,B+1){
		pref[i]=pref[i-1]+a[i-1];
	}
}
int find(ll x){
	int s=0;
	int e=B+1;
	int m;
	while(s<e){
		m=(s+e)/2;
		//cout<<m<<"\n";
		if(pref[m]<=x)
			s=m+1;
		else
			e=m;	
	}
	//cout<<m<<"\n";
	return s;
}	
int main(){
	ios_base::sync_with_stdio(0);
	int q;
	cin>>B>>q;
	loop(i,0,B){
		cin>>a[i];
	}
	countMod();
	pln(mod);
	remA(mod);
	entr;
	ll k;
	countPref();
	//coutTab(pref,B+1);
	loop(z,0,q){
		cin>>k;
		if(z==42578){
		cout<<k<<"\n";
		cout<<pref[90874]<<"\n";
		if(k>=pref[B])
			pln(-1);
		else	
			pln(find(k)-1);
		}
	}
}
