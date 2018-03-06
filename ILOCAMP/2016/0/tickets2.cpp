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
const int MAX=1000100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int n;
int ticket[MAX][2];
ll howMany[MAX];
set<int> S;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>ticket[i][0]>>ticket[i][1];
	}
	ll sum=0;
	loop(i,0,n){
		if(howMany[ticket[i][0]]==0)
			S.insert(ticket[i][0]);
		howMany[ticket[i][0]]=howMany[ticket[i][0]]+ticket[i][1];
		sum=sum+(*S.begin());
		//ps(sum);
		howMany[(*S.begin())]--;
		if(howMany[(*S.begin())]==0)
			S.erase(S.begin());
	}
	//entr;
	cout<<sum<<"\n";
}
