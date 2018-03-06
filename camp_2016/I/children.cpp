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
int main(){
	ios_base::sync_with_stdio(0);
	int A,B,C,D;
	cin>>A>>B>>C>>D;
	loop(i,0,4){
		switch(i){
			case 0:
				cout<<B+C+D<<" ";
				break;
			case 1:
				cout<<A+C+D<<" ";
				break;
			case 2:
				cout<<B+A+D<<" ";
				break;
			case 3:
				cout<<B+C+A<<" ";
				break;			
			
		}
	}
}
