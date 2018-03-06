#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define ss second
#define ff first
#define mp make_pair
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
struct pnt{
	int x,y;
};
struct segment{
	pnt a, b;
};
struct E{
	int v;
	double d;
};
pnt P,K;
int n;
vector<segment> sgmnts;
vector<pnt> pnts;
vector< vector<E> > G(MAX);
segment make_segment(pnt a, pnt b){
	segment s;
	s.a=a;
	s.b=b;
	return s;
}
ll coef[2][2];
ll getCoef(pnt A,pnt B,pnt C){
	coef[0][0]=B.x-A.x;
	coef[0][1]=B.y-A.y;
	coef[1][0]=C.x-A.x;
	coef[1][1]=C.y-A.y;
	return coef[0][0]*coef[1][1]-coef[0][1]*coef[1][0];
}
bool intersect(segment sa, segment sb){
	pnt A=sa.a;
	pnt B=sa.b;
	pnt C=sb.a;
	pnt D=sb.b;
	ll d1=getCoef(A,B,C);
	ll d2=getCoef(A,B,D);
	ll d3=getCoef(C,D,A);
	ll d4=getCoef(C,D,B);
	if(((d1>0&&d2<0)||(d1<0&&d2>0))&&((d3>0&&d4<0)||(d3<0&&d4>0)))
		return 1;
	return  0;			
}
bool intersectSegment(segment s){
	loop(i,0,sgmnts.size()){
		if(intersect(s,sgmnts[i]))
			return 1;
	}
	return 0;
}
double d(pnt A, pnt B){
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
void createGraph(){
	loop(i,0,pnts.size()){
		loop(j,0,pnts.size()){
			if(i!=j){
				if(!intersectSegment(make_segment(pnts[i],pnts[j]))){
					E e;
					e.v=j;
					e.d=d(pnts[i],pnts[j]);
					G[i].push_back(e);
				}
			}
		}
	}
}
void coutGraph(){
	loop(i,0,4*n+2){
		cout<<i<<": ";
		loop(j,0,G[i].size()){
			cout<<G[i][j].v<<"|"<<G[i][j].d<<" ";
		}
		entr;
	}
}
double min_cost[MAX];
double dijkstra(int a, int b){
	loop(i,0,4*n+2){
		min_cost[i]=INFTY;
	}
	min_cost[a]=0;
	set< pair<double,int> > S;
	S.insert(mp(0,a));
	while(!S.empty()){
		pair<double,int> v = (*S.begin());
		S.erase(S.begin());
		//ps(v.ss);
		loop(i,0,G[v.ss].size()){
			//cout<<min_cost[G[v.ss][i].v]<<"_"<<min_cost[v.ss]+G[v.ss][i].d<<" ";
			if(min_cost[G[v.ss][i].v]>min_cost[v.ss]+G[v.ss][i].d){
				S.erase(mp(min_cost[G[v.ss][i].v],G[v.ss][i].v));
				min_cost[G[v.ss][i].v]=min_cost[v.ss]+G[v.ss][i].d;
				S.insert(mp(min_cost[G[v.ss][i].v],G[v.ss][i].v));
			}
		}
	}
	return min_cost[b];
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	cin>>P.x>>P.y>>K.x>>K.y;
	pnt a,b,c,d;
	pnts.push_back(P);
	pnts.push_back(K);
	loop(i,0,n){
		cin>>a.x>>a.y>>c.x>>c.y;
		b.x=c.x;
		b.y=a.y;
		d.x=a.x;
		d.y=c.y;
		pnts.push_back(a);
		pnts.push_back(b);
		pnts.push_back(c);
		pnts.push_back(d);
		sgmnts.push_back(make_segment(a,b));
		sgmnts.push_back(make_segment(b,c));
		sgmnts.push_back(make_segment(c,d));
		sgmnts.push_back(make_segment(d,a));
		sgmnts.push_back(make_segment(a,c));
		sgmnts.push_back(make_segment(d,b));
	}
	createGraph();
	//coutGraph();
	cout<<fixed<<setprecision(8)<<dijkstra(0,1);
}
