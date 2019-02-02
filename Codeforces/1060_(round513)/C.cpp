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
typedef pair<ll,ll> PLL;
const int INFTY=20000000;
const int MAX=4000100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
vector<PLL> SA,SB;
ll a[2010],b[2010];

int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	ll x;
	cin>>n>>m;
	loop(i,0,n) cin>>a[i];
	loop(i,0,m) cin>>b[i];
	cin>>x;
	ll S=0;
	loop(i,0,n){
		loop(j,i,n){
			S+=a[j];
			SA.pb({S,j-i+1});
		}
		S=0;
	}
	S=0;
	loop(i,0,m){
		loop(j,i,m){
			S+=b[j];
			SB.pb({S,j-i+1});
		}
		S=0;
	}
	sort(ALL(SB));
	loop(i,1,SIZE(SB)){
		SB[i].ss=max(SB[i].ss,SB[i-1].ss);
	}
	ll res = 0;
	for(auto i:SA){
		if(i.ff<=x){
			int s=0,e=SIZE(SB)-1;
			while(s<e){
				int m=(s+e+1)/2;
				if(SB[m].ff*i.ff<=x){
					s=m;
				}else{
					e=m-1;
				}
			}
			if(SB[s].ff*i.ff<=x){
				//ps(s);ps(i.ff);ps(i.ss);ps(SB[s].ff);pln(SB[s].ss);
				res=max(res,i.ss*SB[s].ss);
			}
		}
	}
	pln(res);
}
