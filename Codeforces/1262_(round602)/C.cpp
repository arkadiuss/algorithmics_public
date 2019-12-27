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
const int MAX=500100;
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
int sfind(string s, int st, char a) {
	loop(i,st,s.size()) {
		if(s[i] == a) return i;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--) {
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		vector<PII> ops;
		int ck = k;
		loop(i,0,n) {
			if(i < 2*(k-1)) {
				if(i%2==0 && s[i] != '(') {
					int p = sfind(s, i+1,'(');
					ops.pb({i+1, p+1});
					reverse(s.begin()+i, s.begin()+p+1);
				} else if(i%2==1 && s[i] != ')') {
					int p = sfind(s, i+1,')');
					ops.pb({i+1, p+1});
					reverse(s.begin()+i, s.begin()+p+1);
				}
			} else {
				if(i < 2*(k-1) + (n-2*(k-1))/2 && s[i] != '(') {
					int p = sfind(s, i+1,'(');
					ops.pb({i+1, p+1});
					reverse(s.begin()+i, s.begin()+p+1);
				} else if(i >= 2*(k-1) + (n-2*(k-1))/2 && s[i] != ')') {
					int p = sfind(s, i+1,')');
					ops.pb({i+1, p+1});
					reverse(s.begin()+i, s.begin()+p+1);
				}
			}
		}//entr;
		//	pln(s);
		pln(ops.size());
		loop(i,0,ops.size()) {
			ps(ops[i].ff);pln(ops[i].ss);
		}
		ops.clear();
	}
}
