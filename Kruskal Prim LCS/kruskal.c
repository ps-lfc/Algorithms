#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int row=1;
int column=1;
int graph[50][50];		//input graph where the matrix is stored
int no_of_edges=0;
int row1;
// edge structure
typedef struct edge {
	int start_vertex;
	int end_vertex;
	int weight;
}edge;
//initialize structure edge
void initialize_structure(edge edge1[no_of_edges])
{	int i,j;
	int index=1;
	for(i=1; i<=row-1; i++) {
		for(j=1; j<=row-1; j++) 
		{	if(graph[i][j] != 999) {
					edge1[index].start_vertex = i;
					edge1[index].end_vertex = j;
					edge1[index].weight = graph[i][j];
					index++;
			}
		}
	}	
}
//Partition called be random_partition function to create actual partitions
int partition(edge *edge1,int p,int r)
{	int x,i,j;
	edge temp;
	x=edge1[r].weight;
	i=p-1;
	for(j=p;j<=r-1;j++)
	{	if(edge1[j].weight<=x)
		{	i=i+1;
			temp=edge1[i];
			edge1[i]=edge1[j];
			edge1[j]=temp;
		}
	}
	temp=edge1[i+1];
	edge1[i+1]=edge1[r];
	edge1[r]=temp;
	return i+1;
}

//Random partition to generate pivot
int random_partition(edge *edge1,int p,int r)
{	int pivot;
	edge temp;
	pivot=rand()%(r+1-p)+p;
	temp=edge1[pivot];
	edge1[pivot]=edge1[r];
	edge1[r]=temp;
	return partition(edge1,p,r);
}
//quicksort implementation recursive call
void random_quicksort(edge *edge1,int p,int r)
{	int q;
	if(p<r)
	{	q=random_partition(edge1,p,r);
		random_quicksort(edge1,p,q-1);
		random_quicksort(edge1,q+1,r);
	}
}
//call to find3
int find3(int x, int set[]) {

	int root, node, parent;

	root = x;
	while(root != set[root])
		root = set[root];

	node = x;

	while(node != root) {
		parent = set[node];
		set[node] = root;
		node = parent;
	}
	return root;
}
//call to union 3
void union3(int x, int y, int height[], int set[]) {

	if(height[x] == height[y]) {
		height[x] = height[x]+1;
		set[y] = x;
	}
	else {
		if(height[x] > height[y])
			set[y] = x;
		else
			set[x] = y;
	}
}


// function which implements the Kruskal's algorithm
void kruskal(edge edge1[no_of_edges]) 
{	int i,j;
	int set[no_of_edges];
	int height[no_of_edges];
	edge temp;
	edge output[no_of_edges];
	int count1=0;
	int u,v;

	for(i=1;i<=no_of_edges; i++) {
			set[i] = i;
			height[i] = 0;
	}
	for(i=1; i<=no_of_edges; i++) {
		temp = edge1[i];
		u = find3(temp.start_vertex,set);
		v = find3(temp.end_vertex,set);
		if(u!=v) {
			output[count1]=edge1[i];
			count1++;
			union3(u,v,height,set);
		}
	}
	for(i=0; i<count1; i++) {
			printf("edge %d,%d\n",output[i].start_vertex,output[i].end_vertex);
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
	else
	{	line = (char *)malloc(sizeof(char)*1000);
		fp = fopen(argv[1], "r");
		if(fp==0)
		{	printf("File not found exception\n");
			exit(0);
		}
		else
		{	while (fgets(line,1000,fp)) 
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
	//calculate total edges to be added in structure
	for(i=1;i<row;i++)
	{	for(j=1;j<row;j++)
		{	if(graph[i][j]!=999)
			{	no_of_edges++;
				
			}
		}
	}
	edge edge1[no_of_edges];
	row1=row*row;
	initialize_structure(edge1);
	random_quicksort(edge1,1,no_of_edges);
	//call to kruskal
	kruskal(edge1);
	fclose(fp);
	return 0;
}
