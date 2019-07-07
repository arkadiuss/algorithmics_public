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
const int MAX=1000100;
const ll MOD=1000000007LL;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
ll cur[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	int T;
	cin>>T;
	int N;
	ll K;
	string s;
	for(int t=1; t<=T; t++) {
		cin>>N>>K;
		cin>>s;
		cur[0] = s[0] == 'A' ? -1 : 1; 
		loop(i,1,N) {
			if(s[i]=='B'){
				cur[i] = cur[i-1] + 1;
			} else { 
				cur[i] = cur[i-1] - 1;
			}
		}
		ll res = 0;
		ll maxi = cur[N-1];
		loopback(i, N-1, 1) {
			maxi = max(cur[i], maxi);
			if(maxi - cur[i-1] > K) {
				res = (res + 1) % MOD;
				maxi -= 2;
			}
			res = (res * 2) % MOD;
		}
		maxi = max(cur[0], maxi);
		if(maxi > K) {
			res = (res + 1) % MOD;
			maxi -= 2;
		}
		res = (res * 2) % MOD;
		cout<<"Case #"<<t<<": "<< res <<"\n";
	}

}
