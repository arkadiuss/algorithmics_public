#include<bits/stdc++.h>
#define loop(i,j,n) for(int i=j;i<n;i++)
#define loopback(i,n,j) for(int i=n;i>=j;i--)
#define ps( v ) cout<<v<<" "
#define pln( v ) cout<<v<<"\n"
#define entr cout<<"\n"
#define pb(v) push_back(v)
#define ff first
#define ss second

using namespace std;

const int MAX=200100;

void coutTab(int* tab, int n){
	loop(i,0,n){
		ps(tab[i]);
	}
	entr;
}
//---------------------------
int n,m,z;
pair<int,int> infrng[MAX];
struct que{
	int t,j,i;
};
que mq(int t, int j, int i){
	que q;
	q.t=t;
	q.j=j;
	q.i=i;
	return q;
}
vector<que> ques;
struct event{
	int t, type, l;
};
event me(int t, int type, int l){
	event q;
	q.t=t;
	q.type=type;
	q.l=l;
	return q;
}
bool toSortEvents(event a, event b){
	if(a.t==b.t) return a.type<b.type;
	return a.t<b.t;
}
vector<event > events; 
void coutEvents(){
	cout<<"couting events";
	entr;
	loop(i,0,events.size()){
		ps(events[i].t);
		ps(events[i].type);
		pln(events[i].l);
	}
}
bool check(int k){
	events.erase(events.begin(),events.end());
	loop(i,0,n){
		infrng[i].ff=-1;
		infrng[i].ss=-1;
	}
	loop(t,0,k){
		if(infrng[ques[t].j].ff==-1){
			infrng[ques[t].j].ff=ques[t].t;
			infrng[ques[t].j].ss=ques[t].t;
		}else{
			infrng[ques[t].j].ff=min(ques[t].t,infrng[ques[t].j].ff);
			infrng[ques[t].j].ss=max(ques[t].t,infrng[ques[t].j].ss);
		}
		events.pb(me(ques[t].t,2,ques[t].i+1));
	}
	//if(z==49) pln("informatics");
	loop(i,0,n){
		//if(z==49){ ps(infrng[i].ff);
		//pln(infrng[i].ss);}
		if(infrng[i].ff!=-1){
			events.pb(me(infrng[i].ff,1,0));
			events.pb(me(infrng[i].ss,3,0));
		}
	}
	sort(events.begin(),events.end(),toSortEvents);
	//if(z==49) coutEvents();
	int lastl=-1,lastt=-1;
	loop(i,0,events.size()){
		if(events[i].type==2){
			if(lastt==events[i].t&&lastl!=events[i].l) return 0;
			lastt=events[i].t;
			lastl=events[i].l;
		}
	}
	int sleep=n,before=0,in=0,after=0,out=0;
	int used=0,last=0;
	//if(z==49) pln("checking");
	loop(i,0,events.size()){
		//if(z==49){
		//ps(events[i].t);
		//ps(events[i].type);
		//pln(events[i].l);
		//}
		if(events[i].type==1){
			if(before>0){ in++; before--;}
			else { 
				in++; 
				if(sleep==0) return 0;
				sleep--;
			}
		}else if(events[i].type==2){
			used=used+max(last-events[i].l,0);
			last=events[i].l;
			int sum=before+in+after;
			if(sum>events[i].l){
				int r=sum-events[i].l;
				out=out+r;
				if(after>=r){
					after=after-r;
				}else{ 
					r=r-after;
					after=0;
					if(before>=r)
						before=before-r;
					else
						return 0;	
				}
			}else if(sum<events[i].l){
				int r=events[i].l-sum;
				if(sleep<r) return 0;
				before=before+r;
				sleep=sleep-r;
			}
		}else if(events[i].type==3){
			after++;
			in--;
		}
		//if(z==49){
		//	ps(sleep);
		//	ps(before);
		//	ps(in);
		//	ps(after);
		//	pln(out);
		//}
	}
	used=used+last;
	if(used>n) return 0;
	return 1;
}
int binfind(){
	int s=1,e=m,mid;
	while(s<e){
		mid=(s+e+1)/2;
		if(check(mid)) s=mid;
		else e=mid-1;
		//if(z==49) entr;
	}
	return e;
}
int itfind(){
	loop(i,1,m+1){
		if(!check(i)) return i-1;
	}
	return m;
}
int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
int main(){
	ios_base::sync_with_stdio(0);
	int tc,j,i;
	z=readInt();
	while(z--){
		
		n=readInt();
		m=readInt();
		ques.erase(ques.begin(),ques.end());
		loop(q,0,m){
			tc=readInt();
			j=readInt();
			i=readInt();
			ques.pb(mq(tc-1,j-1,i));
			
		}
		pln(binfind());
	}
	
}

