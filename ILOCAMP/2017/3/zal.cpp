#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define foreach(i,c) for(VAR(i,c.begin());i!=c.end();i++)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) c.size()
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const int MAX=530100;
const int MOD=1000000000;
const int INFTY=1000000000;
typedef vector<int> VI;

void coutTab(int * tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------
int maxB[MAX];
int n,k,ch[MAX];
int tree[2*MAX];
int D;
int countD(){
	D=1;
	while(D<k) D*=2;
}
void update(int i, int v){
	i=i+D;
	tree[i]+=v;
	i=i/2;
	while(i>0){
		tree[i]=min(tree[2*i],tree[2*i+1]);
		i=i/2;
	}
}
int readMin(int L,int R){
	L=L+D;
	R=R+D;
	int mini=INFTY;
	while(L<R){
		if(L%2==1) mini=min(tree[L],mini);
		if(R%2==0) mini=min(tree[R],mini);
		L=(L+1)/2;
		R=(R-1)/2;
	}
	if(L==R) mini=min(tree[L],mini);
	return mini;
}
int main(){
	ios_base::sync_with_stdio(0);
	int q;
	cin>>n>>k>>q;
	loop(i,0,n){
		cin>>ch[i];
	}
	int j=0;
	countD();
	update(ch[0],1);
	loop(i,0,n){
		
		if(j<=i){
			if(j<i) update(ch[i],1);
			j=i+1;
			update(ch[j],1);
		}
		//coutTab(tree,2*D);
		while(j<n&&readMin(1,k)==0){
			j++;
			update(ch[j],1);
		}
		//coutTab(tree,2*D);
		if(j!=n-1||(j==n-1&&readMin(1,k)!=0)) update(ch[j],-1);
		j--;
		//coutTab(tree,2*D);
		maxB[i]=j;
		update(ch[i],-1);
		//entr;
	}
	int a,b;
	loop(i,0,q){
		cin>>a>>b;
		if(maxB[a-1]>=b-1&&k!=1) pln("TAK");
		else pln("NIE");	
	}
}
