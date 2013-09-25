#include<stdio.h> // ao > ao.ppm
#include<stdlib.h>
#include<math.h>
typedef double D;typedef int I;struct V
{V operator +(V r){return V(x+r.x,y+r.y
,z+r.z);}V operator*(D r){return V(x*r,
y*r,z*r);}D operator%(V r){return x*r.x
+y*r.y+z*r.z;}D x,y,z;V(){}V operator^(
V r){return V(y*r.z-z*r.y,z*r.x-x*r.z,x
*r.y-y*r.x);}V operator!(){return*this*
(1/sqrt(*this%*this));}V(D a,D b,D c){x
=a;y=b;z=c;}};I W=256,H=256,Q=2,A=8;V S
[3]={V(-2,0,-3.5),V(-0.5,0,-3),V(1,0,-
2.2)};D R[3]={0.5,0.5,0.5};V P(0,-0.5,0
),N(0,1,0);I T(V o,V d,V&p,V&n){D t=1e9
;D b=d%N,c=(o%N+P%N)/b;if(fabs(b)>1e-17
&&0<c){t=c;p=o+d*t;n=N;}for(I i=0;i<3;
++i){V s=o+(S[i]*-1);c=s%d;c=-c-sqrt(c*
c-s%s+R[i]*R[i]);if(0<c&&c<t){t=c;p=o+d
*t;n=!(p+S[i]*-1);}}return t<1e9?1:0;}D
F(){return(D)rand()/RAND_MAX;}I main(){
printf("P3 %d %d 255 ",W,H);D x,y,u,v,X
,Y,e,t,s,i,j,c;t=s=A;for(y=0;y<H;++y)
for(x=0;c=0,x<W;printf("%d %d %d ",(I)c
,(I)c,(I)c),x++)for(v=0;v<Q;++v)for(u=0
;u<Q;++u){V o(0,0,0),d(2*(x+u/Q)/W-1,1-
2*(y+v/Q)/H,-1),p,n;if(T(o,!d,p,n)){e=t
*s;for(j=0;j<t;++j)for(i=0;i<s;X=sqrt(F
()),Y=6.2831*F(),o=!(V(1,0,0)^n),d=!V((
o*cos(Y)*X+(n^o)*sin(Y)*X+n*sqrt(1-X*X)
)),T(p,d,o,o)&&e--,++i);c+=e*255/(Q*Q*t
*s);}}}
