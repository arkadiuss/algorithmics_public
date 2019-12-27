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
const int MAX=2100;
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
map<int, int> ca;
map<int, int> cb;
int a[MAX];
int b[MAX];
set<int> xs;
int m;
bool check(int x) {
	//pln(x);
	for(auto ia:ca) {
		auto it=cb.find((ia.ff+x)%m);
		if(it == cb.end() || it->ss != ia.ss) {
			return false;
		}
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n>>m;
	loop(i,0,n) {
		cin>>a[i];
		ca[a[i]]++;
	}
	loop(i,0,n){
	 	cin>>b[i];
		cb[b[i]]++;
	}
	auto it = *ca.begin();	
	for(auto ib:cb) {
		if(it.ss == ib.ss) {
			int r=ib.ff-it.ff;
			while(r<0) r+=m;
			xs.insert(r);
		}
	}
	
	for(auto x : xs) {
		if(check(x)){ pln(x); return 0;}
	}	
}
