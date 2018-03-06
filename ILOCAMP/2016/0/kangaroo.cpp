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
const int MAX=100100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int n;
int trees[MAX];
ll low[MAX][210];
int main(){
	ios_base::sync_with_stdio(0);
	int m;
	cin>>n>>m;
	loop(i,0,n){
		cin>>trees[i];
	}
	loop(j,0,200){
		loop(i,0,n){
			if(i-j>=0)
				low[i][j]=low[i-j][j]+trees[i];
			else
				low[i][j]=trees[i];	
		}
	}
	/*loop(i,0,n){
		loop(j,0,min(n,200)){
			cout<<low[i][j]<<" ";
		}
		entr;
	}*/
	int a,b,c;
	while(m--){
		cin>>a>>b>>c;
		if(c<200){
			cout<<low[a+b*c-1][c]-low[a-1][c]+trees[a-1]<<"\n";
		}else{
			ll sum=trees[a-1];
			int j=a-1+c;
			loop(i,0,b){
				sum=sum+trees[j];
				j=j+c;
			}
			cout<<sum<<"\n";
		}
	}
}
