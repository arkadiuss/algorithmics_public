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
const int MAX=100100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int n, x, y;
int a[MAX];
bool check(int p) {
	loop(i, max(0,p-x), p) {
		if(a[i] <= a[p]) return false;
	}
	
	loop(i, p+1, min(n, p+y+1)) {
		if(a[i] <= a[p]) return false;
	}
	
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);
	
	cin>>n>>x>>y;
	loop(i,0,n) cin>>a[i];
	loop(i,0,n) {
		if(check(i)) {
			pln(i+1);
			break;
		}
	}
}
