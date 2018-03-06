#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define foreach(i,c) for(VAR(i,c.begin());i!=c.end();i++)
#define SIZE(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"
#define ll long long
#define pb(v) push_back(v)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
const int MAX=1e6;
const ll MAXVAL=4*1e17;

using namespace std;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef pair<ll,ll> PLL;

void coutTab(int* tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//-----------------------------
VLL fib;
void countFib(){
	fib.pb(0);
	fib.pb(1);
	while(fib[SIZE(fib)-1]<MAXVAL){
		fib.pb(fib[SIZE(fib)-1]+fib[SIZE(fib)-2]);
	}
}
int divide(ll k){
	int i=0;
	while(fib[i]<k) i++;
	if(fib[i]==k) return 1;
	else if(k-fib[i-1]<fib[i]-k) return divide(k-fib[i-1])+1;
	else return min(divide(k-fib[i-1]),divide(fib[i]-k))+1;
}
int main(){
	ios_base::sync_with_stdio(0);
	countFib();
	int p;
	ll k;
	cin>>p;
	loop(i,0,p){
		cin>>k;
		pln(divide(k));
	}
}
