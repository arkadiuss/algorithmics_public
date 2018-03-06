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
const int MAX=50100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int n;
vector<VI > G(MAX);
vector<VI > GT(MAX);
int pwrs[MAX][10];
bool visited[MAX];
bool visitedT[MAX];
int visCo=0;
bool can[MAX];
bool dfs(int v){
    int c=0;
    //ps(v);
    if(visCo!=-1&&!visited[v]) visCo++;
    visited[v]=1;
    bool res=0;
    loop(i,0,SIZE(G[v])){
        if(visited[G[v][i]]){
            if(can[G[v][i]]) return 1;
            //res=res||dfs(G[v][i]);
        }else if(!visited[G[v][i]]){

            res=res||dfs(G[v][i]);
        }
    }
    return res;
}
void dfsT(int v){
    loop(i,0,SIZE(GT[v])){
        if(!visitedT[GT[v][i]]){
            visitedT[GT[v][i]]=1;
            can[GT[v][i]]=1;
            dfs(GT[v][i]);
        }
    }
}
int main(){
	ios_base::sync_with_stdio(0);
    int k;
    cin>>n>>k;
    pln(1);
    loop(j,0,k){
        cin>>pwrs[0][j];
    }
    loop(i,1,n){
        loop(j,0,k) cin>>pwrs[i][j];
        loop(j,0,i){
            bool oTN=false;
            bool nTO=false;
            loop(p,0,k){
                if(pwrs[j][p]>pwrs[i][p]) oTN=true;
                else nTO=true;
            }
            if(oTN){
                G[j].pb(i);
                GT[i].pb(j);
            }
            if(nTO){
                G[i].pb(j);
                GT[j].pb(i);
            }
        }
        /*loop(j,0,i+1){
            ps(j);ps(": ");
            loop(p,0,SIZE(G[j])){
                ps(G[j][p]);
            }
            entr;
        }*/
        int c=0;
        loop(p,0,i+1){
            visited[p]=0;
            visitedT[p]=0;
            can[p]=0;
        }
        visCo=0;
        loop(j,0,i+1){
            //visited[j]=1;
            if(dfs(j)||visCo==i+1){
                c++;
                //ps(visCo);pln(j);
                can[j]=1;
                dfsT(j);
            }
            if(visCo==i+1) visCo=-1;
           // entr;
        }

        pln(c);
    }
}
