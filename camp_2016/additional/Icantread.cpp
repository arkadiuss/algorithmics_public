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
const int MAX=1000;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int T,n;
int nimbar[MAX];
bool was[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>T;
	nimbar[0]=0;
	nimbar[1]=0;
	nimbar[2]=0;
	nimbar[3]=1;
	loop(i,4,MAX){
		loop(j,0,MAX){
			was[j]=0;
		}
		loop(j,1,i-2){
			was[nimbar[j] xor nimbar[i-j-1]]=1;
		}
		loop(j,0,MAX){
			if(!was[j]){
				nimbar[i]=j;
				break;
			}
		}	
	}
	while(T--){
		cin>>n;
		if(nimbar[n-1]==0)
			cout<<"Pierwszy"<<"\n";
		else
			cout<<"Drugi"<<"\n";	
	}
}
