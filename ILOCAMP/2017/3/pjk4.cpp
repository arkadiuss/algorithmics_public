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
const int MAX=1050100;
const int MOD=1000000000;
const int INFTY=1000000000;
typedef vector<int> VI;

void coutTab(int* tab, int n){
	loop(i,0,n){
		if(tab[i]<-100) ps("-");  
		else ps(tab[i]);
	}
	entr;
}
//---------------------------------
bool c[MAX],p[MAX];
int n,D;
int T[2*MAX],S[2*MAX];
bool check(){
	loop(i,0,n-1){
		if(c[i]&&!c[i+1]) return 0;
	}
	return 1;
}
void countD(){
	D=1;
	while(D<n) D*=2;
}
int countFirst(){
	int k=0;
	loop(i,0,n){
		if(c[i])
			k++;
	}
	int l1l=n-1;
	while(c[l1l]) l1l--;
	int l1=0;
	int maxl=0;
	loop(i,0,l1l+1){
		if(c[i]){
			maxl=max(maxl,n-k-i+2*l1);
			S[i+D]=-i+2*l1;
			//ps(n-k-i+2*l1);
			l1++;
		}else{
			S[i+D]=-INFTY-i+2*l1;
			//ps("-");
		}
	}

	loopback(i,D-1,1){
		S[i]=max(S[2*i],S[2*i+1]);
	}
	return maxl;
}
void add(int L, int R, int v){
	L=L+D;
	R=R+D;
	S[L]+=v;
	T[L]+=v;
	if(L!=R){
		S[R]+=v;
		T[R]+=v;
	}
	while(L>0){
		if(L<R-1){
			if(L%2==0){
				T[L+1]+=v;
				S[L+1]+=v;
			}
			if(R%2==1){
				T[R-1]+=v;
				S[R-1]+=v;
			}
		}
		if(L<D){
			S[L]=max(S[2*L],S[2*L+1])+T[L];
			S[R]=max(S[2*R],S[2*R+1])+T[R];
		}
		L/=2;
		R/=2;
	}
}
int read(int L, int R){
	L=L+D;
	R=R+D;
	int ml=S[L];
	int mr=S[R];
	while(L>0){
		if(L<D){
			ml+=T[L];
			mr+=T[R];
		}
		if(L<R-1){
			if(L%2==0){
				ml=max(ml,S[L+1]);
			}
			if(R%2==1){
				mr=max(mr,S[R-1]);
			}
		}
		L/=2;
		R/=2;
	}
	return max(ml,mr);
}
int setVal(int i,int v){
	i=i+D;
	S[i]=v;
	i=i/2;
	while(i>0){
		S[i]=max(S[2*i],S[2*i+1]);
		i=i/2;
	}
}
set<int> zeros;
int main(){
	ios_base::sync_with_stdio(0);
	int q;
	cin>>n>>q;
	int k=0;
	loop(i,0,n){
		cin>>c[i];
		if(!c[i]) zeros.insert(i);
		else k++;
	}
	countD();
	pln(countFirst());
	int a;
	//coutTab(S,2*D);
	//coutTab(T,2*D);
	loop(i,0,q){
		cin>>a;
		int m0;//(*zeros.rbegin());
		if(c[a-1]){
			k--;
			zeros.insert(a-1);
			m0=(*zeros.rbegin());
			//setVal(a-1,-INFTY);
			add(a-1,a-1,-INFTY);
			//coutTab(S,2*D);
			//coutTab(T,2*D);
			if(a<=m0) add(a,m0,-2);
			//coutTab(S,2*D);
			//coutTab(T,2*D);
			pln(max(0,n-k+read(0,m0)));
		}else{
			k++;
			zeros.erase(zeros.find(a-1));
			m0=(*zeros.rbegin());
			//setVal(a-1,-(a-1));
			add(a-1,a-1,INFTY);
			//coutTab(S,2*D);
			//coutTab(T,2*D);
			if(a<=m0)add(a,m0,2);
			
			pln(n-k+read(0,m0));
		}
		//pln(n-k);
		//coutTab(S,2*D);
		//coutTab(T,2*D);
		c[a-1]=!c[a-1];
		//loop(i,0,n) ps(c[i]);
		//entr;
	}
}
