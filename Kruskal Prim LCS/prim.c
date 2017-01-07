#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int row=1;
int column=1;
int graph[50][50];			//input graph where the matrix is stored
//Prims algorithm function
void prim()
{	int i,j,k,l;
	int nodes_visited[row];
	int min_j,min_k;
	int min;
	for(i=0;i<row;i++)
	{			nodes_visited[i]=0;
	}
	nodes_visited[1]=1;
	for(i=1;i<row-1;i++)
	{	min=999;
		for(j=1;j<row;j++)
		{	if(nodes_visited[j]==1)
			{	for(k=1;k<row;k++)
				{	if(nodes_visited[k]==0)
					{	if(graph[j][k]<min)
						{	min=graph[j][k];
							min_j=j;
							min_k=k;
							
						}	
					}	
				}
			}
		}
		nodes_visited[min_k]=1;
		printf("edge %d,%d\n",min_j,min_k);
	}
	
	
}
//main function
int main(int argc, char* argv[])
{	int i,j;
	int temp;
	char *line;
	char *tok;
	FILE *fp;
	if(argc!=2)
	{	printf("Provide input as per assignment requirement\n");
		exit(0);
	}
	//open file graph.txt
	else
	{	fp = fopen(argv[1], "r");
		if(fp==0)
		{	printf("File not found exception\n");
			exit(0);
		}
		//read file
		else
		{
			line = (char *)malloc(sizeof(char)*1000);
			while (fgets(line,1000,fp)!=NULL) 
			{	tok = strtok(line,",");
				while(tok!=NULL)
				{	temp=atoi(tok);
					graph[row][column]=temp;
					tok=strtok(NULL,",");
					column++;
				}
				row++;
				column=1;
			}
		}
	}
	//put 999 on diagonal edges
	for(i=1;i<row;i++)
	{	graph[i][i]=999;
	}
	//put 999 on all matrix points where there are no edges
	for(i=1;i<row;i++)
	{	for(j=1;j<row;j++)
		{	if(graph[i][j]==0)
			{	graph[i][j]=999;
			}
		}
	}
	//call prim's algorithm
	prim();
	//close file
	fclose(fp);
	return 0;
}
