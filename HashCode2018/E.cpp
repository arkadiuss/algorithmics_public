#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
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
const int MAX=10100;
const int MOD=10000000;

void coutTab(int* tab,int n){
	loop(i,0,n){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
}
//------------------------------------------
struct ride {
	int a,b;
	int x,y;
	int s,f;
	int ind;
	int end;
};
struct car{
	int x,y;
	int endtime;
	vector<int> getted;
};
int R,C,F,N,B,T;
ride rides[MAX];
bool sortByS(ride a, ride b){
	return a.s<b.s;
}
void coutRides(){
	loop(i,0,N){
		cout<<rides[i].a<<" "<<rides[i].b<<" "<<rides[i].x<<" "<<rides[i].y<<" "<<rides[i].s<<" "<<rides[i].f<<"\n";
	}
}
ll dist(int a, int b,int c ,int d){
	return abs(d-b)+abs(c-a);
}
bool was[MAX];
int main(){
	ios_base::sync_with_stdio(0);
	cin>>R>>C>>F>>N>>B>>T;
	loop(i,0,N){
		cin>>rides[i].a>>rides[i].b>>rides[i].x>>rides[i].y>>rides[i].s>>rides[i].f;
		rides[i].ind=i;
	}
	sort(rides,rides+N,sortByS);
	//coutRides();
	int avoidTresh=3000;
	ll sum=0;
	car cars[1000];
	loop(i,0,F){
		cars[i].x=0;
		cars[i].y=0;
		cars[i].endtime=0;
	}
	int j=0;
	int notget=0;
	loop(t,0,T){
		//pln(t);
		while(j<N&&rides[j].s<=t){
			int iBS=-1;
			loop(i,0,F){
				if(avoidTresh<dist(cars[i].x,cars[i].y,rides[j].a,rides[j].b)) continue;
				int d=dist(cars[i].x,cars[i].y,rides[j].a,rides[j].b);
				int dR=dist(rides[j].x,rides[j].y,rides[j].a,rides[j].b);
				if(cars[i].endtime+d<rides[j].s&&cars[i].endtime+d+dR<=T){
					if(iBS==-1){ iBS=i;}
					else{
						if(d>dist(cars[iBS].x,cars[iBS].y,rides[j].a,rides[j].b)){
							iBS=i;
						}
					}
				}
			}
			if(iBS!=-1){
				if(max(cars[iBS].endtime+dist(cars[iBS].x,cars[iBS].y,rides[j].a,rides[j].b),rides[j].s+
					dist(rides[j].a,rides[j].b,rides[j].x,rides[j].y))<rides[j].f)
					sum+=dist(rides[j].a,rides[j].b,rides[j].x,rides[j].y)+B;
				cars[iBS].endtime=rides[j].s+dist(rides[j].a,rides[j].b,rides[j].x,rides[j].y);
				rides[j].end=rides[j].s+dist(rides[j].a,rides[j].b,rides[j].x,rides[j].y);
				cars[iBS].x=rides[j].x;
				cars[iBS].x=rides[j].y;
				
				cars[iBS].getted.pb(j);
				was[j]=1;
			}else{
				notget++;
			}
			j++;
		}
	}
	loop(j,0,N){
		if(!was[j]){
			int iBS=-1;
			loop(i,0,F){
				int d=dist(cars[i].x,cars[i].y,rides[j].a,rides[j].b);
				if(max(cars[i].endtime+d,rides[j].s)+dist(rides[j].a,rides[j].b,rides[j].x,rides[j].y)<=rides[j].f){
					if(iBS==-1){ iBS=i;}
				
					else{
						if(cars[i].endtime>cars[iBS].endtime){
							iBS=i;
						}
					}
				}
			}
			if(iBS!=-1){
				cars[iBS].endtime=rides[j].s+dist(rides[j].a,rides[j].b,rides[j].x,rides[j].y);
				cars[iBS].x=rides[j].x;
				cars[iBS].x=rides[j].y;
				sum+=dist(rides[j].a,rides[j].b,rides[j].x,rides[j].y);
				cars[iBS].getted.pb(j);
				was[j]=1;
				notget--;
			}
		}
	}
	loop(i,0,F){
		ps(cars[i].getted.size());
		loop(j,0,cars[i].getted.size()){
			cout<<rides[cars[i].getted[j]].ind<<" ";
			//cout<<rides[cars[i].getted[j]].end<<":"<<rides[cars[i].getted[j]].x<<":"<<rides[cars[i].getted[j]].y<<":"<<rides[cars[i].getted[j+1]].a<<":"<<rides[cars[i].getted[j+1]].b<<":"<<dist(rides[cars[i].getted[j]].x,rides[cars[i].getted[j]].y,rides[cars[i].getted[j+1]].a,rides[cars[i].getted[j+1]].b)<<":"<<rides[cars[i].getted[j+1]].s<<"\n";
		}
		entr;
	}
	//pln(sum);
	//pln(notget);
}
