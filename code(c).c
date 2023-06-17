#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main(void) {
    int T,N,Q,i;
    scanf("%d",&T);
    while(T)
    {
       scanf("%d",&N);
       int*A=(int*)malloc(sizeof(int)*(N+1));
      int*B=(int*)malloc(sizeof(int)*(N+1));
      int*P=(int*)malloc(sizeof(int)*(N+1));
      A[0]=0;
      P[0]=0;
      B[0]=0;
       for(i=1;i<=N;i++)
       scanf("%d",&A[i]);
       for(i=1;i<=N;i++)
       scanf("%d",&P[i]);
       scanf("%d",&Q);
       while(Q)
       {
           int c,x,y,n;
           scanf("%d",&n);
           if(n==1)
           for(i=1;i<=N;i++)
           B[P[i]]=A[i];
           else if(n==2)
           {
           scanf("%d%d",&x,&y);
           c=B[x];
           B[x]=B[y];
           B[y]=c;
           }
           else
           {
            scanf("%d",&x);
           printf("%d\n",B[x]);
           }
           Q--;
       }
       T--;
    }
	return 0;
}
