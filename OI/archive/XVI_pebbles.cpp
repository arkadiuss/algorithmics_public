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
int a[MAX], b[MAX];
int n;
int main(){
	ios_base::sync_with_stdio(0);
	int u;
	cin>>u;
	while(u--){
		cin>>n;
		loop(i,0,n){
			cin>>a[i];
		}
		int xors=0;
		loop(i,0,n){
			b[0]=a[0];
			loop(j,1,n){
				b[j]=a[j]-a[j-1];
			}
			loop(j,0,n){
				xors=xors xor b[j];
			}
			loop(j,0,n){
				a[j]=a[j]-b[j];
			}
		}
		//coutTab(a,n);
		if(xors==0)
			cout<<"NIE"<<"\n";
		else
			cout<<"TAK"<<"\n";	
	}
}
