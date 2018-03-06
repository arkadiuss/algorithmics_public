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

void coutTab(int * tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------------
int n;
int a[1000003];
int A[2*MAX];
ll B[2*MAX];
int D;
int gcd(int a, int b){
	if(a<b)
		swap(a,b);
	if(b==0) return a;	
	return gcd(b,a%b);
}
void countD(){
	D=1;
	while(D<n) D*=2;
}
void createTrees(){
	loop(i,D,D+n){
		A[i]=a[i-D];
		B[i]=a[i-D];
	}
	loopback(i,D-1,1){
		A[i]=gcd(A[2*i],A[2*i+1]);
	}
}
int readA(int L,int R){
	L=L+D;
	R=R+D;
	int agcd=A[L];
	while(L<R){
		if(L%2==1) agcd=gcd(agcd,A[L]);
		if(R%2==0) agcd=gcd(agcd,A[R]);
		L=(L+1)/2;
		R=(R-1)/2;
	}
	if(L==R) agcd=gcd(agcd,A[L]);
	return agcd;
}
void setB(int L, int R, ll v){
	L=L+D;
	R=R+D;
	while(L<R){
		if(L%2==1) B[L]=max(B[L],v);
		if(R%2==0) B[R]=max(B[R],v);
		L=(L+1)/2;
		R=(R-1)/2;
	}
	if(L==R) B[L]=max(B[L],v);
}
ll readB(int i){
	i=i+D;
	ll maxi=0;
	while(i>0){
		maxi=max(maxi,B[i]);
		i=i/2;
	}
	return maxi;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>a[i];
	}
	countD();
	createTrees();
	//pln(D);
	//coutTab(A,2*D);
	int agcd=a[0];
	ll sum=a[0];
	int j=0;
	loop(i,0,n){
		agcd=readA(i,j);
		if(j<=i){ 
			j=i+1;
			agcd=gcd(a[i],a[j]);
			sum=a[i]+a[j];
		}
		//ps(agcd);
		while(j<n&&agcd>1){
			j++;
			sum=sum+a[j];
			agcd=gcd(agcd,a[j]);
		}
		if(j<n-1||(j==n-1&&agcd==1)){
			sum-=a[j];
			j--;
		}
		//ps(i);ps(j);pln(sum);
		
		setB(i,j,sum);
		sum-=a[i];
		//coutTab(B,2*D);
	}
	loop(i,0,n){
		if(a[i]==1) ps(0);
		else ps(readB(i));
	}
}
