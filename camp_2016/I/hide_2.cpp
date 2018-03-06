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
const int MAX=5010;
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
vector<int> Kmax;
vector<int> Kempty;
bool checkWithZ(int p,vector<int> K){
	loop(i,0,K.size()){
		if(!G[p][K[i]])
			return false;
	}
	return true;
}
bool check(int k){
	vector<int> K;
	loop(i,1,n+1){
		loop(j,1,n+1){
			if(i!=j&&G[i][j]){
				K.push_back(i);
				K.push_back(j);
				int p=1,howmany=2;
				while(p<n&&howmany<k){
					if(p!=i&&p!=j&&G[p][i]&&G[p][j]&&checkWithZ(p,K)){ 
						K.push_back(p);
						howmany++;
					}
					p++;
				}
				if(howmany==k){
					Kmax=K;
					return true;
				}
				K=Kempty;
			}
		}
	}
	return false;
}	
int main(){
	ios_base::sync_with_stdio(0);
	int maxk;
	cin>>n>>m;
	loop(i,0,m){
		cin>>a>>b;
		G[a][b]=1;
		G[b][a]=1;
		if(i==0){
			Kmax.push_back(a);
			Kmax.push_back(b);
		}
	}
	loop(i,0,n){
		G[i+1][i+1]=1;
	}
	int kmax=2;
	loop(k,3,5){
		if(!check(k)) break;
		kmax=k;
	}
	cout<<kmax<<"\n";
	loop(i,0,Kmax.size()) cout<<Kmax[i]<<" ";
}
