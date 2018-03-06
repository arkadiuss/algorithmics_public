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
int perm[MAX],perm2[MAX];
int p=29;
bool was[10000000]={0};
int power(){
	loop(i,1,n){
		size=size*i;
	}
}
bool check(){
	int sum=0;
	loop(i,1,n){
		sum=sum*p+perm[i];
	}
	if(was[sum])
		return 0;
	was[sum]=1;	
	return 1;		
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,1,n){
		cin>>perm[i];
		
	}
	int j=n;
	power();
	loop(i,1,size){
		loop(j,1,n){	
			if(j>n-3){
				if(i%2==1)
					swap(perm[n-1],perm[n]);
				else
					swap(perm[n-2],perm[n]);	
			}
		}
		if(i%6==1&&i!=1){
			int k=1;
			int tofind=perm[1]+1;
			if(tofind==n+1)
				tofind=1;
			while((perm[k]!=tofind)){
				k++;
			}
			swap(perm[1],perm[k]);
		}
		coutTab(perm,n);
	}
	//coutTab(perm,n);
	/*loop(i,1,size/2-1){
		loop(i,1,n)
			perm2[i]=perm[i];	
		next_permutation(perm,perm+n);
		next_permutation(perm2,perm2+n);
		next_permutation(perm2,perm2+n);
		coutTab(perm2,n);
		coutTab(perm,n);
	}
	*/
	
}
