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
typedef vector<ll> VI;
typedef pair<ll, ll> PLL;
typedef vector<vector<ll> > VVI;
const ll INFTY=1e18;
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}

template<class T> void coutVec(vector<T> tab){
	for(T t : tab){
		cout<<t<<" ";
	}
	cout<<"\n";
}
//------------------------------------------


void testcase() {
	int n;
	cin>>n;
	VI a(n);
	VVI dp(n, VI(n, 0));
	ll S = 0;
	loop(i,0,n){
		cin>>a[i];
		S += a[i];
	}
	loop(d,0,n) {
		loop(i,0,n) {
			if(d==0){
				dp[i][(i+d)%n] = a[i];
			} else {
				dp[i][(i+d)%n] = max(a[i] - dp[(i+1)%n][(i+d)%n], a[(i+d)%n]-dp[i][(i+d-1)%n]);
			}
		}
	}
	ll maxi = -INFTY;
	loop(i,0,n) {
		maxi = max(maxi, dp[i][(i+n-1)%n]);
	}
	ps((maxi+S)/2);pln((S-maxi)/2);
}

int main(){
	ios_base::sync_with_stdio(0);
	int Z;
	cin>>Z;
	while(Z--) {
		testcase();
	}
}
