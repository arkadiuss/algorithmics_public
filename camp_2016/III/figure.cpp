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
point N[MAX];
point M[MAX];
int n,m;
long long coef[2][2];
ll minxN,maxxN,minxM,maxxM;
long long getCoef(point A,point B,point C){
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
	long long d1=getCoef(A,B,C);
	long long d2=getCoef(A,B,D);
	long long d3=getCoef(C,D,A);
	long long d4=getCoef(C,D,B);
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
bool check(){
	vector<point> vN,vM;
	if(minxN<minxM){
		if(maxxN<minxM)
			return false;
		loop(i,0,n){
			if(N[i].x>=minxM)
				vN.push_back(N[i]);
		}
		loop(i,0,m){
			if(M[i].x<=maxxN)
				vM.push_back(M[i]);
		}	
	}else{
		if(maxxM<minxN)
			return false;
		loop(i,0,n){
			if(N[i].x<=maxxM)
				vN.push_back(N[i]);
		}
		loop(i,0,m){
			if(M[i].x>=minxN)
				vM.push_back(M[i]);
		}	
	}

	loop(i,0,vN.size()-1){
		loop(j,0,vM.size()-1){
			if(intersect(vN[i],vN[i+1],vM[j],vM[j+1]))
				return true;
		}
		if(intersect(vN[i],vN[i+1],vM[vM.size()-1],vM[0]))
			return true;
	}
	loop(i,0,m+1){
		if(intersect(vN[vN.size()-1],vN[0],vM[i],vM[i+1]))
			return true;
	}
	if(intersect(vN[vN.size()-1],vN[0],vM[vM.size()-1],vM[0]))
		return true;
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
		minxN=min(N[i].x,minxN);
		maxxN=max(N[i].x,maxxN);
	}
	loop(i,0,m){
		cin>>x>>y;
		M[i].x=x;
		M[i].y=y;
		minxM=min(M[i].x,minxM);
		maxxM=max(M[i].x,maxxM);
	}
	
	if(check())
		cout<<"TAK";
	else
		cout<<"NIE";	
	
}
