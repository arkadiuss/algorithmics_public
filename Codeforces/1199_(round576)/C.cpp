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
int n,I;
int a[MAX];
int c[MAX];
int pref[MAX];
int pow2(int k) {
	int r=1;
	while(k--){
		r*=2;
	}
	return r;
}

void renumber_and_count(){
	int j=0;
	c[j]=1;
	loop(i,1,n){
		if(a[i]!=a[i-1]) j++;
		c[j]++;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>I;
	loop(i,0,n) cin>>a[i];
	int k = (I*8)/n;
	if(k>=28) {
		pln(0);
		return 0;
	}
	int K = pow2(k);
	sort(a, a+n);
	renumber_and_count();
	pref[0]=c[0];
	loop(i,1,n) pref[i]=pref[i-1]+c[i];
	if(K>=n) {
		pln(0);
		return 0;
	}
	int res = 0;
	loop(i,0,n-K) {
		res = max(res, pref[i+K-1]-pref[i]+c[i]);
	}
	pln(n-res);
}
