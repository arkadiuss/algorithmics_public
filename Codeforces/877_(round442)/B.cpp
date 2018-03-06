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
string s;
int n;
int pref[MAX][2];
int getPref(int a,int b,int t){
	if(a==0) return pref[b][t];
	else return pref[b][t]-pref[a][t];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>s;
	n=SIZE(s);
	int maxlen=0;
	pref[0][0]=0;
	pref[0][1]=0;
	loop(i,1,n+1){ 
		pref[i][0]=pref[i-1][0]+(s[i-1]=='a');
		pref[i][1]=pref[i-1][1]+(s[i-1]=='b');
	}
	loop(i,0,n+1){
		loop(j,i,n+1){
			maxlen=max(maxlen,n-getPref(0,i,1)-getPref(i,j,0)-getPref(j,n,1));
		}
	}
	pln(maxlen);
}
