#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define foreach(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n"
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define SIZE(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
using namespace std;
typedef vector<int> VI;
const int INFTY=20000000;
const int MAX=51;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int G[MAX][MAX];
int N, M;
struct query {
	int a, b, z;
};

query qs[1001];

void fw() {
	for(int k=0; k < N; k++) {
		for(int i =0; i < N; i++) {
			for(int j =0; j < N; j++) {
				if(G[i][k] + G[k][j] < G[i][j]) {
					G[i][j] = G[i][k] + G[k][j];
				}
			}
		}
	}
}

bool check() {
	for(int i=0;i<M;i++) {
		if(G[qs[i].a-1][qs[i].b-1] != qs[i].z ||
			G[qs[i].b-1][qs[i].a-1] != qs[i].z)  return false;
	}
	return true;
}

void ans() {
	if(check()) {
		pln(M);
		for(int m=0;m<M;m++) {
			ps(qs[m].a);ps(qs[m].b);pln(qs[m].z);
		}
	} else {
		ps("Impossible\n");
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	int T;
	cin>>T;
	for(int t=1; t<=T; t++) {
		
		cin>>N>>M;
		
		for(int i =0; i < N; i++) {
			for(int j =0; j < N; j++) {
				G[i][j] = INFTY;
			}
		}
		
		for(int m=0;m<M;m++) {
			cin>>qs[m].a>>qs[m].b>>qs[m].z;
			G[qs[m].a-1][qs[m].b-1] = qs[m].z;
			G[qs[m].b-1][qs[m].a-1] = qs[m].z;
		}
		
		fw();
		 		
		cout<<"Case #"<<t<<": ";
		ans();
	}

}
