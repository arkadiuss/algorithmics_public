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
	int x,y;
};
int n,m;
point A,B,C,D;
point mA,mB,mC,mD;
void addOne(point* p){
	if(p->x==m){
		p->x=0;
		p->y++;
	}else
		p->x++;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	A.x=0;
	A.y=0;
	B.x=0;
	B.y=0;
	C.x=0;
	C.y=0;
	D.x=0;
	D.y=0;
	double maxd=0;
	loop(a,0,(n+1)*(m+1)){
		B.x=0;
		B.y=0;
		loop(b,0,(n+1)*(m+1)){
			C.x=0;
			C.y=0;
			if((B.x==A.x&&B.y==A.y)){
				addOne(&B);
				continue;
			}
			loop(c,0,(n+1)*(m+1)){
				D.x=0;
				D.
				y=0;
				if((C.x==A.x&&C.y==A.y)||(C.x==B.x&&C.y==B.y)){
					addOne(&C);
					continue;		
				}
				loop(d,0,(n+1)*(m+1)){
					double len=sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y))+sqrt((C.x-B.x)*(C.x-B.x)+(C.y-B.y)*(C.y-B.y))+sqrt((C.x-D.x)*(C.x-D.x)+(C.y-D.y)*(C.y-D.y));
					if((D.x==A.x&&D.y==A.y)||(D.x==B.x&&D.y==B.y)||(D.x==C.x&&D.y==C.y)){
						addOne(&D);
						continue;
					}
					if(len>maxd){
						mA=A;
						mB=B;
						mC=C;
						mD=D;
						maxd=len;
					}
					addOne(&D);
				}
				addOne(&C);
			}
			addOne(&B);
		}
		addOne(&A);
	}
	A.y=1;
	A.x=0;
	B.y=m;
	B.x=n;
	C.y=0;
	C.x=0;
	D.y=m-1;
	D.x=n;
	double len=sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y))+sqrt((C.x-B.x)*(C.x-B.x)+(C.y-B.y)*(C.y-B.y))+sqrt((C.x-D.x)*(C.x-D.x)+(C.y-D.y)*(C.y-D.y));
	if(n==1||m==1){
	cout<<mA.y<<" "<<mA.x<<"\n";
	cout<<mB.y<<" "<<mB.x<<"\n";			
	cout<<mC.y<<" "<<mC.x<<"\n";
	cout<<mD.y<<" "<<mD.x<<"\n";
	}else
	cout<<maxd<<"\n";
	
}
