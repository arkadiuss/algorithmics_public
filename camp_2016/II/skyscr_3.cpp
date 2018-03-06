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
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int a[MAX],b[MAX];
int n,d=1;
int tree[3*MAX];
void findTreeSize(){
	while(d<n)
		d=d*2;
}
void update(int i,int v){
	i=i+d;
	tree[i]=v;
	i=i/2;
	while(i>0){
		tree[i]=tree[i*2]+tree[i*2+1];
		i=i/2;
	}
}
void createTree(){
	loop(i,0,n){
		update(i,1);
	}
}
int find(int l){
	int sum=0;
	int i=1;
	//cout<<l<<"\n";
	if(l==tree[1]){
		while(i<d){
			if(tree[i*2+1]>0)
				i=i*2+1;
			else
				i=i*2;	
		}
		return i;
	}
	while(i<d){
		//cout<<i<<" "<<tree[i*2+1]<<" "<<sum<<" ";
		if(sum==l){
			if(tree[i*2+1]>0)
				i=i*2+1;
			else
				i=i*2;	
			//cout<<"\n";
		}else if(l-sum<tree[i*2+1]){
			i=i*2+1; //cout<<1<<"\n";
			if(d<=i)
				l=l-tree[i];
		}else{
			//cout<<0<<"\n";
			sum=sum+tree[i*2+1];
			i=i*2;
		}	
	}
	return i-d;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	findTreeSize();
	loop(i,0,n){
		cin>>a[i];
	}
	createTree();
	//coutTab(tree,2*d);
	loop(i,0,n){
		int l=find(a[i]);
		update(l,0);
		cout<<l+1<<" ";	
	}
	//coutTab(tree,2*d);
	
}
