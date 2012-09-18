#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>
int main(void)
{
	int X,N,i,len,k = 1;
	FILE *fp = fopen("A-small-attempt0.in","r");
	FILE *qp = fopen("output.in","w");
	assert(fp!=NULL);
	assert(qp!=NULL);

	char table[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

	char str[109];
	fscanf(fp,"%d\n",&N);
	while(k <= N)
	{
		fgets(str,109,fp);
		str[strlen(str)-1] = '\0';
		len = strlen(str);
		for(i = 0; i < len; i++)
		{
			if(isalpha(str[i]))
			{
				str[i] = table[str[i] - 97];
			}
		}
		fprintf(qp,"Case #%d: %s\n",k,str);
		k++;
	}

	fclose(fp);
	fclose(qp);
	return 0;
}

