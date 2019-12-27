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
typedef vector<ll> VI;
typedef pair<int, int> PII;
typedef vector<vector<ll> > VVI;
const int INFTY=20000000;
const int MAX=103;
const int MOD=1000000007;

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

const int ALPHABET = 26;
const int FAIL = -1;
// goto function
vector<vector<int> > g;
// failure function
vector<int> f;
// output function
map<int, string> o;

// maps char a into int <0..ALPHABET)
int mp(char a) {
	return a-'a';
}
// backward map
char mpb(int a) {
	return a+'a';
}

int new_state() {
	int ind = g.size();
	g.push_back(vector<int>(ALPHABET, FAIL));
	f.push_back(FAIL);
	return ind;
}

void init() {
	new_state();
}

void add(string s) {
	int st=0;
	for(char a : s) {
		if(g[st][mp(a)] == FAIL) {
			st = g[st][mp(a)] = new_state();
		} else {
			st = g[st][mp(a)];
		}
	}
	o[st]=s;
}

void construct() {
	for(int i=0;i<(int)g[0].size();i++) if(g[0][i]==FAIL) g[0][i]=0;
	
	queue<int> Q;
	for(auto s:g[0]) if(s != 0) {
		f[s]=0;
		Q.push(s);
	} 
	
	while(!Q.empty()){
		int r = Q.front();
		Q.pop();
		int s;
		for(int a=0;a<(int)g[r].size();a++) if((s = g[r][a]) != FAIL) {
			Q.push(s);
			int state = f[r];
			while(g[state][a]==FAIL) state=f[state];
			f[s]=g[state][a];
		}
	}
}

bool output(int st) {
	while(st != 0) {
		if(o.find(st) != o.end()) return true;
		st=f[st];
	}
	return false;
}

VVI multiply(VVI a, VVI b) {
	VVI C(a.size(), VI(b.size()));
	loop(i,0,a.size()) {
		loop(j,0,a[i].size()) {
			loop(k,0,a[i].size()) 
				C[i][j] = (C[i][j] + a[i][k]*b[k][j])%MOD;
		}
	}
	return C;
}

void prnt(VVI C) {
	loop(i,0,C.size()) coutVec(C[i]);
	entr;
}
VVI count(VVI M, int n) {
	if(n == 1) return M;
	if(n%2==1) return multiply(count(M,n-1), M);
	auto C = count(M, n/2);
	return multiply(C,C);
}

ll pwr(ll a, int n) {
	if(n==0) return 1;
	if(n==1) return a;
	if(n%2==1) return (pwr(a,n-1)*a)%MOD;
	ll c = pwr(a,n/2);
	return (c*c)%MOD;
}

int main(){
	ios_base::sync_with_stdio(0);
	int N,Q;
	init();
	cin>>N>>Q;
	string s;
	int a;
	loop(i,0,Q) {
		cin>>a>>s;
		add(s);
	}
	construct();
	int S = g.size();
	VVI R(S+1, VI(S+1));
	loop(i,0,S) {
		loop(j,0,g[i].size()) {
			int st=i;
			while(g[st][j]==FAIL) st=f[st];
			if(output(g[st][j])) R[i][S]++;
			else R[i][g[st][j]]++; 
		}
	}
	R[S][S]=26;
	//prnt(R);
	R = count(R, N);
	//	prnt(R);
	ll res = pwr(26,N)-R[0][S];
	while(res<0) res+=MOD;
	pln(res);
}
