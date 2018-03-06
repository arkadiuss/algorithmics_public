#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<=s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
using namespace std;
const int INFTY=20000000;
const int MAX=12;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,1,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int size=1,n;
int p=29;
bool was[10000000]={0};
int power(){
	loop(i,1,n){
		size=size*i;
	}
}
/*bool check(){
	int sum=0;
	loop(i,1,n){
		sum=sum*p+perm[i];
	}
	if(was[sum])
		return 0;
	was[sum]=1;	
	return 1;		
}*/
int* go(int n2,int perm[MAX] ){
	int initperm[MAX];
	loop(i,1,n)
		initperm[i]=perm[i];
	if(n2==3){
		coutTab(perm,n);
		swap(perm[n],perm[n-1]);
		coutTab(perm,n);
		swap(perm[n],perm[n-2]);
		coutTab(perm,n);
		swap(perm[n],perm[n-1]);
		coutTab(perm,n);
		swap(perm[n],perm[n-2]);
		coutTab(perm,n);
		swap(perm[n],perm[n-1]);
		coutTab(perm,n);
	}else{
		perm=go(n2-1,perm);
		loop(i,1,n)
			perm[i]=initperm[i];
		loop(i,n-n2+2,n){
			swap(perm[n-n2+1],perm[i]);
			perm = go(n2-1,perm);
			loop(i,1,n)
				perm[i]=initperm[i];
		}
	}
	return perm;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	int perm[MAX];
	loop(i,1,n){
		cin>>perm[i];	
	}
	
	int j=n;
	power();
	go(n,perm);
	
}
