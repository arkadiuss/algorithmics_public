#include<bits/stdc++.h>
#define VAR(i,n) __typeof(n) i = (n)
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define foreach(i,c) for(VAR(i,c.begin());i!=c.end();i++)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) c.size()
#define ps(v) cout<<v<<" "
#define pln(v) cout<<v<<"\n"
#define entr cout<<"\n"
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const int MAX=1000100;
const int MOD=1000000000;
const int INFTY=1000000000;
typedef vector<int> VI;
 
void coutTab(int * tab, int n){
        loop(i,0,n){
                ps(tab[i]);
        }
        entr;
}
//---------------------------------
template<class V, class E> struct Tree{
        struct Ed : E {
                int v;
                Ed(E e, int w) : E(e), v(w) {};
        };
        struct Ve : V, vector<Ed> { };
       
        vector<Ve> g;
        Tree(int n=0) : g(n) {};
        void EdgeU(int a,int b,E e=E()){
                g[a].pb(Ed(e,b));
                g[b].pb(Ed(e,a));
        }
};
struct V {};
struct E {
        ll w;
};
int n;
Tree<V,E> T;
void change(int a, int b, ll w){
        foreach(it,T.g[a]){
                if(it->v==b)
                        it->w=w;
        }
        foreach(it,T.g[b]){
                if(it->v==a)
                        it->w=w;
        }
}
ll ans(){
        ll res=0;
        loop(i,0,SIZE(T.g)){
                ll maxi=0,sum=0;
                foreach(it,T.g[i]){
                        maxi=max(maxi,it->w);
                        sum+=it->w;
                }
                if(maxi>sum-maxi)
                        res+=maxi-(sum-maxi);
                else if(sum%2==1)
                        res++; 
        }
        return res/2;
}
int main(){
        ios_base::sync_with_stdio(0);
        int q;
        cin>>n;
        T=Tree<V,E>(n);
        int a,b,w;
        loop(i,0,n-1){
                E e;
                cin>>a>>b>>e.w;
                T.EdgeU(a-1,b-1,e);
        }
        pln(ans());
        cin>>q;
        loop(i,0,q){
                cin>>a>>b>>w;
                change(a-1,b-1,w);
                pln(ans());
        }
}
