#include<bits/stdc++.h>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j;i>=s;i--)
#define pln( x ) cout << x << "\n"
#define ps( x ) cout << x << " "
#define entr cout << "\n" 
#define pcnt(i) __builtin_popcount(i)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
using namespace std;
const int INFTY=20000000;
const int MAX=500100;
const int MOD=10000000;
//------------------------------------------
struct obstcl{
    int x;
    int a,b;
};
int n,X;
int maxY, minY;
obstcl obstcls[MAX]; //obstacles
int lenght(int x1,int x2,int y1, int y2){
	if((abs(x2-x1)%2==0&&abs(y2-y1)%2==1)||(abs(x2-x1)%2==1&&abs(y2-y1)%2==0)) return -1;
	int b1=y1-x1;
	int b2=x2+y2;
	int x=(b2-b1)/2;
	return x+b1-y1;
}
int maxavpoint(int x,int y,int xres, int mode){
	int b;
	if(mode==1){
		b=y-x;
		return xres+b;
	}else{	
		b=y+x;
		return -xres+b;
	}
}
void coutObstcls(){
	loop(i,0,n){
		cout<<obstcls[i].x<<": "<<obstcls[i].a<<" "<<obstcls[i].b<<"\n";
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>X;
	loop(i,0,n){
        cin>>obstcls[i].x>>obstcls[i].a>>obstcls[i].b;
        maxY=max(obstcls[i].b,maxY);
	}
	obstcls[0].a=max(obstcls[0].a,maxavpoint(0,0,obstcls[0].x,2)-1);
	obstcls[0].b=min(obstcls[0].b,maxavpoint(0,0,obstcls[0].x,1)+1);
	loop(i,1,n){
		obstcls[i].a=max(obstcls[i].a,maxavpoint(obstcls[i-1].x,obstcls[i-1].a,obstcls[i].x,2));
		obstcls[i].b=min(obstcls[i].b,maxavpoint(obstcls[i-1].x,obstcls[i-1].b,obstcls[i].x,1));
	}
	//coutObstcls();
	loopback(i,n-2,0){
		obstcls[i].a=max(obstcls[i].a,maxavpoint(obstcls[i+1].x,obstcls[i+1].a,obstcls[i].x,1));
		obstcls[i].b=min(obstcls[i].b,maxavpoint(obstcls[i+1].x,obstcls[i+1].b,obstcls[i].x,2));
	}
	//coutObstcls();
	int len=0,l,y;
	l=-1;
	if(obstcls[0].a+1<obstcls[0].b)
		l=lenght(0,obstcls[0].x,0,obstcls[0].a+1);
	if(l==-1&&obstcls[0].b>obstcls[0].a+2){
		l=lenght(0,obstcls[0].x,0,obstcls[0].a+2);
		y=obstcls[0].a+2;
	}else
		y=obstcls[0].a+1;
	if(l==-1)
		len=-1;
	else
	len=l;	
	//ps(len);
	//pln(y);
	loop(i,1,n){
		if(len==-1) break;
		l=-1;
		if(obstcls[i].a+1<obstcls[i].b)
			l=lenght(obstcls[i-1].x,obstcls[i].x,y,obstcls[i].a+1);
		if(l==-1&&obstcls[i].b>obstcls[i].a+2){
			//ps("fi");
			l=lenght(obstcls[i-1].x,obstcls[i].x,y,obstcls[i].a+2);
			y=obstcls[i].a+2;
		}else
			y=obstcls[i].a+1;
		if(l==-1)
			len=-1;
		else
			len=len+l;
		//ps(len);
		//pln(y);		
	}
	if(n==0)
		cout<<0;
	else if(len==-1)
		cout<<"NIE";	
	else
		cout<<len;	
}
