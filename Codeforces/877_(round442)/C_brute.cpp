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
struct f{
	bool t1,t2;
};
f fs[MAX];
int pts[20];
int n;
void put(int i){
	if(i==1){
		if(fs[i].t2){
			fs[i].t2=0;
			fs[i+1].t1=1;
		}
		fs[i].t1=0;	
	}else if(i==n){
		if(fs[i].t2){
			fs[i].t2=0;
			fs[i-1].t1=1;
		}
		fs[i].t1=0;
	}else{
		if(fs[i].t2){
			fs[i].t2=0;
			fs[i-1].t1=1;
			fs[i+1].t1=1;
		}
		fs[i].t1=0;
	}
}
bool check(){
	loop(i,1,n+1){
		if(fs[i].t1||fs[i].t2) return false;
	}
	return true;
}
int main(){
	//ios_base::sync_with_stdio(0);
	cin>>n;
	int S=1;
	loop(i,1,n+1){
		fs[i].t2=1;
		pts[2*i-1]=i;
		pts[2*i]=i;
		S*=i;
	}
	loop(i,n+1,2*n+1) S*=i;
	int j=1,minj=1000;
	while(S--){
		//coutTab(pts,2*n);
		loop(i,1,n+1){
			fs[i].t2=1;
			fs[i].t1=0;
		}
		j=1;
		while(j<=2*n&&!check()){
			put(pts[j]);
			j++;		
		}
		int tmp=2*n+1;
		next_permutation(pts+1,pts+tmp);
		if(j==8)
			coutTab(pts,2*n);
		minj=min(minj,j);
		
	}
	pln(--minj);
}
