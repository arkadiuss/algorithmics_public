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
ll count(ll t[MAX],ll d,ll p){
	ll SL=0,SR=0;
	loop(i,0,n){
		if(t[i]<p) SL+=abs(p-t[i]);
		else if(t[i]>p+d) SR+=abs(p+d-t[i]);
	}
	return SL+SR;
}
ll countBest(ll t[MAX],ll d){
	sort(t,t+n);
	ll s=0;
	ll e=t[n-1]-t[0];
	while(s<e-1){
		ll p1=(2*s+e+1)/3;
		ll p2=(s+2*e+2)/3;
		ll m=(p1+p2)/2;
		//ps(s+t[0]);ps(p1+t[0]);ps(m+t[0]);ps(p2+t[0]);pln(e+t[0]);
		ll ans1=count(t,d,p1+t[0]);
		ll ansm=count(t,d,m+t[0]);
		ll ans2=count(t,d,p2+t[0]);
		if((ans1>=ansm&&ans2>=ansm)){
			s=p1;
			e=p2;
		}else if(ans2<=ansm&&ans1>=ansm){
			s=p1;
		}else{
			e=p2;
		}	
	}
	//ps(s+t[0]);pln(e+t[0]);
	ll ans=count(t,d,s+t[0]);
	ll ans2=count(t,d,e+t[0]);
	ans=min(ans,count(t,d,s-1+t[0]));
	//ps(ans);pln(ans2);
	return min(ans,ans2);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>s>>w;
	loop(i,0,n){
		cin>>x[i]>>y[i];
	}
	pln(countBest(x,s)+countBest(y,w));
}
