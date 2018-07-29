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
const int MAX=100100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
const int BITS=20;
struct NTree{
	ll mod;
	int count; //hom many numbers
	int val[BITS];
};
int countD(int n){
	int i=1;
	while(i<n){
		i*=2;
	}
	return i;
}
void addToVal(int val[],int a){
	int i = 0;
	while(a>0){
		if(a%2==1) val[i]++;
		i++;
		a/=2;
	}
}
void init(NTree * tree,int * A,int n,int D){
	loop(i,D,2*D){
		tree[i].mod=0;
		tree[i].count=1;
		loop(j,0,BITS){
			tree[i].val[j]=0;
		}
		if(i-D<n){
			addToVal(tree[i].val,A[i-D]);
		}
	}
	loopback(i,D-1,1){
		tree[i].count = tree[2*i].count+tree[2*i+1].count;
		loop(j,0,BITS){
			tree[i].val[j]=tree[2*i].val[j]+tree[2*i+1].val[j];
		}
	}
}
void applyXor(int val[],int count,int x){
	/*loop(i,0,BITS)
		cout<<val[i];
	ps(" ");	
	ps(x);*/
	int i=0;
	while(x>0){
		if(x%2==1){
			val[i]=count-val[i];
		}
		i++;
		x/=2;
	}
	/*loop(i,0,BITS)
		cout<<val[i];
	ps(" ");
	entr;*/
}
ll countVal(int val[]){
	int d=0;
	ll b=1;
	ll v=0;
	loop(i,0,BITS){
		//ps(val[i]+d);
		if((val[i]+d)%2==1){
			v+=b;
		}
		d=((val[i]+d)/2);
		b*=2;
	}
	while(d>0){
		if(d%2==1) v+=b;
		d=d/2;
		b*=2;
	}
	//pln(v);
	return v;
}
void update(NTree * tree,int l,int r,int a,int b,ll x,int D){
	int rp = (b+D)/(b-a+1);
	if(b<l||a>r) return;
	else if(l<=a&&b<=r){
		tree[rp].mod^=x;
		applyXor(tree[rp].val,tree[rp].count,x);
	}else{
		if(tree[rp].mod!=0){
			tree[2*rp].mod^=tree[rp].mod;
			applyXor(tree[2*rp].val,tree[2*rp].count,tree[rp].mod);
			tree[2*rp+1].mod^=tree[rp].mod;
			applyXor(tree[2*rp+1].val,tree[2*rp+1].count,tree[rp].mod);
			tree[rp].mod=0;
		}
		update(tree,l,r,a,(a+b)/2,x,D);
		update(tree,l,r,(a+b)/2+1,b,x,D);
		loop(j,0,BITS){
			tree[rp].val[j]=tree[2*rp].val[j]+tree[2*rp+1].val[j];
		}
	}
}
ll query(NTree * tree,int l,int r,int a,int b,int D){
	int rp = (b+D)/(b-a+1);
	if(b<l||a>r) return 0;
	else if(l<=a&&b<=r){
		return countVal(tree[rp].val);
	}else{
		if(tree[rp].mod!=0){
			tree[2*rp].mod^=tree[rp].mod;
			applyXor(tree[2*rp].val,tree[2*rp].count,tree[rp].mod);
			tree[2*rp+1].mod^=tree[rp].mod;
			applyXor(tree[2*rp+1].val,tree[2*rp+1].count,tree[rp].mod);
			tree[rp].mod=0;
		}
		return query(tree,l,r,a,(a+b)/2,D)+query(tree,l,r,(a+b)/2+1,b,D);
	}
}
void coutTree(NTree * tree,int D){
	loop(i,1,2*D){
		cout<<i<<": ";
		loop(j,0,BITS)
			cout<<tree[i].val[j];
		entr;		
	}
	entr;
}
int main(){
	ios_base::sync_with_stdio(0);
	NTree * tree = new NTree[10*MAX];
	int * A = new int[MAX];
	int n,D;
	cin>>n;
	D=countD(n);
	loop(i,0,n){
		cin>>A[i];
	}
	init(tree,A,n,D);
	int q,t,l,r;
	ll x;
	cin>>q;
	while(q--){
		cin>>t;
		if(t==1){
			cin>>l>>r;
			pln(query(tree,l-1,r-1,0,D-1,D));
		}else{
			cin>>l>>r>>x;
			update(tree,l-1,r-1,0,D-1,x,D);
		}
		//coutTree(tree,D);
	}
	delete [] A;
	delete [] tree;
}
