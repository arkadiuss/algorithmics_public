#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
using namespace std;
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
int n,x,howManyxor=0;
int a[MAX];
int dp[MAX][2];

int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>x;
	loop(i,0,n) cin>>a[i];
	dp[0][1]=1;
	dp[0][0]=0;
	loop(i,1,n){
		dp[i][0]=INFTY;
		dp[i][1]=INFTY;
	}
	loop(i,1,n){
		if(a[i-1]<=a[i]){
			dp[i][0]=min(dp[i][0],dp[i-1][0]);
		}
		if((a[i-1] xor x)<=a[i]){
			dp[i][0]=min(dp[i][0],dp[i-1][1]);
		}
		if(a[i-1]<=(a[i] xor x)){
			dp[i][1]=min(dp[i][1],dp[i-1][0]+1);
		}
		if((a[i-1] xor x)<=(a[i] xor x)){
			dp[i][1]=min(dp[i][1],dp[i-1][1]);
		}
		
	}
	cout<<min(dp[n-1][0],dp[n-1][1]);
}
