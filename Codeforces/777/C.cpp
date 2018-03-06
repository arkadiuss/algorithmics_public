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
vector< VI > T,DP;
int n,m;
VI mxs;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	VI tmp;
	int a;
	loop(i,0,n){
		loop(j,0,m){
			cin>>a;
			tmp.pb(a);
		}
		T.pb(tmp);
		tmp.erase(ALL(tmp));
	}
	DP=T;
	loop(i,0,n){
		loop(j,0,m){
			DP[i][j]=0;
		}
	}
	loop(j,0,m){
		DP[0][j]=1;
		loop(i,1,n){
			if(T[i][j]>=T[i-1][j])
				DP[i][j]=DP[i-1][j]+1;
			else
				DP[i][j]=1;	
		}
	}
	loop(i,0,n){
		mxs.pb(0);
		loop(j,0,m){
			mxs[i]=max(mxs[i],DP[i][j]);
		}
	}
	int l,r,k;
	cin>>k;
	loop(i,0,k){
		cin>>l>>r;
		if(r-mxs[r-1]+1<=l) pln("Yes");
		else pln("No");
	}
}
