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
const int MAX=5100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
bool G[MAX][MAX];
int n,startV,endV;
struct V{
	int p,n;
};
V Vs[MAX];
int find(int j,int size){
	int v=startV;
	loop(i,0,size){
		if(G[v][j]&&G[j][Vs[v].n])
			return v;
		v=Vs[v].n;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	string a;
	loop(i,0,n){
		cin>>a;
		loop(j,0,n){
			if(a[j]=='1'){
				G[i][j]=1;
			}else
				G[i][j]=0;
		}
	}
	loop(i,0,n){
		Vs[i].p=-1;
		Vs[i].n=-1;
	}
	startV=0;
	endV=0;
	int size=1,v;
	loop(i,1,n){
		if(G[i][startV]){
			Vs[startV].p=i;
			Vs[i].n=startV;
			startV=i;
		}else if(G[endV][i]){
			Vs[endV].n=i;
			Vs[i].p=endV;
			endV=i;
		}else{
			v=find(i,size);
			//cout<<v<<"\n";
			Vs[Vs[v].n].p=i;
			Vs[i].n=Vs[v].n;
			Vs[v].n=i;
			Vs[i].p=v;
			
		}
		size++;
	}
	cout<<n<<"\n";
	v=startV;
	loop(i,0,n){
		cout<<v+1<<" ";
		v=Vs[v].n;
	}		
}
