#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
const int INFTY=20000000;
const int MAX=5100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int G[MAX][MAX];
int bruteSizes[MAX];
int n;
void coutG(){
	loop(i,0,n){
		cout<<i<<": ";
		loop(j,0,n){
			cout<<G[i][j]<<" ";
		}
		entr;
	}

}
int main(){
	ios_base::sync_with_stdio(0);
	
	cin>>n;
	int a;
	loop(i,0,n){
		loop(j,0,n){
			G[i][j]=0;
		}
	}
	loop(i,0,n){
		loop(j,0,i){
			cin>>a;
			if(a==1){
				G[j][i]=1;
			}else
				G[i][j]=1;
		}
	}
	//coutG();
	bool every=1;
	/*loop(i,0,n){
		cin>>bruteSizes[i];
		if(bruteSizes[i]<n) every=0;
		loop(j,0,bruteSizes[i]){
			cin>>a;
		}
	}*/
	//cout<<"jest"<<"\n";
	bool pass=1;
	int size,preva,T;
	cin>>T;
	loop(i,0,T){
		cin>>size;
		//if(size!=bruteSizes[i])
		//	pass=0;
		if(size!=0) cin>>preva;	
		int firsta=preva;
		loop(i,1,size){
			cin>>a;	
			if(!G[preva-1][a-1]){ 
				pass=0;
				cout<<preva<<" "<<a<<"\n";
			}
			preva=a;
		}
		if(size>1&&!G[preva-1][firsta-1]) pass=0;		
	}
	if(!every) pln("Not every");
	else if(pass) pln("OK");
	else pln("fail");
}
