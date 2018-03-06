#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
using namespace std;
const int INFTY=20000000;
const int MAX=1000100;
const int MOD=10000000;

void coutTab(ll* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int n,q,k,d=1;
ll woods[MAX];
bool was[MAX];
ll change[MAX];
ll tree[3*MAX];
void findD(){
	while(d<n)
		d=d*2;
}

void createTree(){
	loop(i,0,n){
		tree[i+d]=woods[i];
	}
	loopback(i,d-1,0){
		tree[i]=tree[2*i]+tree[2*i+1];
	}
}
void update(int i,int val){
	i=i+d;
	tree[i]=val;
	i=i/2;
	while(i>0){
		tree[i]=tree[2*i]+tree[2*i+1];
		i=i/2;
	}
}
ll read(int L,int R){
	ll sum=0;
	L=L+d;
	R=R+d;
	//if(L==R) sum=tree[L];
	while(L<=R){
		if(L%2==1) sum=sum+tree[L];
		if(R%2==0) sum=sum+tree[R];
		L=(L+1)/2;
		R=(R-1)/2;
	}
	//pln(sum);
	return sum;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k>>q;
	srand(time(NULL));
	loop(i,0,n){
		cin>>woods[i];
	}
	ll sumk=0;
	loop(i,1,k+1){
		change[i]=rand()%9000000+1;
		sumk=sumk+change[i];
	}
	int t,a,b;
	loop(i,0,n){
		woods[i]=change[woods[i]];
	}
	findD();
	createTree();
	//coutTab(woods,n);
	//pln(sumk);
	
	
	loop(z,0,q){
		cin>>t;
		if(t==1){
			cin>>a>>b;
			update(a-1,change[b]);
		}else{
			cin>>a>>b;
			if(read(a-1,b-1)==sumk)
				cout<<"TAK"<<"\n";
			else
				cout<<"NIE"<<"\n";	
		}
		//coutTab(tree,2*d);
	}
}
