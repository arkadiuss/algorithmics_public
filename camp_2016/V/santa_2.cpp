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
int a[MAX],color[MAX];
int n,k;
vector<int> cyclesS;
int act_col=1;
bool was[MAX];
void colour(int v){
	color[v]=act_col;
	int size=1;
	while(color[a[v]]==0){
		//cout<<v<<"\n";
		v=a[v];
		color[v]=act_col;
		size++;
	}
	act_col++;
	cyclesS.push_back(size);
}
int main(){
	ios_base::sync_with_stdio(0);
	int mini,maxi;
	cin>>n>>k;
	loop(i,0,n){
		cin>>a[i];
		a[i]=a[i]-1;
	}
	//coutTab(a,n);
	loop(i,0,n){
		color[i]=0;
	}
	loop(i,0,n){
		if(color[i]==0)
			colour(i);
	}
	//coutTab(color,n);
	loop(i,0,n){
		was[i]=0;
	}
	sort(cyclesS.begin(),cyclesS.end());
	vector<int> toCount,toCount2;
	loop(i,0,cyclesS.size()){	
		if(i>0&&cyclesS[i]==cyclesS[i-1]){
			loop(j,0,toCount.size()){
				if(!was[toCount[j]+cyclesS[i]])
					toCount2.push_back(toCount[j]+cyclesS[i]);
				was[toCount[j]+cyclesS[i]]=1;
				
			}
			toCount.erase(toCount.begin(),toCount.end());
			loop(i,0,toCount2.size()){
				toCount.push_back(toCount2[i]);
			}
			toCount2.erase(toCount2.begin(),toCount2.end());
		}else{
			toCount.erase(toCount.begin(),toCount.end());
			loopback(j,n-1,0){
				if(was[j]){
					if(!was[j+cyclesS[i]])
						toCount.push_back(j+cyclesS[i]);		
					was[j+cyclesS[i]]=1;
				}
			}
			toCount.push_back(cyclesS[i]);
			was[cyclesS[i]]=1;
		}
		
		//loop(i,0,n+1){
		//	if(was[i]) cout<<i<<" ";
		//}entr;
	}
	
	
	if(was[k])
		mini=k;
	else
		mini=k+1;
	int khelp=k;
	maxi=0;	
	//loop(i,0,cyclesS.size()){
	//	ps(cyclesS[i]);
	//}
	loop(i,0,cyclesS.size()){
		if(cyclesS[i]%2==0){
			if(khelp==0){
				break;
			}else if(khelp>=cyclesS[i]/2){
				khelp=khelp-cyclesS[i]/2;
				maxi=maxi+cyclesS[i];
			}else{
				maxi=maxi+2*khelp;
				khelp=0;
			}
		}else if(cyclesS[i]%2==1){
			if(khelp==0){
				break;
			}else if(khelp>=cyclesS[i]/2){
				khelp=khelp-cyclesS[i]/2;
				maxi=maxi+cyclesS[i]-1;
			}else{
				maxi=maxi+2*khelp;
				khelp=0;
			}

		}
		
	}
	//pln(maxi);
	//pln(khelp);
	maxi=maxi+khelp;
	if(maxi>n)
		maxi=n;
	cout<<mini<<" "<<maxi<<"\n";		
}
