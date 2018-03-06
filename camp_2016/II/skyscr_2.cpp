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
int n;
int perm[MAX];
void insert(int i,int val){
	loopback(j,n-1,i){
		perm[j+1]=perm[j];
	}
	perm[i]=val;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	loop(i,0,n){
		cin>>a[i];
	}
	perm[0]=n-1;
	int act_size=1;
	loopback(i,n-2,0){
		//cout<<act_size-a[i]<<"\n";
		insert(act_size-a[i],i);
		act_size++;
	}
	loop(i,0,n){
		b[perm[i]]=i+1;
	}
	loop(i,0,n)
		cout<<b[i]<<" ";
}
