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
const int MAX=1100;
const int MAXVAL=100100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
struct event{
	int t;
	int type;
	int i;
};
event me(int t, int type, int i){
	event e;
	e.t=t;
	e.type=type;
	e.i=i;
	return e;
}
bool toSortEvents(event a, event b){
	if(a.t==b.t) return a.type>b.type;
	return a.t<b.t;
}
struct que{
	int m,k,s;
	bool ans;
};
que mq(int m, int k, int s,bool ans){
	que q;
	q.m=m;
	q.k=k;
	q.s=s;
	q.ans=ans;
	return q;
} 
struct thing{
	int a,b,c;
};
thing mt(int a,int b,int c){
	thing t;
	t.a=a;
	t.b=b;
	t.c=c;
	return t;
}
vector<event> evs;
que qs[1000100];
thing ths[MAX];
int n;
int nearest[MAXVAL];
int maxval=0;
void add(int c, int b){
	loopback(i,maxval,0){
		if(i+c<MAXVAL&&nearest[i]!=-1){
			nearest[i+c]=max(nearest[i+c],min(nearest[i],b));
			maxval=max(maxval,i+c);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	int c,a,b;
	loop(i,0,n){
		cin>>c>>a>>b;
		ths[i]=mt(a,b,c);
		evs.pb(me(a,2,i));
	}
	int p,m,k,s;
	cin>>p;
	loop(i,0,p){
		cin>>m>>k>>s;
		qs[i]=mq(m,k,s,0);
		evs.pb(me(m,1,i));
	}
	sort(ALL(evs),toSortEvents);
	loop(i,0,MAXVAL){
		nearest[i]=-1;
	}
	nearest[0]=INFTY;
	foreach(it,evs){
		//pln(it->t);
		if(it->type==1){
			if(nearest[qs[it->i].k]>qs[it->i].m+qs[it->i].s) 
				qs[it->i].ans=1;
		}else{
			//pln("adding");
			add(ths[it->i].c,ths[it->i].b);
		}
		//coutTab(nearest,maxval);
	}
	loop(i,0,p){
		if(qs[i].ans) pln("TAK");
		else pln("NIE");
	}
}
