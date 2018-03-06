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
const int MAX=1000100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int n;
ll k,c;
ll dp[MAX];
ll dates[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k>>c;
	loop(i,0,k){
		dates[i]=INFTY;
	}
	int t,w;
	loop(i,0,n){
		cin>>t>>w;
		dates[t-1]=w;
	}
	dp[0]=c;
	loop(i,0,k){
		dp[i]=min(dp[i-1]+c,dates[i]+c-(dates[i]+c)%c);
	}
	cout<<dp[k-1];
}
