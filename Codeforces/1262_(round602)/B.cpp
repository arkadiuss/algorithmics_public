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
typedef pair<int, int> PII;
typedef vector<vector<int> > VVI;
const int INFTY=20000000;
const int MAX=100100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}

template<class T> void coutVec(vector<T> tab){
	for(T t : tab){
		cout<<t<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
bool taken[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		loop(i,0,n+1) {
			taken[i]=false;
		}
		int q,pq=-1;
		int j = 1;
		VI res;
		bool ok = true;
		loop(i,0,n) {
			cin>>q;
			if(pq < q) {
				taken[q] = true;
				res.pb(q);
			} else {
				while(j < n && taken[j]) j++;
				if(taken[j] || j > q) ok = false;
				else {
					taken[j]=true;
					res.pb(j);
				}
			}
			pq = q;
		}
		if(!ok) {pln(-1);}
		else coutVec(res);
		res.clear();
	}
}
