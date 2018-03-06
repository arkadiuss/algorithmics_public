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
const int MAX=3010;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}

//------------------------------------------
bool G[MAX][MAX];
int n,m,a,b;
bool go;
void coutTabD(int n){
	loop(i,1,n+1){
		loop(j,1,n+1)
			cout<<G[i][j]<<" ";
		cout<<"\n";
	}
}
	
int main(){
	ios_base::sync_with_stdio(0);
	int maxk;
	cin>>n>>m;
	loop(i,0,m){
		cin>>a>>b;
		G[a][b]=1;
		G[b][a]=1;
	}
	loop(i,0,n){
		G[i+1][i+1]=1;
	}
	//coutTabD(n);
	vector<int> K,Kempty,Kmax;
	loop(mask,0,1<<n){
		loop(j,0,n){
			if((1<<j)&mask)
				K.push_back(j);
				
		}
		go=1;
		for(int i=0;i<K.size()&&go;i++){
			loop(j,0,K.size()){
				if(!G[K[i]+1][K[j]+1]){
					go=0;
					break;
				}	
			}
		}
		if(go==1){maxk=pcnt(mask);Kmax=K;}
		K=Kempty;
	}
	cout<<maxk<<"\n";
	loop(i,0,Kmax.size()){
		cout<<Kmax[i]+1<<" ";
	}
	
	//coutTabD(m);
}
