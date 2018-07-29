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
const int MAX=5100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int f[MAX][MAX];
int gcd(int a,int b){
	return a%b==0 ? b : gcd(b,a%b); 
}
int main(){
	ios_base::sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	f[1][0]=1;
	loop(i,2,n+1){
		loop(j,1,sqrt(i)){
			if(i%j==0&&gcd(j,i/j)==1){
				f[i][0]++;
			}
		}
		f[i][0]*=2;	
	}
	loop(l,1,k+1){
		loop(i,1,n+1){
			int j = 1;
			while(j<sqrt(i)){
				if(i%j==0){
					f[i][l]=(f[i][l]+f[j][l-1]+f[i/j][l-1])%MOD;
				}
				j++;
			}
			if(j*j==i) f[i][l]=(f[i][l]+f[j][l-1])%MOD;
		}	
	}
	loop(i,1,n+1){
		ps(i);ps(":");
		loop(j,0,k+1){
			cout<<f[i][j]<<" ";
		}
		entr;
	}
}
