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
typedef pair<int, int> PII;
const int INFTY=20000000;
const int MAX=300100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int a[MAX];
PII p[MAX];
vector<PII> rs;
int dp[MAX][2];
int main(){
	ios_base::sync_with_stdio(0);
	int n,q;
	cin>>q;
	while(q--) {
		cin>>n;
		loop(i,0,n+1){
			p[i].ff=-1;
			p[i].ss=-1;
		}
		rs.clear();
		loop(i,0,n) {
			cin>>a[i];
			if(p[a[i]].ff==-1){
				p[a[i]].ff = i;
			}
			p[a[i]].ss = i;	
		}
		loop(i,0,n+1) {
			if(p[i].ff!=-1)
				rs.pb({p[i].ff, p[i].ss});
		}
		int maxi = 0;
		int cur = 1;
		loop(i,1,rs.size()){
			if(rs[i].ff > rs[i-1].ss) {
				cur += 1;
			} else {
				maxi = max(maxi, cur);
				cur = 1;
			}
		}
		maxi = max(maxi, cur);
		pln(rs.size() - maxi);
	}
}
