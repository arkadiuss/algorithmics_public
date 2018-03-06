#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<=s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pd( x ) cout << x << "\n"
#define pcnt(i) __builtin_popcount(i)
#define ll long long
using namespace std;
const int INFTY=20000000;
const int MAX=1000100;
const int MOD=10000000;
//------------------------------------------
int n;
int fruits[MAX];
int pre[MAX];
int eql[MAX];
int ende[MAX];
int max_lexi(int a,int b){
	if(pre[a]>pre[b])
		return a;	
	else if(pre[b]>pre[a])
		return b;
	else{
		if(a>b)
			return a;
		else
			return b;	
	}
		
}
void countPre(){
	pre[0]=0;
	loop(i,1,n){
		pre[i]=pre[i-1]+fruits[i];
	}
}
void counteql(){
	int lasttime[2*MAX];
	loop(i,0,2*n+1){
		lasttime[i]=-1;
		if(i<=n)
			eql[i]=n;
	}
	loopback(i,n,0){
		if(lasttime[pre[i]+n]==-1)
			lasttime[pre[i]+n]=i;
		else{
			eql[i]=lasttime[pre[i]+n];
			lasttime[pre[i]+n]=i;
		}
			
	}
}
void coutTab(int* tab){
	loop(i,0,n){
		cout<<(tab[i])<<" ";
	}
	cout<<"\n";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	char a;
	loop(i,1,n){
		cin>>a;
		if(a=='j')
			fruits[i]=-1;
		else
			fruits[i]=1;	
	}
	countPre();
	counteql();
	//coutTab(pre);
	//coutTab(eql);
	ende[n]=n;
	loopback(i,n-1,0){
		if(fruits[i+1]==-1)
			ende[i]=i;
		else{
			if(i==n-1)
				ende[i]=i+1;
			else if(eql[i]==n)
				ende[i]=ende[i+1];
			else
				ende[i]=ende[max_lexi(ende[i+1],ende[eql[i]])];		
		}	
	}
	//coutTab(ende);
	int maxlen=0;
	loop(i,0,n){
		maxlen=max(maxlen,ende[i]-i);
	}	
	cout<<maxlen;
}
