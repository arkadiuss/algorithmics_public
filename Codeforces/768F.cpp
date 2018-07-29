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
ll pwr(ll a,int n){
	if(n==0) return 1;
	if(n==1) return a;
	if(n%2==1) return (pwr(a,n-1)*a)%MOD;
	a=pwr(a,n/2);
	return (a*a)%MOD;
}
ll fact[MAX];
void countFact(int n){
	fact[0]=1;
	fact[1]=1;
	for(ll i=2;i<n;i++){
		fact[i]=(fact[i-1]*i)%MOD;
	}
}
ll newton(int n,int k){
	return (((fact[n]*pwr(fact[n-k],MOD-2))%MOD)*pwr(fact[k],MOD-2))%MOD;
}
int main(){
	ios_base::sync_with_stdio(0);
	ll f,w,h;
	cin>>f>>w>>h;
	countFact(f+w+1);
    ll p=0,q=0;
    for(ll i=1;i<min(w+1,f+2);i++){
    	ll tmp=0;
    	if(i>1) tmp=(tmp+newton(f-1,i-2))%MOD;
    	//ps(tmp);
    	if(i<=f) tmp=(tmp+2*newton(f-1,i-1))%MOD;
    	//ps(tmp);
    	if(i<f) tmp=(tmp+newton(f-1,i))%MOD;
    	///ps(tmp);
    	if(tmp==0) tmp=1;
    	//ps(tmp);
    	if(w-i>=0){
    		//pln(newton(w-1,i-1));
    		q=(q+newton(w-1,i-1)*tmp)%MOD;
    	}
    	if(w-i*(h+1)>=0){
    		p=(p+newton(w-i*(h+1)+i-1,i-1)*tmp)%MOD;
    	}
    	 //ps(p);pln(q);		
    }
	if(h==0||w==0) pln(1);
    else pln((p*pwr(q,MOD-2))%MOD);
}
