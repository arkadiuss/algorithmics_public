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
const int MAX=500100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
struct point{
	ll x,y;
};
struct segment{
	point p1,p2;
	ll w;
};
point N[MAX];
point M[MAX];
segment segments[MAX];
ll minx=INFTY,maxx=0;
int n,m;
ll coef[2][2];
bool was[MAX];
vector<ll> xWas;
ll getCoef(point A,point B,point C){
	coef[0][0]=B.x-A.x;
	coef[0][1]=B.y-A.y;
	coef[1][0]=C.x-A.x;
	coef[1][1]=C.y-A.y;
	return coef[0][0]*coef[1][1]-coef[0][1]*coef[1][0];
}
bool onSegment(point A,point B,point C){
	if(min(A.x,B.x)<=C.x&&C.x<=max(A.x,B.x)&&min(A.y,B.y)<=C.y&&C.y<=max(A.y,B.y))
		return 1;
	return 0;	
}
bool intersect(point A,point B,point C,point D){
	ll d1=getCoef(A,B,C);
	ll d2=getCoef(A,B,D);
	ll d3=getCoef(C,D,A);
	ll d4=getCoef(C,D,B);
	if(((d1>0&&d2<0)||(d1<0&&d2>0))&&((d3>0&&d4<0)||(d3<0&&d4>0)))
		return 1;
	if(d1==0&&onSegment(A,B,C))
		return 1;
	if(d2==0&&onSegment(A,B,D))
		return 1;	
	if(d3==0&&onSegment(C,D,A))
		return 1;	
	if(d4==0&&onSegment(C,D,B))
		return 1;
	return  0;			
}
bool toSort(segment a,segment b){
	if(a.p1.x==b.p1.x) return a.p2.x<b.p2.x;
	if(a.p1.x==b.p1.x&&a.p2.x==b.p2.x) return a.p1.y<b.p1.y;
	return a.p1.x<b.p1.x;
}
void createSegments(){
	loop(i,0,n-1){
		segments[i].p1=N[i];
		segments[i].p2=N[i+1];
		segments[i].w=0;
	}
	segments[n-1].p1=N[n-1];
	segments[n-1].p2=N[0];
	segments[n-1].w=0;
	loop(i,0,m-1){
		segments[n+i].p1=M[i];
		segments[n+i].p2=M[i+1];
		segments[n+i].w=1;
	}
	segments[n+m-1].p1=M[m-1];
	segments[n+m-1].p2=M[0];
	segments[n+m-1].w=1;
	loop(i,0,n+m){
		if(segments[i].p1.x>segments[i].p2.x)
			swap(segments[i].p1,segments[i].p2);
	}
	sort(segments,segments+m+n,toSort);
	xWas.push_back(segments[0].p1.x);
	loop(i,1,n+m){
		if(segments[i].p1.x!=xWas.back())
			xWas.push_back(segments[i].p1.x);
	}
}
void coutSeg(){
	loop(i,0,n+m){
		cout<<"("<<segments[i].p1.x<<","<<segments[i].p1.y<<"):("<<segments[i].p2.x<<","<<segments[i].p2.y<<") ";
	}
	entr;
}
bool inside(){
	bool pass=1;
	ll d=getCoef(N[n-1],N[0],M[0]);
	loop(i,0,n-1){
		//cout<<getCoef(N[i],N[i+1],M[0])<<" "<<d<<"\n";
		if(getCoef(N[i],N[i+1],M[0])*d<=0){
			pass=0;
			break;
		}
	}
	if(pass) return true;
	pass=0;
	d=getCoef(M[m-1],M[0],N[0]);
	loop(i,0,m-1){
		//cout<<getCoef(N[i],N[i+1],M[0])<<" "<<d<<"\n";
		if(getCoef(M[i],M[i+1],N[0])*d<=0)
			return false;
	}
	return true;
}
bool check(){
	int p=0,k=0;
	ll j;
	loop(i,0,xWas.size()){
		j=xWas[i];
		k=p;
		cout<<p<<" "<<k<<" | ";
		while(p>=0&&j>=segments[p].p1.x&&j<=segments[p].p2.x){
			p--;
		}
		while(k<n+m&&segments[k].p1.x==xWas[i]){
			k++;
		}
		p++;
		cout<<p<<" "<<k<<"\n";
		loop(ni,p,k+1){
			loop(mi,p,k+1){
				if(ni!=mi){
					if(intersect(segments[ni].p1,segments[ni].p2,segments[mi].p2,segments[mi].p2)&&segments[mi].w!=segments[ni].w)
						return true;
				}
			}
		}
		
		while(p<n+m&&segments[p].p1.x<=xWas[i])
			p++;
	}
	return false;	
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	ll x,y;
	loop(i,0,n){
		cin>>x>>y;
		N[i].x=x;
		N[i].y=y;
		minx=min(minx,x);
		maxx=max(maxx,x);
	}
	loop(i,0,m){
		cin>>x>>y;
		M[i].x=x;
		M[i].y=y;
		minx=min(minx,x);
		maxx=max(maxx,x);
	}
	
	createSegments();
	coutSeg();
	loop(i,0,xWas.size()){
		cout<<xWas[i]<<" "; 
	}
	entr;
	bool checked;
	//cout<<inside()<<"\n";
	checked=check();
	if(inside()){
		cout<<"TAK";
	}else{	
		if(checked)
			cout<<"TAK";
		else if(!checked&&inside())
			cout<<"TAK";
		else
			cout<<"NIE";
	}
		
	
}
