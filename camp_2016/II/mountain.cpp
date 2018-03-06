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
ll a[MAX];
ll countOne(){
	ll dp[MAX];
	ll len=1;
	dp[0]=1;
	loop(i,1,n){
		if(a[i]<=a[i-1])
			len++;
		else
			len=1;	
		dp[i]=dp[i-1]+len;
	}
	return dp[n-1];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>a[i];
	}
	ll sum=countOne();
	reverse(a,a+n);
	sum=sum+countOne()-n;
	cout<<sum;
}
