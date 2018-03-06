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
typedef pair<int,int> PII;
const int INFTY=2000000000;
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		if(tab[i]<0) ps("-");
		else cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int n,D,k;
int a[MAX];
int AT[3*MAX], AS[3*MAX],AIS[3*MAX],B[3*MAX];
void countD(){
	D=1;
	while(D<n) D*=2;
}
void createAB(){
	loop(i,0,n){
		AS[i+D]=a[i];
		AIS[i+D]=i+D;
	}
	loopback(i,D-1,1){
		if(AS[2*i]>AS[2*i+1]) AIS[i]=AIS[2*i];
		else AIS[i]=AIS[2*i+1];
		AS[i]=max(AS[2*i],AS[2*i+1]);
	}
	
}
void coutA(){
	pln("couting tree");
	coutTab(AS,2*D);
	coutTab(AT,2*D);
	coutTab(AIS,2*D);
}

void addA(int L, int R, int v){
	L=L+D;
	R=R+D;
	AT[L]+=v;
	AS[L]+=v;
	if(L!=R){
		AS[R]+=v;
		AT[R]+=v;
	}
	while(L>0){
		if(L<R-1){
			if(L%2==0){
				AT[L+1]+=v;
				AS[L+1]+=v;
			}
			if(R%2==1){
				AT[R-1]+=v;
				AS[R-1]+=v;
			}
		}
		if(L<D){
			if(AS[2*L]>AS[2*L+1])
				AIS[L]=AIS[2*L];
			else
				AIS[L]=AIS[2*L+1];	
			AS[L]=max(AS[2*L],AS[2*L+1])+AT[L];
			if(AS[2*R]>AS[2*R+1])
				AIS[R]=AIS[2*R];
			else
				AIS[R]=AIS[2*R+1];
			AS[R]=max(AS[2*R],AS[2*R+1])+AT[R];
		}
		L/=2;
		R/=2;
	}
}
PII readA(int L, int R){
	L=L+D;
	R=R+D;
	int maxl=-INFTY;
	int maxr=-INFTY;
	maxl=AS[L];
	maxr=AS[R];
	int maxir=R;
	int maxil=L;
	while(L>0){
		if(L<D){
			maxl+=AT[L];
			maxr+=AT[R];
		}
		//ps(L);
		//ps(R);
		//ps(maxl);
		//pln(maxr);
		if(L<R-1){
			if(L%2==0){
				if(AS[L+1]>maxl)
					maxil=AIS[L+1];	
				maxl=max(maxl,AS[L+1]);	
				
			}
			if(R%2==1){
				if(AS[R-1]>maxr)
					maxir=AIS[R-1];
				maxr=max(maxr,AS[R-1]);
				
			}
		}
		L/=2;
		R/=2;
	}
	if(maxl>maxr) return mp(maxil,maxl);
	else return mp(maxir,maxr);
}
void addB(int i,int v){
	i=i+D;
	B[i]=B[i]+v;
	i=i/2;
	while(i>0){
		B[i]=B[2*i]+B[2*i+1];
		i=i/2;
	}
}
void updateB(int L,int R){
	PII res=readA(L,R);
	//ps(res.ss);
	while(res.ss>=k){
		addA(res.ff-D,res.ff-D,-INFTY);
		addB(res.ff-D,1);
		res=readA(L,R);
		//ps(res.ss);
	}
}
int readB(int L, int R){
	updateB(L,R);
	L=L+D;
	R=R+D;
	int res=0;
	while(L<R){
		if(L%2==1) res+=B[L];
		if(R%2==0) res+=B[R];
		L=(L+1)/2;
		R=(R-1)/2;
	}
	if(L==R) res+=B[L];
	return res;
}
void inicjuj(int nn, int kk, int* aa){
	n=nn;
	countD();
	k=kk;
	loop(i,0,n) a[i]=aa[i];
	createAB();
}
void podlej(int aa,int bb){
	addA(aa,bb,1);
}
int dojrzale(int aa,int bb){
	return readB(aa,bb);
}
/*int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k;
	countD();
	loop(i,0,n) cin>>a[i];
	createAB();
	int q,t,a,b,v;
	//coutA();
	cin>>q;
	loop(i,0,q){
		cin>>t;
		if(t==1){
			cin>>a>>b>>v;
			addA(a-1,b-1,v);
		}else{
			cin>>a>>b;
			pln(readB(a-1,b-1));
			//pln(res.ss);
		}
		//coutA();
		//coutTab(B,2*D);
	}
	
}*/
