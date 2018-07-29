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
const int MAX=5001;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int a[MAX];
ll pref[MAX];
ll getPref(int i,int j){
	if(i==0) return pref[j];
	else return pref[j]-pref[i-1];
}
int main(){
	ios_base::sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	loop(i,0,n){
		cin>>a[i];
	}
	pref[0]=a[0];
	loop(i,1,n) pref[i]=pref[i-1]+a[i];
	double be = 0;
	loop(i,0,n){
		loop(j,i,n){
			if(j-i+1>=k){
				double s = getPref(i,j);
				be = max(be,s/(j-i+1));
			}
		}
	}
	cout<<fixed<<setprecision(7)<<be<<"\n";
}
