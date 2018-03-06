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
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
struct seg{
	int id;
	int i,j,k;
	int ans;
};
bool sortSegByK(seg a, seg b){
	return a.k<b.k;
}
bool sortSegById(seg a, seg b){
	return a.id<b.id;
}
struct el{
	int a;
	int pos;
};
bool sortElByA(el a,el b){
	return a.a<b.a;
}
int n;
el els[MAX];
seg sgs[MAX];
int D;
int tree[MAX];
void countD(){
	D=1;
	while(D<n) D*=2;
}
void add(int i){
	i+=D;
	while(i>0){
		tree[i]++;
		i=i/2;
	}
}
int query(int L,int R){
	L+=D;
	R+=D;
	int sum=0;
	while(L<R){
		if(L%2==1){
			sum+=tree[L];
		}
		if(R%2==0){
			sum+=tree[R];
		}
		L=(L+1)/2;
		R=(R-1)/2;
	}
	if(L==R){
		sum+=tree[L];
	}
	return sum;
}
int getFromSeg(int i, int j){
	if(i==0) return query(0,j);
	return query(0,j)-query(0,i-1);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	countD();
	loop(i,0,n){
		cin>>els[i].a;
		els[i].pos=i;
	}
	int q;
	cin>>q;
	loop(i,0,q){
		cin>>sgs[i].i>>sgs[i].j>>sgs[i].k;
		sgs[i].id=i;
	}
	sort(sgs,sgs+q,sortSegByK);
	sort(els,els+n,sortElByA);
	int j=0;
	loop(i,0,q){
		while(j<n&&els[j].a<=sgs[i].k){
			add(els[j].pos);
			j++;
		}
		sgs[i].ans=sgs[i].j-sgs[i].i-getFromSeg(sgs[i].i-1,sgs[i].j-1)+1;
		//loop(l,1,2*D) ps(tree[l]);
		//entr;
		//pln(query(0,sgs[i].j-1));
		
	}
	sort(sgs,sgs+q,sortSegById);
	loop(i,0,q){
		pln(sgs[i].ans);
	}
}
