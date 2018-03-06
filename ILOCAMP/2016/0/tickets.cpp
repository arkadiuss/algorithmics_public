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
int dp[MAX];
int ticket[MAX][2];
int howManyTcks[MAX][3];
int mns[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>ticket[i][0]>>ticket[i][1];
	}
	dp[0]=ticket[0][0];
	ticket[0][1]--;
	entr;
	loop(i,1,n){
		dp[i]=dp[i-1]+ticket[i][0];
		loop(j,0,i){
			if(i-j<=ticket[j][1]){
				if(dp[i]>=dp[j]+ticket[j][0]*(i-j)){
					dp[i]=dp[j]+ticket[j][0]*(i-j);
					mns[i]=max(0,abs(ticket[i][0]-ticket[j][0]));
				}
				if(dp[i]>=dp[j]+ticket[j][0]*(i-j)-mns[j]*(i-j)){
					dp[i]=dp[j]+ticket[j][0]*(i-j)-mns[j]*(i-j);
					mns[i]=max(0,abs(ticket[i][0]-ticket[j][0]));
				}
			}
		}
		if(dp[i]==dp[i-1]+ticket[i][0])
			ticket[i][1]--;
		ps(i+1);
		ps(mns[i]);
		pln(dp[i]);
	}
	cout<<dp[n-1]<<endl;
}
