#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#define max(a,b) a>=b ? a : b

int check_unsurprising(int score, int minimum)
{
	int i,j,k;
	for(i = 0; i <= score; i++)
		for(j = 0; j <= score; j++)
			for(k = 0; k <= score; k++)
				if((i+j+k)==score && best_score(i,j,k)>=minimum)
					if(abs(i-j)<=1&&abs(j-k)<=1&&abs(i-k)<=1)
						return 1;
	return 0;					
}

int check_surprising(int score, int minimum)
{
	int i,j,k;
	int a,b,c;
	int res = 0;
	for(i = 0; i <= score; i++)
		for(j = 0; j <=score; j++)
			for(k = 0; k <=score; k++)
			{
				if(i+j+k==score && best_score(i,j,k)>=minimum)
					if(abs(i-j)<=2 && abs(j-k)<=2 && abs(i-k)<=2)
						return 1;
			}
	return 0;
}

int best_score(int a, int b, int c)
{
	if(a>=b && b>=c)
		return a;
	if(b>=a && b>=c)
		return b;
	if(c>=a && c>=b)
		return c;
}

int main(void)
{
	int P,res = 0;
	int T,N,S,*a;
	FILE *fp,*fq;
	fp = fopen("B-large.in","r");
	fq = fopen("output.in","w");
	assert(fp!=NULL && fq!=NULL);
	fscanf(fp,"%d\n",&T);
	int i,x = 1;
	while(x <= T)
	{
		fscanf(fp, "%d %d %d",&N,&S,&P);
		
		a = (int *) malloc(sizeof(int)*N);
		assert(a!=NULL);
		for(i = 0; i < N; i++)
			fscanf(fp,"%d",&a[i]);
		for(i = 0; i < N; i++)
		{
			if(check_unsurprising(a[i],P)==1)
				res++;
                        else if(check_surprising(a[i],P)==1 && S > 0)
                          { res++; S--;} else {res+=0;}
		}
		fprintf(fq,"Case #%d: %d\n",x,res);
		res = 0;
		x++;
	}
	fprintf(fp,"\n");
	fclose(fp);
	fclose(fq);
	return 0;
}

