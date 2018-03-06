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
int tree[MAX*3],S[MAX*3],a[MAX],b[MAX];
int d=1,n;
void findTreeSize(){
	while(d<n)
		d=d*2;
}
void update(int i,int v){
	i=i+d;
	tree[i]=v;
	i=i/2;
	while(i>0){
		if(a[tree[i*2+1]]<a[tree[i*2]])
			tree[i]=tree[i*2+1];
		else
			tree[i]=tree[i*2];	
		i=i/2;
	}
}

void createTree(){
	loop(i,0,d+1){
		if(i<n-1)
			update(i,i);
		else
			update(i,n);
	}
}
int getMin(){
	/*int mini=n;
	L=L+d;
	R=R+d;
	while(L<R){
		cout<<L<<" "<<R<<"\n";
		if(L%2==1){
			if(a[mini]>a[L])
				mini=L;
		}
		if(R%2==0){
			if(a[mini]>a[R])
				mini=R;
		}
		L=(L+1)/2;
		R=(R-1)/2; 
	}
	if(a[mini]>a[R])
		mini=R;*/
	return tree[1];
}
int find(int p,int k,int i){
	int pos=0;
	bool first=1;
	loop(j,p,k){
		if(a[j]==i&&first){
			pos=find(p,j+1,i+1)+1;
			first=0;
		}else if(a[j]==i)
			pos++;	
	}
	return pos;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	findTreeSize();
	loop(i,0,n){
		cin>>a[i];
	}
	a[n]=INFTY;
	createTree();
	//coutTab(tree,2*d);
	int p=n,mini;
	int pos=find(0,n-1,0);
	loop(i,0,n){
		if((n-p)==pos)
			mini=n-1;
		else	
			mini=getMin();
		
		cout<<mini<<" ";
		b[mini]=p;
		a[mini]=INFTY;
		update(mini,mini);
		p--;
	}
	entr;
	loop(i,0,n)
		cout<<b[i]<<" ";
}
