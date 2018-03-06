/**
*Arkadiusz Kraus
*/
#include<bits/stdc++.h>
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,j,n) for(int i=j;i>=n;i--)
#define pln( v ) cout<<v<<"\n";
#define ps( v ) cout<<v<<" ";
#define entr cout<<"\n"
#define pb( v ) push_back(v)
using namespace std;

const int MAX=1000100;

void coutTab(int* tab,int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//------
int n;
int c[MAX],k;
int m,l;
int x[MAX],y[MAX];

int posInX[MAX];
int posInY[MAX];
int nextposs[MAX];
int actpos[MAX];
int thenearestlast[MAX];
int thenearestfirst[MAX];

int smallback[MAX];
int thefarest[MAX];
int maxfarest[MAX];
void movel(int i){
	//ps(i);
	if(actpos[x[i]]!=-1){
		int j=actpos[x[i]];
		while(j!=-1&&actpos[x[i]]<actpos[x[i-1]]){
			j=nextposs[j];
		}
		//ps(j);
		//cout<<i<<" "<<nextposs[i][j]<<"\n";
		if(j!=-1&&j>actpos[x[i-1]]){
			actpos[x[i]]=j;
			if(i<m-1)
				movel(i+1);
			else{
				if(j!=-1&&j!=n-1&&j!=0)
					thenearestlast[j]=actpos[x[0]];
			}
		}
	}
}
void mover(int i){
	//pln(i);
	if(actpos[y[i]]!=-1){
		int j=actpos[y[i]];
		while(j!=-1&&j>actpos[y[i-1]])
			j=nextposs[j];
		//ps(i);pln(j);	
		if(j!=-1&&j<actpos[y[i-1]]){
			actpos[y[i]]=j;
			//pln(j);
			if(i<l-1){
				mover(i+1);
			}else{
				if(j!=-1&&j!=n-1&&j!=0)
					thenearestfirst[j]=actpos[y[0]];
			}
		}
	}	
}
int main(){
	//ios_base::sync_with_stdio(0);
	cin>>n>>k;
	loop(i,0,n){	
		cin>>c[i];
	}
	cin>>m>>l;
	loop(i,0,n){
		posInX[i]=-1;
		posInY[i]=-1;
	}
	loop(i,0,m){
		cin>>x[i];
		posInX[x[i]]=i;
	}
	loop(i,0,l){
		cin>>y[i];
		posInY[y[i]]=i;
	}
	loop(i,0,n){
		thenearestlast[i]=-1;
		thenearestfirst[i]=-1;
	}
	//---------------------------------
	loop(i,0,k+1){
		smallback[i]=-1;
	}
	loopback(i,n-1,0){
		nextposs[i]=smallback[c[i]];
		smallback[c[i]]=i;
		actpos[c[i]]=i;
	}
	//cout<<"L"<<"\n";
	//coutTab(nextposs,n);
	
	while(actpos[x[0]]!=-1){
		//ps(actpos[x[0]]);
		if(actpos[x[0]]==0||actpos[x[0]]==n-1){
			actpos[x[0]]=nextposs[actpos[x[0]]];
			continue;
		}
		if(m>1)
			movel(1);
		else
			thenearestlast[actpos[x[0]]]=actpos[x[0]];
		actpos[x[0]]=nextposs[actpos[x[0]]];
		//pln(actpos[x[0]]);	
	}
	//cout<<"endL"<<"\n";
	int lastknow=-1;
	loop(i,1,n-1){
		if(thenearestlast[i]!=-1)
			lastknow=thenearestlast[i];
		else if(c[i]==x[m-1])
			thenearestlast[i]=lastknow;	
	}
	//loop(i,0,n){
	//	cout<<i<<":"<<thenearestlast[i]<<" ";
	//}
	//coutTab(thenearestlast,n);
	//-----------------------------------
	loop(i,0,k+1){
		nextposs[i]=-1;
		smallback[i]=-1;
	}
	loop(i,0,n){
		nextposs[i]=smallback[c[i]];
		smallback[c[i]]=i;
		actpos[c[i]]=i;
	}
	//cout<<"R"<<"\n";
	//coutTab(nextposs,n);
	while(actpos[y[0]]!=-1){
		//pln(actpos[y[0]]);
		if(actpos[y[0]]==0||actpos[y[0]]==n-1){
			 actpos[y[0]]=nextposs[actpos[y[0]]];
			 continue;
		}
		if(l>1)
			mover(1);
		else
			thenearestfirst[actpos[y[0]]]=actpos[y[0]];
		actpos[y[0]]=nextposs[actpos[y[0]]];
	}
	lastknow=-1;
	loopback(i,n-2,1){
		if(thenearestfirst[i]!=-1)
			lastknow=thenearestfirst[i];
		else if(c[i]==y[l-1])
			thenearestfirst[i]=lastknow;	
	}
	//coutTab(thenearestfirst,n);
	//------------------------------------
	loop(i,0,n){
		smallback[i]=-1;
	}
	loopback(i,n-1,0){
		if(smallback[c[i]]==-1){
			smallback[c[i]]=i;
		}
	}
	loop(i,0,n){
		thefarest[i]=smallback[c[i]];	
	}
	maxfarest[0]=thefarest[0];
	loop(i,1,n){
		maxfarest[i]=max(maxfarest[i-1],thefarest[i]);
	}
	//coutTab(maxfarest,n);
	//------------------------------------
	vector<int> ans;
	loop(i,0,n){
		if(thenearestfirst[i]!=-1&&thenearestlast[i]!=-1){
			if(maxfarest[thenearestlast[i]-1]>thenearestfirst[i]){
				ans.pb(i+1);
			}
		}
	}
	
	pln(ans.size());
	loop(i,0,ans.size()){
		ps(ans[i]);
	}
	
	
}
