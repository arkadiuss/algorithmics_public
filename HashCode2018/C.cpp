#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
#include<ctime>
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
	vector<ride> getted;
};
int R,C,F,N,B,T;
ride rides[MAX];
ll dist(int a, int b,int c ,int d){
	return abs(d-b)+abs(c-a);
}
bool sortByS(ride a, ride b){
	return dist(a.a,a.b,a.x,a.y)>dist(b.a,b.b,b.x,b.y);
}
void coutRides(){
	loop(i,0,N){
		cout<<rides[i].a<<" "<<rides[i].b<<" "<<rides[i].x<<" "<<rides[i].y<<" "<<rides[i].s<<" "<<rides[i].f<<"\n";
	}
}

bool was[MAX];
int countEndTime(vector<ride> & rides){
	int endtime=0;
	int x=0,y=0;
	loop(i,0,rides.size()){
		int d=dist(x,y,rides[i].a,rides[i].b);
		int dR=dist(rides[i].a,rides[i].b,rides[i].x,rides[i].y);
		endtime=max(endtime+d,rides[i].s)+dR;
		if(endtime>rides[i].f) return INFTY;
		x=rides[i].x;
		y=rides[i].y;
	}
	return endtime;
}
int bestPos(vector<ride> rides, ride a){
	if(rides.empty()) return 0;
	else{
		rides.pb(a);
		int bi=rides.size()-1;
		int be=countEndTime(rides);
		loopback(i,rides.size()-2,0){
			swap(rides[i],rides[i+1]);
			int en=countEndTime(rides);
			if(be>en){
				be=en;
				bi=i;
			}
		}
		if(be==INFTY) return -1;
		return bi;
	}
}
void swapLastToPos(vector<ride> & rides,int i){
	if(rides.size()==1&&i==0) return;
	int j=rides.size()-2;
	while(j>=i){
		swap(rides[j],rides[j+1]);
		j--;
	}
	//swap(rides[j],rides[j+1]);	
}
int main(){
	//ios_base::sync_with_stdio(0);
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
	int S=0;
	int z=10;//pln("START");
	loop(j,0,N){
		int bcar=-1;
		int bend=INFTY;
		int bpos=-1;
		int dR=dist(rides[j].x,rides[j].y,rides[j].a,rides[j].b);
		//ps("j");pln(j);
		cerr<<j<<"\n";
		loop(i,0,F/2){
			if(!was[j]){
				//int d=dist(cars[i].x,cars[i].y,rides[j].a,rides[j].b);
				int bi=bestPos(cars[i].getted,rides[j]);
				//if(i==1) pln(bi);
				if(bi!=-1){
					vector<ride> rs;
					rs=cars[i].getted;
					rs.pb(rides[j]);
					int e=countEndTime(rs);
					
					if(e<bend){
						bend=e;
						bcar=i;
						bpos=bi;
					}
				}
			}
		}
		//ps("I have best");pln(bcar);
		if(bcar!=-1){
			cars[bcar].getted.pb(rides[j]);
			swapLastToPos(cars[bcar].getted,bpos);
			cars[bcar].endtime=countEndTime(cars[bcar].getted);
			S+=dR;
			was[j]=1;
		}
	}
	loop(j,0,N){
		int bcar=-1;
		int bend=INFTY;
		int bpos=-1;
		int dR=dist(rides[j].x,rides[j].y,rides[j].a,rides[j].b);
		//ps("j");pln(j);
		cerr<<j<<"\n";
		loop(i,F/2,F){
			if(!was[j]){
				//int d=dist(cars[i].x,cars[i].y,rides[j].a,rides[j].b);
				int bi=bestPos(cars[i].getted,rides[j]);
				//if(i==1) pln(bi);
				if(bi!=-1){
					vector<ride> rs;
					rs=cars[i].getted;
					rs.pb(rides[j]);
					int e=countEndTime(rs);
					
					if(e<bend){
						bend=e;
						bcar=i;
						bpos=bi;
					}
				}
			}
		}
		//ps("I have best");pln(bcar);
		if(bcar!=-1){
			cars[bcar].getted.pb(rides[j]);
			swapLastToPos(cars[bcar].getted,bpos);
			cars[bcar].endtime=countEndTime(cars[bcar].getted);
			S+=dR;
			was[j]=1;
		}
	}
	ll notget;
	loop(i,0,N){
		if(!was[i]) notget++;
	}
	loop(i,0,F){
		ps(cars[i].getted.size());
		loop(j,0,cars[i].getted.size()){
			cout<<cars[i].getted[j].ind<<" ";
			//cout<<rides[cars[i].getted[j]].end<<":"<<rides[cars[i].getted[j]].x<<":"<<rides[cars[i].getted[j]].y<<":"<<rides[cars[i].getted[j+1]].a<<":"<<rides[cars[i].getted[j+1]].b<<":"<<dist(rides[cars[i].getted[j]].x,rides[cars[i].getted[j]].y,rides[cars[i].getted[j+1]].a,rides[cars[i].getted[j+1]].b)<<":"<<rides[cars[i].getted[j+1]].s<<"\n";
		}
		entr;
	}
	pln(S);
	//pln(notget);
}
