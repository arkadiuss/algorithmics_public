#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define foreach(i,n) for(VAR(i,c.begin());i!=c.end();i++)
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
const int MAX=1100;
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
bool mape[MAX][MAX];
int hm[MAX][MAX];
int n,m;
int l;

void coutHTab(){
	loop(i,0,n){
		loop(j,0,m){
			ps(hm[i][j]);
		}
		entr;
	}
}
int countVal(int i, int j, int c){
	int val=INFTY;
	if(min(i,j)>=c){
			val=hm[i][j];
			if(i-c-1>=0) val-=hm[i-c-1][j];
			if(j-c-1>=0) val-=hm[i][j-c-1];
			if(i-c-1>=0&&j-c-1>=0) val+=hm[i-c-1][j-c-1];
	}
	return val;
}
int first(int i,int j){
	int s=0;
	int e=min(i,j)+1;
	int mid;
	while(s<e){
		mid=(s+e)/2;
		if(countVal(i,j,mid)<l) s=mid+1;
		else e=mid;
	}
	return s;
}
int last(int i,int j){
	int s=0;
	int e=min(i,j)+1;
	int mid;
	while(s<e){
		//entr;ps("bin");ps(s);pln(e);
		mid=(s+e+1)/2;
		if(countVal(i,j,mid)<=l) s=mid;
		else e=mid-1;
	}
	return e;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m>>l;
	char a;
	loop(i,0,n){
		loop(j,0,m){		
			cin>>a;
			if(a=='#')
				mape[i][j]=1;
		}
	}
	hm[0][0]=mape[0][0];	
	loop(i,1,n) hm[i][0]=hm[i-1][0]+mape[i][0];
	loop(i,1,m) hm[0][i]=hm[0][i-1]+mape[0][i];
	loop(i,1,n){
		loop(j,1,m){
			hm[i][j]=hm[i-1][j]+hm[i][j-1]-hm[i-1][j-1]+mape[i][j];
		}
	}
	//coutHTab();
	int v=0;
	loop(i,0,n){
		loop(j,0,m){
			if(countVal(i,j,first(i,j))==l)
				v=v+last(i,j)-first(i,j)+1;
		}
	}
	pln(v);
}
