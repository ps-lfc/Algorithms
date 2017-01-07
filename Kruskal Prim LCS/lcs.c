#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int m,n;		//check length of both the strings
//call lcs function
void lcs(char *x,char *y)
{	int i,j,k,l,length,final_length;
	int b[m+1][n+1];
	for(i=0;i<=m;i++)
	{	for(j=0;j<=n;j++)
		{	if(i==0||j==0)
			{	b[i][j]=0;
			}
			else if(x[i-1]==y[j-1])
			{	b[i][j]=b[i-1][j-1]+1;
			}
			else
			{	b[i][j]=MAX(b[i-1][j],b[i][j-1]);
			}
		}	
	}
	k=m;
	l=n;
	length=b[m][n];
	final_length=length;
	char lcs[length];
	lcs[length]='\0';
	//store lcs in lcs[]
	while(k>0 && l>0)
	{	if(x[k-1]==y[l-1])
		{	lcs[length-1]=x[k-1];
			k--;
			l--;
			length--;			
		}
		else if(b[k-1][l]>b[k][l-1])
		{	k--;
		}
		else
		{	l--;
		}
	}
	printf("\n%s %d",lcs,final_length);
}
//main function
int main(int argc,char* argv[])
{	char *x = (char *)malloc(sizeof(char));
	char *y = (char *)malloc(sizeof(char));
	char line[1024];
	FILE *fp;
	if(argc!=2)
	{	printf("Provide input as per assignment requirement\n");
		exit(0);
	}
	else
	{	fp = fopen(argv[1], "r");
		if(fp==0)
		{	printf("File not found exception\n");
		}
		else
		{	if(fgets(line,1000,fp))
			{	line[strlen(line)-1]='\0';
				strcpy(x,line);
			}
			if(fgets(line,1000,fp))
			{	line[strlen(line)-1]='\0';
				strcpy(y,line);
			}
		}
	}
	m=strlen(x);
	n=strlen(y);
	//call lcs function
	lcs(x,y);
	return 0;
}
