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
const int INFTY=2000000000;
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int gcd(int a,int b){
	if(a>b) swap(a,b);
	if(a==0) return b;
	return gcd(b%a,a);
}
int main(){
	ios_base::sync_with_stdio(0);
	int n,k,a;
	cin>>n>>k;
	int g=0,mini=INFTY;
	loop(i,0,n){
		cin>>a;
		mini=min(mini,a%k);
		g=gcd(g,a%k);
	}
	VI res;
	res.pb(mini);
	int i=(mini+g)%k;
	while(i!=mini){
		res.pb(i);
		i=(i+g)%k;
	}
	sort(ALL(res));
	pln(res.size());
	loop(i,0,res.size()) ps(res[i]);
	entr;
}
