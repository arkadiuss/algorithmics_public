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
const int MAX=200100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
struct seg{
	int a,b,i,c;
};
struct num{
	int v,io,i;
};
num mn(int v,int io,int i){
	num m;
	m.v=v;
	m.io=io;
	m.i=i;
	return m;
}
bool sortByVal(num a,num b){
	return a.v<b.v;
}
bool sortByInd(num a,num b){
	if(a.i==b.i) return a.v<b.v;
	return a.i<b.i;
}
bool sortSegByB(seg a,seg b){
	return a.b<b.b;
}
bool sortSegByI(seg a,seg b){
	return a.i<b.i;
}
int n;
seg sgs[MAX];
int tree[5*MAX];
int d=1;
void renumber(){
	vector<num> nms;
	loop(i,0,n){
		nms.pb(mn(sgs[i].a,-1,i));
		nms.pb(mn(sgs[i].b,-1,i));
	}
	sort(ALL(nms),sortByVal);
	loop(i,0,SIZE(nms)) nms[i].io=i;
	sort(ALL(nms),sortByInd);
	loop(i,0,n){
		sgs[i].a=nms[2*i].io;
		sgs[i].b=nms[2*i+1].io;
	}
}
void add(int i){
	i=i+d;
	while(i>0){
		tree[i]++;
		i=i/2;
	}
}
int read(int L,int R){
	int S=0;
	L+=d;
	R+=d;
	while(L<=R){
		if(L%2==1) S+=tree[L];
		if(R%2==0) S+=tree[R];
		L=(L+1)/2;
		R=(R-1)/2;
	}
	return S;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n) {
		cin>>sgs[i].a>>sgs[i].b;
		sgs[i].i=i;
	}
	renumber();
	sort(sgs,sgs+n,sortSegByB);
	while(d<2*n) d*=2;
	//coutTab(tree,2*d);
	loop(i,0,n){
		sgs[i].c=read(sgs[i].a+1,sgs[i].b-1);
		add(sgs[i].a);
	}
	sort(sgs,sgs+n,sortSegByI);
	loop(i,0,n){
		pln(sgs[i].c);
	}
}
