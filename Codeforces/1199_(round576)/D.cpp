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
int t[MAX];
int pref[MAX];
struct citizen {
	int w;
	int t;
};
citizen a[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	int n,q;
	cin>>n;
	loop(i,0,n){ 
		cin>>a[i].w;
		a[i].t = 0;
	}
	cin>>q;
	loop(i,0,q) t[i] = -1;
	int type, x, p;
	loop(j,0,q) {
		cin>>type;
		if(type==1) {
			cin>>p>>x;
			a[p-1].w = x;
			a[p-1].t = j;
		} else {
			cin>>x;
			t[j] = x;
		}
	}
	pref[q-1] = t[q-1];
	loopback(i,q-2,0) {
		pref[i] = max(pref[i+1],t[i]);
	}
	loop(i,0,n){
		ps(max(a[i].w,pref[a[i].t]));
	}
}
