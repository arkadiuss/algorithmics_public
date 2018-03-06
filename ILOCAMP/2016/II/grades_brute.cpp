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
int pe[MAX],inf[MAX];
int dp[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>inf[i];
	}
	loop(i,0,n){
		cin>>pe[i];
	}
	int minswap = INFTY;
	int minmask=0;
	loop(mask,0,1<<n+1){
		loop(j,0,n){
			if(1<<j&mask){
				swap(pe[j],inf[j]);
			}
		}
		bool pass=1;
		loop(i,1,n){
			pass=pass&&(inf[i-1]<inf[i]&&pe[i-1]<pe[i]);
		}
		if(pass){
			if(pcnt(mask)<minswap){
				minswap=min(minswap,pcnt(mask));
				minmask=mask;
			}
		}
		loop(j,0,n){
			if(1<<j&mask){
				swap(pe[j],inf[j]);
			}
		}
	}
	//pln(minmask);
	if(minswap==INFTY)
		cout<<"NIE";
	else	
		cout<<minswap<<"\n";
}
