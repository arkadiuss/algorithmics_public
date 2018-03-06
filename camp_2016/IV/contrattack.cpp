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
int n,q,k;
int woods[MAX];
bool was[MAX];
bool check(int s,int e){
	loop(i,0,k+1){
		was[i]=0;
	}
	loopback(i,e,s){
		if(was[woods[i]])
			return false;
		else
			was[woods[i]]=1;	
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k>>q;
	loop(i,0,n){
		cin>>woods[i];
	}
	int t,a,b;
	loop(z,0,q){
		cin>>t;
		if(t==1){
			cin>>a>>b;
			woods[a-1]=b;
		}else{
			cin>>a>>b;
			if(check(a-1,b-1))
				cout<<"TAK"<<"\n";
			else
				cout<<"NIE"<<"\n";	
		}
	}
}
