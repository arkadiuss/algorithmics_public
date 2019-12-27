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
int A[MAX];
struct query {
	int k,p,i,res;
};
query qs[MAX]; 
bool cmpq(query & a, query & b) {
	if(a.k == b.k) return a.p < b.p;
	return a.k < b.k;
}
bool cmpq2(query & a, query & b) {
	return a.i < b.i;
}

int tree[5*MAX];
int D;
void countD(int n) {
	D = 1;
	while(D < n) {
		D*=2;
	}
}

void init_tree() {
	loop(i,0,2*D) tree[i] = 0;
}

void insert(PII a) {
	int i = a.ss+D;
	tree[i] = a.ff;
	i/=2;
	while(i>0) {
		if(i*2>=D) {
			tree[i]=min(tree[2*i],1)+min(tree[2*i+1],1);
		} else {
			tree[i]=tree[2*i]+tree[2*i+1];
		}
		i/=2;
	}
}

int pfind(int p) {
	int i=1;
	p++;
	while(i<D) {
		if(2*i>=D) {
			if(p==1&&tree[2*i]) i=2*i;
			else i=2*i+1;
		} else {
			if(tree[2*i]<p) {
				p-=tree[2*i];
				i=2*i+1;
			} else {
				i=2*i;
			}
		}
	}
	//ps(p);pln(i);
	return tree[i];
}

int main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n;
	countD(n);
	init_tree();
	priority_queue<PII> Q;
	loop(i,0,n) {
		cin>>A[i];
		Q.push({A[i],-i});
	}
	cin>>m;
	loop(i,0,m){
		cin>>qs[i].k>>qs[i].p;
		qs[i].i=i;
	}
	sort(qs,qs+m,cmpq);
	int j=0;
	loop(i,0,n){
		PII v = Q.top();
		Q.pop();
		insert({v.ff,-v.ss});
		//pln("");
		//coutTab(tree, 2*D);
		while(j < m && qs[j].k == i+1) {
			//ps(qs[j].k);pln(qs[j].p);
			qs[j].res = pfind(qs[j].p-1);
			j++;
		}
	}
	sort(qs,qs+m,cmpq2);
	loop(i,0,m) {
		pln(qs[i].res);
	}
}
