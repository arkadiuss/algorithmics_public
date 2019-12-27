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
const int MAX=1000100;
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

int tree[4*MAX];
int D;

void countD(int n) {
	D=1<<20;	
}

void init_tree(int n) {
	countD(n);
	for(int i=0;i<2*D;i++) tree[i]=0;
}

ll read(int i) {
	ll c=0;
	i+=D;
	while(i>0) {
		c+=tree[i];
		i/=2;
	}
	return c;
}

void insert(int L, int R, int v) {
	L+=D;
	R+=D;
	while(L<R) {
		if(L%2==1) tree[L]+=v;
		if(R%2==0) tree[R]+=v;
		L=(L+1)/2;
		R=(R-1)/2;
	}
	if(L==R) tree[L]+=v;
}


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

vector<vector<int> > T(MAX);
int preorder[MAX];
int subtree_size[MAX];
int cpre=0;
void create_ftree() {
	for(int i=1;i<(int)f.size();i++) {
		T[f[i]].push_back(i);
	}
}

int compute_ftree(int v) {
	preorder[v] = cpre++;
	subtree_size[v]=1;
	for(auto w:T[v]) subtree_size[v] += compute_ftree(w);
	return subtree_size[v];
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

int add(string s) {
	int st=0;
	for(char a : s) {
		if(g[st][mp(a)] == FAIL) {
			st = g[st][mp(a)] = new_state();
		} else {
			st = g[st][mp(a)];
		}
	}
	o[st]=s;
	return st;
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
	
	create_ftree();
	compute_ftree(0);
	for(auto t:o) insert(preorder[t.first],preorder[t.first]+subtree_size[t.first]-1, 1);
}

ll output(int st) {
	return read(preorder[st]);
}

int match(string s) {
	int st = 0;
	int c=0;
	for(auto a : s) {
		while(g[st][mp(a)]==FAIL) st=f[st];
		st=g[st][mp(a)];
		c+=output(st);
	}
	return c;
}

map<int, int> iToS;
string S[MAX];
bool r[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	init();
	int n,k;
	cin>>k>>n;
	init_tree(n);
	loop(i,0,n){
		cin>>S[i];
		iToS[i]=add(S[i]);
	}
	construct();
	char t=0;
	int j;
	string s;
	while(k--) {
		cin>>t;
		if(t=='-'){
			cin>>j;
			if(!r[j-1])
				insert(preorder[iToS[j-1]],preorder[iToS[j-1]]+subtree_size[iToS[j-1]] - 1 , -1);
			r[j-1]=1;	
		} else if(t=='+') {
			cin>>j;
			if(r[j-1])
				insert(preorder[iToS[j-1]],preorder[iToS[j-1]]+subtree_size[iToS[j-1]] - 1, 1);
			r[j-1]=0;
		} else {
			cin>>s;
			pln(match(s));
		}
	}
}
