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
const int MAX=500;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
ll dp[MAX][4];
int howMany(string &s1,string &s2,int i){
	int h=0;
	h+=(s1[i]=='X');
	h+=(s1[i-1]=='X');
	h+=(s2[i]=='X');
	h+=(s2[i-1]=='X');
	return h;
}

int main(){
	ios_base::sync_with_stdio(0);
	string s1,s2;
	cin>>s1>>s2;
	loop(j,0,4) dp[0][j]=0;
	int n=SIZE(s1);
	loop(i,1,n){
		if(howMany(s1,s2,i)>1){
			loop(j,0,4) dp[i][j]=dp[i-1][j];
		}else{
			if(s2[i]=='X'){
				if(i!=1){
					loop(j,0,4){
						dp[i][0]=max(dp[i][0],dp[i-2][j]+1);
					}
				}else{
					dp[i][0]=1;
				}
			}else if(s1[i]=='X'){
				if(i!=1){
					loop(j,0,4){
						dp[i][1]=max(dp[i][1],dp[i-2][j]+1);
					}
				}else{
					dp[i][1]=1;
				}
			}else if(s2[i-1]=='X'){
				if(i!=1){
					loop(j,0,4){
						dp[i][2]=max(dp[i][2],dp[i-2][j]+1);
					}
				}else{
					dp[i][2]=1;
				}
			}else if(s1[i-1]=='X'){
				if(i!=1){
					loop(j,0,4){
						dp[i][3]=max(dp[i][3],dp[i-2][j]+1);
					}
				}else{
					dp[i][3]=1;
				}
			}else{
				if(i==1){
					loop(j,0,4) dp[i][j]=1;
				}else{
					loop(j,0,4){
						loop(k,0,4){
							dp[i][j]=max(dp[i][j],dp[i-2][k]+1);
						}
					}
					dp[i][2]=max(dp[i][2],dp[i-1][1]+1);
					dp[i][3]=max(dp[i][3],dp[i-1][0]+1);
				}
			}
		} 
	}
	ll maxi=0;
	loop(i,0,n){
		loop(j,0,4) maxi=max(maxi,dp[i][j]);
	}
	pln(maxi);	
}
