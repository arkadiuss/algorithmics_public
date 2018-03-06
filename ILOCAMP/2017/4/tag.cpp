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
const int MAX=1000100;
const int MOD=1000000000;
const int INFTY=1000000000;
typedef vector<int> VI;

void coutTab(ll* tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------
int n;
ll hm[MAX],a[MAX];
ll  maxval=0;
vector<ll> val;
ll dp[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>a[i];
		hm[a[i]]++;
		maxval=max(maxval,a[i]);
	}
	loop(i,0,maxval+1){
		if(hm[i]>0)
			val.pb(i);
	}
	dp[0]=hm[val[0]]*val[0];
	if(val[0]==val[1]-1){
		dp[1]=max(dp[0],hm[val[1]]*val[1]);
	}else{
		dp[1]=dp[0]+hm[val[1]]*val[1];
	}
	loop(i,2,SIZE(val)){
		if(val[i]-1==val[i-1]){
			dp[i]=max(dp[i-1],dp[i-2]+val[i]*hm[val[i]]);
		}else{
			dp[i]=dp[i-1]+val[i]*hm[val[i]];
		}
	}
	//coutTab(dp,SIZE(val));
	pln(dp[SIZE(val)-1]);
}
