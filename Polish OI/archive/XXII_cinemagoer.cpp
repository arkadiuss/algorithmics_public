#include<iostream>
#define loop(i,j,s) for(int i=j;i<s;i++)
#define loopback(i,j,s) for(int i=j-1;i>=s;i--)
#define used(i) use[films[i]-1]
#define coef(i) coefficient[films[i]-1]
using namespace std;
const int MAX=1050000;
const int INFTY=200000000;
int n;
int leafs;
int coefficient[MAX];
int films[MAX]; 
int use[MAX]={0};
long long sum[MAX]={0};
long long M[2*MAX]={0};
long long P[2*MAX]={0};
int nxt[MAX]={0};
int act_nex[MAX]={0};
int countSize(int n){
	int size=1,b=2;
	while(size<n){
		size=size*b;
	}
	return size;
}
long long maxi=0;
void countLeafs(){
	sum[0]=coef(0);
	used(0)=1;
	M[leafs]=sum[0];
	maxi=sum[0];
	loop(i,1,n){
		if(used(i)==0){
			used(i)=1;
			sum[i]=sum[i-1]+coef(i);
		}else if(used(i)==1){
			sum[i]=sum[i-1]-coef(i);
			used(i)++;
		}else{
			used(i)++;
			sum[i]=sum[i-1];
		}
		M[i+leafs]=sum[i];
		maxi=max(sum[i],maxi);		
	}
}
void countnxt(){
	loop(i,0,n){
		act_nex[i]=INFTY;
	}
	loopback(i,n,0){
		nxt[i]=act_nex[films[i]-1];
		act_nex[films[i]-1]=i;
	}
}
int countMax(int i){
	if(i>=leafs)
		return M[i];
	M[i]=max(countMax(2*i),countMax(2*i+1));
	return M[i];		
}
void updateMax(int i){
	i=i/2;
	while(i>0){
		M[i]=max(M[2*i]+P[2*i],M[2*i+1]+P[2*i+1]);
		i=i/2;
	}
}
void add(int L,int R,int a){
	//cout<<L<<" "<<R<<" "<<a<<endl;
	L=L+leafs;
	R=R+leafs;
	while(L<=R){
		if(L%2==1) {
			P[L]=P[L]+a;
			updateMax(L);
		}
		if(R%2==0){
			P[R]=P[R]+a;
			updateMax(R);
		}
		L=(L+1)/2;
		R=(R-1)/2;
	}
}
int main(){
	int m;
	cin>>n>>m;
	//ios_base::sync_with_stdio(0);
	loop(i,0,n)
		cin>>films[i];
	
	loop(i,0,m)
		cin>>coefficient[i];
	leafs=countSize(n);
	countLeafs();
	/*loop(i,0,n){
		cout<<sum[i]<<" ";
	}
	cout<<"\n";*/
	countnxt();
	/*loop(i,0,n){
		cout<<nxt[i]<<" ";
	}
	cout<<"\n";
	*/
	countMax(1);
	/*loop(i,1,2*leafs){
		cout<<M[i]<<" ";
	}
	cout<<"\n";
	loop(i,1,2*leafs){
		cout<<P[i]<<" ";
	}
	cout<<"\n";	
	cout<<endl;*/
	loop(i,1,n){
		if(used(i-1)==1){
			add(i,n-1,-coef(i-1));
			maxi=max(maxi,M[1]);
			used(i-1)--;
		}else if(used(i-1)==2){
			add(i,nxt[i-1]-1,-coef(i-1));
			add(nxt[i-1],n-1,coef(i-1));
			maxi=max(maxi,M[1]);
			used(i-1)--;
		}else{
			add(i,nxt[i-1]-1,-coef(i-1));
			add(nxt[i-1],nxt[nxt[i-1]]-1,coef(i-1));
			maxi=max(maxi,M[1]+P[1]);
			used(i-1)--;
		}
		/*loop(i,1,2*leafs){
			cout<<M[i]<<" ";
		}
		cout<<"\n";	
		loop(i,1,2*leafs){
			cout<<P[i]<<" ";
		}
		cout<<"\n";
		cout<<"\n";	*/
	}
	cout<<maxi;	
}
