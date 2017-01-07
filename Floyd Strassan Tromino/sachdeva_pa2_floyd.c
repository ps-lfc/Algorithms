#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX_LENGTH 1024
int row=1;
	int column=1;
//print shortest distance between all vertices
int print_path(int p1[7][7],int y,int z)
{	int x;
	if(p1[y][z]==0)
	{	return 0;
	}
	else
	{	print_path(p1,y,p1[y][z]);
		printf("%d\t",p1[y][z]);
		print_path(p1,p1[y][z],z);
	}
	return;
}
//run the floyd algorithm
int floyd(int a[7][7])
{	int i,j,k;
	int p[7][7];
	for(i=1;i<row;i++)
	{	for(j=1;j<row;j++)
		{	p[i][j]=0;
		}
	}
	for(k=1;k<row;k++)
	{	for(i=1;i<row;i++)
		{	for(j=1;j<row;j++)
			{	if(a[i][j]>a[i][k]+a[k][j])
				{	a[i][j]=a[i][k]+a[k][j];
					p[i][j]=k;
				}					
			}
		}
	}
	//check for negative cycles in distance array
	for(i=1;i<row;i++)
	{	if(a[i][i]<0)
		{	printf("Negative cycle\n");
			return 0;	
		}
	}
	printf("Distance Array\n");
	for(i=1;i<row;i++)
	{	for(j=1;j<row;j++)
		{	printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("Path Array\n");
	for(i=1;i<row;i++)
	{	for(j=1;j<row;j++)
		{	printf("%d\t",p[i][j]);
		}
		printf("\n");
	}
	for(i=1;i<row;i++)
	{	for(j=1;j<row;j++)
		{	printf("Shortest path from %d to %d:",i,j);
			printf("\t%d\t",i);
			print_path(p,i,j);
			printf("%d",j);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
//main function
int main(int argc, char* argv[])
{	int i,j;
	int temp;
	char *line;
	char *tok;
	int args[7][7],d[7][7],p[7][7];
	if(argc!=2)
	{	printf("Provide input as per assignment requirement\n");
		exit(0);
	}
	//read file and call floyd function
	else
	{	FILE *fp = fopen(argv[1], "r");
		if(fp==0)
		{	printf("File not found exception\n");
		}
		else
		{	while (fgets(line,1000,fp)) 
			{	tok = strtok(line,",");
				while(tok!=NULL)
				{	temp=atoi(tok);
					args[row][column]=temp;
					tok=strtok(NULL,",");
					column++;
				}
				row++;
				column=1;
			}
			printf("Input array\n");
			for(i=1;i<row;i++)
			{	for(j=1;j<row;j++)
				{	printf("%d\t",args[i][j]);
				}
				printf("\n");
			}
			fclose(fp);
			for(i=1;i<row;i++)
			{	for(j=1;j<row;j++)
				{	d[i][j]=args[i][j];
				}
			}
			//check for negative self loops in the array
			for(i=1;i<row;i++)
			{	if(args[i][i]<0)
				{	printf("Negative self loop error\n");
					return 0;	
				}
			}
			floyd(d);
			
		}
	}
	return 0;
}