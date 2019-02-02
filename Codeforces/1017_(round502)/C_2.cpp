
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
int p[12];
int last[12];
int n;
int fact(int n){
	int i=1;
	loop(j,2,n+1) i*=j;
	return i;
}
int check(){
	int dp[12];
	loop(i,0,12){ last[i]=0; dp[i]=0; }
	dp[0]=1;
	last[p[0]]=1;
	int maxi=0;
	loop(i,1,n){
		dp[i]=1;
		loop(j,0,p[i]){
			if(last[j]>0)
				dp[i]=max(dp[i],last[j]+1);
		}
		last[p[i]]=max(last[p[i]],dp[i]);
		maxi = max(maxi,dp[i]);
	}
	return maxi;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n) p[i]=i;
	int best=INFTY;
	loop(i,0,fact(n)){
		int s=0;
		s=check();
		reverse(p,p+n);
		s+=check();
		reverse(p,p+n);
		if(s<best){
			loop(i,0,n) ps(p[i]);
			entr;
			best=s;
			pln(s);
		}
		next_permutation(p,p+n);
	}
	pln(best);
}
