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
int res[MAX];
int dp[MAX];
int last[MAX];
int check(int * p,int n){
	loop(i,0,n){ last[i]=0; dp[i]=0; }
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
	int n;
	cin>>n;
	int p = sqrt(n);
	loop(i,1,n+1) res[i-1]=i;
	int i = 0;
	while(i + p <=n){
		reverse(res+i,res+i+p);
		i+=p;
	}
	reverse(res+i,res+n);	
	//int s = check(res,n);
	//reverse(res,res+n);
	//s+=check(res,n);
	//reverse(res,res+n);
	//pln(s);
	loop(i,0,n) ps(res[i]);
	entr;
}
