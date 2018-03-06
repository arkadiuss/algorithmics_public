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
string hsh[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	int maxlen=0;
	string s;
	loop(i,0,n){
		cin>>s;
		hsh[i]=s;
	}
	loopback(i,n-2,0){
		int j=0;
		while(j<SIZE(hsh[i])&&j<SIZE(hsh[i+1])&&hsh[i][j]==hsh[i+1][j]) j++;
		//pln(j);
		if(hsh[i][j]>hsh[i+1][j]){
			loopback(k,SIZE(hsh[i])-1,j) hsh[i].erase(hsh[i].end()-1,hsh[i].end());
		} 
	}
	loop(i,0,n) pln(hsh[i]);
}
