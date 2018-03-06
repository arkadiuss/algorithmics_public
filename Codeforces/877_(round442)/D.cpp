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
typedef pair<int,int> PII;
const int INFTY=20000000;
const int MAX=1100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
int n,m,k;
int d[MAX][MAX];
char mapp[MAX][MAX];
void bfs(PII s,PII e){
    queue<PII> Q;
    d[s.ff][s.ss]=0;
    Q.push(s);
    while(!Q.empty()){
        PII a=Q.front();Q.pop();
       // ps(a.ff);pln(a.ss);
        loop(i,1,k+1){
            // ps(a.ff);pln(a.ss+i);
            if(a.ss+i>=m||mapp[a.ff][a.ss+i]=='#') break;
            if(d[a.ff][a.ss+i]!=-1) continue;
            else{
                d[a.ff][a.ss+i]=d[a.ff][a.ss]+1;
                if(a.ff==e.ff&&a.ss+i==e.ss) return;
                Q.push(mp(a.ff,a.ss+i));
            }
        }
        loop(i,1,k+1){
            if(a.ss-i<0||mapp[a.ff][a.ss-i]=='#') break;
            if(d[a.ff][a.ss-i]!=-1) continue;
            else{
                d[a.ff][a.ss-i]=d[a.ff][a.ss]+1;
                if(a.ff==e.ff&&a.ss-i==e.ss) return;
                Q.push(mp(a.ff,a.ss-i));
            }
        }
        loop(i,1,k+1){
            if(a.ff+i>=n||mapp[a.ff+i][a.ss]=='#') break;
            if(d[a.ff+i][a.ss]!=-1) continue;
            else{
                d[a.ff+i][a.ss]=d[a.ff][a.ss]+1;
                if(a.ff+i==e.ff&&a.ss==e.ss) return;
                Q.push(mp(a.ff+i,a.ss));
            }
        }
        loop(i,1,k+1){
            if(a.ff-i<0||mapp[a.ff-i][a.ss]=='#') break;
            if(d[a.ff-i][a.ss]!=-1) continue;
            else{
                d[a.ff-i][a.ss]=d[a.ff][a.ss]+1;
                if(a.ff-i==e.ff&&a.ss==e.ss) return;
                Q.push(mp(a.ff-i,a.ss));
            }
        }
    }
}
int main(){
	ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    loop(i,0,n){
        loop(j,0,m){
            cin>>mapp[i][j];
            d[i][j]=-1;
        }
    }
    PII s,e;
    cin>>s.ff>>s.ss>>e.ff>>e.ss;
    bfs(mp(s.ff-1,s.ss-1),mp(e.ff-1,e.ss-1));
    pln(d[e.ff-1][e.ss-1]);
}
