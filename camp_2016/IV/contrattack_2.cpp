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

void coutTab(bool* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int n,q,k;
int woods[MAX];
bool good[MAX];
bool was[MAX];
void animal(int s,int e){
	int j=s;
	was[woods[s]]=1;
	loop(i,s+1,e){
		good[i]=0;
	}
	loop(i,s,e){
		if(i>s) was[woods[i-1]]=0;
		while(j<e-1&&!was[woods[j+1]]){
			j++;
			was[woods[j]]=1;
		}
		//cout<<i<<" "<<j<<"\n";
		if(j-i+1==k)
			good[j]=1;	
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>k>>q;
	loop(i,0,n){
		cin>>woods[i];
	}
	int t,a,b;
	animal(0,n);
	
	loop(z,0,q){
		cin>>t;
		
		if(t==1){
			cin>>a>>b;
			woods[a-1]=b;
			animal(max(0,a-k-1),min(a+k+1,n));
		}else{
			cin>>a>>b;
			if(good[b-1])
				cout<<"TAK"<<"\n";
			else
				cout<<"NIE"<<"\n";	
		}
		//coutTab(good,n);
	}
}
