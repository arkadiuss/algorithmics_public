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
int rub,saf,szek;
int a[MAX],b[MAX];
int dp[MAX][MAX];
int cost(int r,int s,int d){
	return a[d]*r+b[d]*s;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,1,n+1){
		cin>>a[i];
	}
	loop(i,1,n+1){
		cin>>b[i];
	}
	loop(i,0,n){
		dp[0][i]=0;
	}
	dp[0][0]=0;
	loop(x,1,2*n){
		loop(h,0,n){
			int r=(x+h)/2;
			int s=x-r;
			if((x+h)%2==0)
			if(h==0)
				dp[x][h]=dp[x-1][h+1];	
			else if(r==h&&s==0)
				dp[x][h]=dp[x-1][h-1]+cost(r,s,h);	
			else
				dp[x][h]=min(dp[x-1][h-1]+cost(r,s,h),dp[x-1][h+1]);	
			
		}
	}
	/*loop(i,0,2*n-1){
		loop(j,0,n){
			cout<<dp[i][j]<<" ";
		}
		entr;
	}*/
	cout<<dp[2*n-2][0]<<"\n";	
}
