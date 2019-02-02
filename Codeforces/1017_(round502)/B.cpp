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
int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	string a,b;
	cin>>a>>b;
	ll zs=0,os=0;
	ll zs2=0,os2=0;
	loop(i,0,n){
		if(a[i]=='0'&&b[i]=='0') zs++;
		if(a[i]=='1'&&b[i]=='1') os++;
		if(a[i]=='0'&&b[i]=='1') zs2++;
		if(a[i]=='1'&&b[i]=='0') os2++;
	}
	ll res = zs*os+zs2*os2+zs*os2;
	pln(res);
}
