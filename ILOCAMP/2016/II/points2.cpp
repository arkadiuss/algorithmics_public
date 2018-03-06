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
int n,m;
struct point{
	int x,y;
};
point points[9];
vector<int> perm(8);
vector<int> bestperm(8);
void coutPerm(){
	loop(i,0,8){
		ps(bestperm[i]);
	}
	entr;	
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	if(n==0){
		cout<<"0 1"<<"\n";
		cout<<"0 "<<m<<"\n";
		cout<<"0 0"<<"\n";
		cout<<"0 "<<m-1<<"\n";
	}else if(m==0){
		cout<<"1 0"<<"\n";
		cout<<n<<" 0"<<"\n";
		cout<<"0 0"<<"\n";
		cout<<n-1<<" 0"<<"\n";
	}else if(n==1){
		cout<<"0 0"<<"\n";
		cout<<"1 "<<m<<"\n";
		cout<<"1 0"<<"\n";
		cout<<"0 "<<m<<"\n";
	}else if(m==1){
		cout<<"0 0"<<"\n";
		cout<<n<<" 1"<<"\n";
		cout<<"0 1"<<"\n";
		cout<<n<<" 0"<<"\n";
	}else{
		perm[0]=0;
		perm[1]=1;
		perm[2]=2;
		perm[3]=3;
		perm[4]=4;
		perm[5]=5;
		perm[6]=6;
		perm[7]=7;
		points[0].x=0;
		points[0].y=0;
		points[1].x=0;
		points[1].y=1;
		points[2].x=1;
		points[2].y=0;
		points[3].x=n;
		points[3].y=m;
		points[4].x=n-1;
		points[4].y=m;
		points[5].x=n;
		points[5].y=m-1;
		points[6].x=0;
		points[6].y=m;
		points[7].x=n;
		points[7].y=0;
		double maxd=0;
		loop(i,0,8*7*6*5*4*3*2){
			//coutPerm();
			double len=sqrt((points[perm[0]].x-points[perm[1]].x)*(points[perm[0]].x-points[perm[1]].x)+(points[perm[0]].y-points[perm[1]].y)*(points[perm[0]].y-points[perm[1]].y))+sqrt((points[perm[1]].x-points[perm[2]].x)*(points[perm[1]].x-points[perm[2]].x)+(points[perm[1]].y-points[perm[2]].y)*(points[perm[1]].y-points[perm[2]].y))+sqrt((points[perm[2]].x-points[perm[3]].x)*(points[perm[2]].x-points[perm[3]].x)+(points[perm[2]].y-points[perm[3]].y)*(points[perm[2]].y-points[perm[3]].y));
			
			if(len>maxd){
				maxd=len;
				bestperm=perm;
			}
			next_permutation(perm.begin(),perm.end());
		}
		//pln(maxd);
		ps(points[bestperm[0]].x);
		pln(points[bestperm[0]].y);
		ps(points[bestperm[1]].x);
		pln(points[bestperm[1]].y);
		ps(points[bestperm[2]].x);
		pln(points[bestperm[2]].y);
		ps(points[bestperm[3]].x);
		pln(points[bestperm[3]].y);
	}
}
