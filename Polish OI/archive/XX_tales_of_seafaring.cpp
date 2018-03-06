#include<bits/stdc++.h>
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr putchar('\n')
#define pb(v) push_back(v)
#define ll long long
using namespace std;
const int MAX=5100;

void coutTab(int* tab, int n){
    loop(i,0,n){
        ps(tab[i]);
    }
    entr;
}
//------------------------------
short way[MAX][2];
struct q{
    int num;
    short a,b;
    int d;
    bool ans;
};
q mq(int num, short a,short b,int d, bool ans){
    q qt;
    qt.num=num;
    qt.a=a;
    qt.b=b;
    qt.d=d;
    qt.ans=ans;
    return qt;
}
vector<q> qs;
vector< vector<short> > G (MAX);
int n;
bool toSort1(q q1,q q2){
    return q1.a<q2.a;
}
bool toSort2(q q1,q q2){
    return q1.num<q2.num;
}
void clearTab(){
    loop(i,0,n){
        way[i][0]=-1;
        way[i][1]=-1;
    }
}
void bfs(short a){
    clearTab();
    queue<short> Q;
    Q.push(a);
    way[a][0]=0;
    while(!Q.empty()){
        int v=Q.front();
        loop(i,0,G[v].size()){
            if(way[v][0]!=-1){
                if(way[G[v][i]][1]==-1){
                    way[G[v][i]][1]=way[v][0]+1;
                    Q.push(G[v][i]);
                }
            }
            if(way[v][1]!=-1){
                if(way[G[v][i]][0]==-1){
                    way[G[v][i]][0]=way[v][1]+1;
                    Q.push(G[v][i]);
                }
            }
        }
        Q.pop();
    }
}
void coutWay(){
    pln("parzyste");
    loop(i,0,n){
        ps(way[i][0]);

    }
    entr;
    pln("nieparzyste");
    loop(i,0,n){
        ps(way[i][1]);

    }
    entr;
}
int main(){
    int a,b,m,k;
    ios_base::sync_with_stdio(0);
    cin>>n>>m>>k;
    loop(i,0,m){
        cin>>a>>b;
        G[a-1].pb(b-1);
        G[b-1].pb(a-1);
    }

    //coutWay();
    ll d;
    loop(i,0,k){
        cin>>a>>b>>d;
        qs.pb(mq(i,a,b,d,0));
    }
//pln("NIE WYKONUJE");
    sort(qs.begin(),qs.end(),toSort1);
    //pln("NIE WYKONUJE");
    loop(i,0,qs.size()){
        a=qs[i].a-1;
        bfs(a);
        //ps("a ");
        //pln(a);
        //coutWay();
        while(i<qs.size()&&qs[i].a-1==a){
            if(G[qs[i].a-1].size()==0||G[qs[i].b-1].size()==0)
                qs[i].ans=0;
            else if(way[qs[i].b-1][qs[i].d%2]!=-1&&way[qs[i].b-1][qs[i].d%2]<=qs[i].d){
                qs[i].ans=1;
            }else{
                qs[i].ans=0;
            }
            i++;
        }
        i--;
    }
    sort(qs.begin(),qs.end(),toSort2);
    loop(i,0,qs.size()){
        if(qs[i].ans) pln("TAK");
        else pln("NIE");
    }
}
