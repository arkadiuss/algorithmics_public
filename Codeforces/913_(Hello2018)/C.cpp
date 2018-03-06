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
const ll INFTY=4*1e18;
const int MAX=31;
const int MOD=10000000;

void coutTab(ll* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
ll cs[MAX];
ll w[MAX];
ll pws[MAX];
int n,m;
ll solve(ll m){
	if(m<=0) return 0;
	int i=0;
	while(pws[i]<=m&&i<n){
		i++;
	}
	//pln(i);
	int j=i-1;
	while(!w[j]&&j>=0) j--;
	ll m1=INFTY;
	//pln(m/pws[j]);
	if(j>=0) m1=(m/pws[j])*cs[j]+solve(m%pws[j]);
	while(!w[i]) i++;
	ll m2=INFTY;
	if(i<n) m2=cs[i];
	return min(m1,m2);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	loop(i,0,n) cin>>cs[i];
	pws[0]=1;
	loop(i,1,n+1) pws[i]=2*pws[i-1];
	loop(i,0,n) w[i]=true;
	loopback(i,n-1,0){
		loop(j,0,i){
			if(cs[j]*pws[i-j]<cs[i]){ 
				w[i]=false;
				break;
			}	
		}
		loop(j,0,i) if(cs[j]>cs[i]) w[j]=false;
	}
	//coutTab(w,n);
	pln(solve(m));
}
