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
int n;
ll pe[MAX],inf[MAX];
int dp[MAX][2];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>inf[i];
	}
	loop(i,0,n){
		cin>>pe[i];
	}
	dp[0][0]=0;
	dp[0][1]=1;
	loop(i,1,n){
		dp[i][0]=INFTY;
		if(inf[i-1]<inf[i]&&pe[i-1]<pe[i]){
			dp[i][0]=min(dp[i][0],dp[i-1][0]);
		}
		if(pe[i-1]<inf[i]&&inf[i-1]<pe[i]){
			dp[i][0]=min(dp[i][0],dp[i-1][1]);
		}
		dp[i][1]=INFTY;
		if(inf[i-1]<pe[i]&&pe[i-1]<inf[i]){
			dp[i][1]=min(dp[i][1],dp[i-1][0]+1);
		}
		if(pe[i-1]<pe[i]&&inf[i-1]<inf[i]){
			dp[i][1]=min(dp[i][1],dp[i-1][1]+1);
		}
	}
	int ans=min(dp[n-1][0],dp[n-1][1]);
	if(ans==INFTY)
		cout<<"NIE";
	else
		cout<<ans;	
}
