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
const int MAX=200100;
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
int n,D;
ll treei[4*MAX];
ll treepf[4*MAX];
ll treepb[4*MAX];
int a[MAX];
int pos[MAX];
void countD() {
	D=1;
	while(D<=n) D*=2;
}

void prep_trees() {
	loop(i,0,2*D) treei[i]=0;
	loop(i,0,2*D) treepf[i]=0;
	loop(i,0,2*D) treepb[i]=0;
}

void add(ll *tree, int i, ll v) {
	i += D;
	while(i>0){
		tree[i]+=v;
		i/=2;
	}
}

ll read(ll * tree, int L, int R) {
	L += D;
	R += D;
	ll v=0;
	while(L < R) {
		if(L%2==1) {
			v+=tree[L];
		}
		if(R%2==0) {
			v+=tree[R];
		}
		L=(L+1)/2;
		R=(R-1)/2;
	}
	if(L==R) {
		v += tree[L];	
	}
	return v;
}

int findp(int k) {
	int s=0, e=n-1;
	while(s<e) {
		int m=(s+e)/2;
		if(read(treei, 0, m)>=(k+1)/2) {
			e=m;
		} else {
			s=m+1;
		}
	}
	return s;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	countD();
	prep_trees();
	loop(i,0,n) {
		cin>>a[i];
		a[i]--;
		pos[a[i]]=i;
	}
	ll res = 0;
	ll inv = 0;
	for(ll k=1;k<n+1;k++) {
		add(treei, pos[k-1],1);
		add(treepf, pos[k-1], pos[k-1]);
		add(treepb, pos[k-1], n - pos[k-1] - 1);
		ll p = findp(k);
		ll mvf = read(treepf,p+1,n) - (p+1)*(k/2) - (k/2-1)*(k/2)/2;
		ll mvb = read(treepb,0,p-1) - (n-p)*((k-1)/2) - ((k-1)/2-1)*((k-1)/2)/2;
		//ps(p-1);ps(read(treepb,0,p-1));pln(((k-2)/2+1)*((k-2)/2)/2);
		inv += (ll) read(treei, pos[k-1]+1,n-1);
		//ps(p);ps(inv);ps(mvf);pln(mvb);
		res = inv + mvf + mvb;
		ps(res);
	}
	entr;
}
