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
const int MAX=200100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int p[MAX];
int n;
ll k,x,y;
ll a,b, nww;
ll gcd(ll a,ll b) {
	if(a>b) swap(a,b);
	if(a==0) return b;
	return gcd(a, b%a);
}

bool check(int m) {
	int c = m/nww;
	int fb = m/b-c;
	int fa = m/a-c;
	ll sum = 0;
	loop(i,0,c) {
		sum += p[i]/100*(x+y);	
	}
	loop(i,c,c+fb) {
		sum += p[i]/100*(y);
	}
	loop(i,c+fb,c+fb+fa) {
		sum += p[i]/100*(x);
	}
	//ps(c);ps(fb);ps(fa);pln(sum);
	return sum >= k;
}

int find_min() {
	int s = 0, e=n;
	while(s < e) {
		int m = (s+e)/2;
		//ps(s);ps(e);pln(m);
		if(check(m)) {
			e = m;
		}else {
			s = m+1;
		}
	}
	return check(s) ? s : -1;
}

bool toSort(ll a, ll b) {
	return a>b;
}

int main(){
	ios_base::sync_with_stdio(0);
	int q;
	cin>>q;
	while(q--) {
		cin>>n;
		loop(i,0,n) cin>>p[i];
		sort(p, p+n, toSort);
		cin>>x>>a;
		cin>>y>>b;
		cin>>k;
		if(x>y){
			swap(a,b);
			swap(x,y);
		}
		nww = a*b/gcd(a,b);
		pln(find_min());
	}
}
