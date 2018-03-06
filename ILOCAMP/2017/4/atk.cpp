#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define foreach(i,c) for(VAR(i,c.begin());i!=c.end();i++)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) c.size()
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const int MAX=68;
const int MOD=1000000000;
const int INFTY=1000000000;
typedef vector<int> VI;

void coutTab(int * tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------
ll pwr[MAX];
ll count(int n,ll k){
	ll n21=pwr[n-1]-1;
	ll n2=pwr[n]-1;
	if(n==1) return 0;
	else if(k==1){
		return n2-n;
	}else{
		///case 1
		/////////////////////////////////
		if(k>n21) return n2-1;
		ll i1=k/2;
		ll i2=k*2+1;
		ll s=1;
		ll p=1;
		
		while(i1>0){
			//ps(i1);ps(i2);pln(s);
			s++;
			if(i2<=n2) s=s+p;
			i1=i1/2;
			i2=i2*2+1;
			p*=2;
		}
		//ps(i1);ps(i2);ps(p);pln(s);
		//s-=p/2;
		//p--;
		while(i2<=n2){
			s=s+p;
			p=(p)*2-1;
			i2*=2;
		}
		//pln(s);
		////case 2
		////////////////////////////////
		i2=k*4;
		ll s2=3;
		p=3;
		while(i2<=n2){
			s2=s2+p;
			p=p*2-1;
			i2=i2*2;
		}
		//ps(s);pln(s2);
		return n2-min(s,s2);
	}
}
void countPwr(){
	pwr[0]=1;
	loop(i,1,61){
		pwr[i]=pwr[i-1]*2;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	int T;
	cin>>T;
	int n;
	ll k;
	countPwr();
	while(T--){
		cin>>n>>k;
		pln(count(n,k));
	}
}
