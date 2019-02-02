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
bool toSort(pair<int,int> a,pair<int,int> b){
	if(a.ss==b.ss) return a.ff<b.ff;
	return a.ss>b.ss;
}
int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	int a,b,c,d;
	vector<pair<int,int> > res;
	loop(i,0,n){
		cin>>a>>b>>c>>d;
		res.pb(mp(i,a+b+c+d));
	}
	sort(ALL(res),toSort);
	loop(i,0,n){
		if(res[i].ff==0) pln(i+1);
	}
}
