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
const int MAX=2100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int n;
int a[MAX];
int dp[MAX];
int gcd(int a,int b){
	if(a>b) swap(a,b);
	if(a==0) return b;
	else return gcd(b%a,a);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	
	loop(i,0,n){
		cin>>a[i];
	}
	int bi=-1,bl=INFTY;
	loop(i,0,n){
		int j=i;
		int g=a[i];
		while(j<n-1&&g>1){
			g=gcd(g,a[++j]);
		}
		if(g==1){
			if(j-i<bl){
				bl=j-i;
				bi=i;
			}
		}
	}
	if(bi==-1){
		pln(-1);
	}else{
		loop(i,bi,bi+bl){
			int g=gcd(a[i],a[i+1]);
			a[i+1]=g;
		}
		int fs;
		fs=bi+bl;
		dp[fs]=0;
		loop(i,fs+1,n){
			if(i==fs+1){
				if(a[i]==1) dp[i]=0;
				else dp[i]=1;
			}else{
				if(a[i]==1) dp[i]=dp[i-1];
				else dp[i]=dp[i-1]+1;
			}
		}
		loopback(i,fs-1,0){
			if(i==fs-1){
				if(a[i]==1) dp[i]=0;
				else dp[i]=1;
			}else{
				if(a[i]==1) dp[i]=dp[i+1];
				else dp[i]=dp[i+1]+1;
			}
		}
		pln(dp[0]+dp[n-1]+bl);
	}
}
