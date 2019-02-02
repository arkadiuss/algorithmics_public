class Point:
	def __init__(self,x,y):
		self.x = x
		self.y = y
		
	def __repr__(self):
		return "(%s:%s)" % (self.x, self.y)

def cos(p1,p2):
	return (p1.x-p2.x)/((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y))
	
def vecProd(p1,p2,p3):
	return (p2.x-p1.x)*(p3.y-p1.y) - (p2.y-p1.y)*(p3.x-p1.x)

def convexHull(A):
	p = 0
	for i in range(1,len(A)):
		if(A[i].y<A[p].y or (A[i].y==A[p].y and A[i].x<A[p].x)):
			p=i
	A[0],A[p] = A[p],A[0]
	for i in range(0,len(A)):
		A[i].x -= A[0].x
		A[i].y -= A[0].y
	A[0].ang = 4
	for i in range(1,len(A)):
		A[i].ang = cos(A[i],A[0]);
	A.sort(reverse = 1,key=lambda a: a.ang)
	s = [A[0],A[1]]
	for i in range(2,len(A)):
		l = len(s)-1
		pl = len(s)-2
		while(pl>=0 and vecProd(s[pl],s[l],A[i])<=0):
			s.pop()
			l = l-1
			pl = pl-1
		s.append(A[i])
	return s	

P = 31
MOD = 1000000009		
def check(A,B):
	if(len(A)!=len(B)):	
		return 0
	else:
		s = len(A)
		pA = []
		pB = []
		for i in range(1,s-1):
			pA.append(vecProd(A[i],A[i-1],A[i+1]))
			pB.append(vecProd(B[i],B[i-1],B[i+1]))
		pA.append(vecProd(A[s-1],A[s-2],A[0]))
		pA.append(vecProd(A[0],A[s-1],A[1]))
		pB.append(vecProd(B[s-1],B[s-2],B[0]))
		pB.append(vecProd(B[0],B[s-1],B[1]))
		#print(pA,pB)		
		h1 = 0
		h2 = 0
		PP = 1
		for i in range(0,s):
			h1 = ((h1*P)%MOD + pA[0])%MOD
			h2 = ((h2*P)%MOD + pB[0])%MOD
			PP = (PP*P)%MOD
			
		for i in range(0,s):
			if(h1==h2):
				return 1
			else:
				h1 = h1 - (PP*pA[0])%MOD
				while(h1<0):
					h1+=MOD
				h1 = ((h1*P)%MOD + pA[i])%MOD
		if(h1==h2):
			return 1
		return 0
						 		
A = []
B = []
n, m = map(int,input().split())
for i in range(0,n):
	x,y = map(int,input().split())
	A.append(Point(x,y))
for i in range(0,m):
	x,y = map(int,input().split())	 		
	B.append(Point(x,y))
A=convexHull(A)
B=convexHull(B)
if(check(A,B)):
	print("YES")
else:
	print("NO")	

