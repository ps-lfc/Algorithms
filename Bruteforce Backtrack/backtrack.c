#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int num=0;
int counter=0;
int no_of_elements;
int capacity_of_knapsack;
int maxprofit=0;
int maxweight=0;
//call to function KWF2
int KWF2(int i,int weight,int profit,int weights[no_of_elements+1],int profits[no_of_elements+1])
{	float bound=0;
	int j;
	float x[no_of_elements+1];
	bound=profit;
	for(j=1;j<=no_of_elements;j++)
	{	x[j]=0;
	}
	while(weight<=capacity_of_knapsack && i<=no_of_elements)
	{	if(weight+weights[i]<=capacity_of_knapsack)
		{	x[i]=1;
			weight=weight+weights[i];
			bound=bound+profits[i];
		}
		else
		{	x[i]=(float)(capacity_of_knapsack-weight)/(float)(weights[i]);
			weight=capacity_of_knapsack;
			bound=bound+(profits[i]*x[i]);
		}
		i=i+1;
	}
	return bound;
}
//call for function promising
int promising(int i,int weight,int profit,int weights[no_of_elements+1],int profits[no_of_elements+1])
{	float bound=0;
	if(weight>=capacity_of_knapsack)
	{	return 0;
	}
	bound=KWF2(i+1,weight,profit,weights,profits);
	return(bound>maxprofit);
}
//call to knapsack function
int knapsack(int i,int profit,int weight,int profits[no_of_elements+1],int weights[no_of_elements+1],int bestset[no_of_elements+1],int include[no_of_elements+1])
{	int j;
	if(weight<=capacity_of_knapsack && profit>maxprofit)
	{	maxprofit=profit;
		maxweight=weight;
		num=i;
		for(j=1;j<=no_of_elements;j++)
		{	bestset[j]=include[j];
		}
	}
	if(promising(i,weight,profit,weights,profits))
	{	include[i+1]=1;
		knapsack(i+1,profit+profits[i+1],weight+weights[i+1],profits,weights,bestset,include);
		include[i+1]=0;
		knapsack(i+1,profit,weight,profits,weights,bestset,include);
	}
	return 0;
}
//main function
int main(int argc, char* argv[])
{	int elements = 1;
	int temp;
	char *line;
	char *tok ;
	FILE *fp;
	int i,j,y,z,a,g;
	float x;
	//check number of command line arguments
	if(argc!=2)
	{	printf("Provide input as per assignment requirement \n");
		exit(0);
	}
	else
	{	//open file to read
		fp=fopen(argv[1],"r");
		if(fp==0)
		{	printf("File not found exception \n");
			exit(0);			
		}
		else
		{	line = (char *)malloc(sizeof(char)*1000);
			if (fgets(line,1000,fp)) 
			{	no_of_elements=atoi(line);
			}
			else
			{	exit(0);
			}
			int weights[no_of_elements+1];
			int profits[no_of_elements+1];
			int bestset[no_of_elements+1];
			int include[no_of_elements+1];
			float pw[no_of_elements+1];
			int flag[no_of_elements+1];
			int flagcheck[no_of_elements+1];
			if(fgets(line,1000,fp))
			{	tok=strtok(line,", ");
				while(tok!=NULL)
				{	temp = atoi(tok);
					weights[elements]=temp;
					tok=strtok(NULL,", ");
					elements++;
				}
			}
			else
			{	exit(0);
			}
			elements = 1;
			if(fgets(line,1000,fp))
			{	tok=strtok(line,", ");
				while(tok!=NULL)
				{	temp = atoi(tok);
					profits[elements]=temp;
					tok = strtok(NULL,", ");
					elements++;
				}
			}
			else
			{	exit(0);
			}
			if (fgets(line,1000,fp)) 
			{	capacity_of_knapsack = atoi(line);
			}
			else
			{	exit(0);
			}
			for(i=1;i<=no_of_elements;i++)
			{	bestset[i]=0;
				include[i]=0;
				flagcheck[i]=i;
			}
			for(i=1;i<=no_of_elements;i++)
			{	pw[i]=(float)(profits[i])/(float)(weights[i]);
			}
			//insertion sort to sort profit and weight array
			for(i=1;i<=no_of_elements;i++)
			{	x= pw[i];
				y=profits[i];
				z=weights[i];
				a=flagcheck[i];
				j=i-1;
				while(j>=1 && pw[j]<x)
				{	pw[j+1]=pw[j];
					profits[j+1]=profits[j];
					weights[j+1]=weights[j];
					flagcheck[j+1]=flagcheck[j];
					j=j-1;
				}
				pw[j+1]=x;
				profits[j+1]=y;
				weights[j+1]=z;
				flagcheck[j+1]=a;
			}
			//call to knapsack
			knapsack(0,0,0,profits,weights,bestset,include);
			//open file to write
			fp=fopen("backtrack_output.txt","w+");
			if(fp==0)
			{	printf("File not found exception \n");
				exit(0);				
			}
			for(i=1;i<=no_of_elements;i++)
			{	if(bestset[i]==1)
				{	counter++;
				}
			}
			for(i=1,g=1;i<=no_of_elements,g<=no_of_elements;i++,g++)
			{	if(bestset[i]==1)
				{	flag[g]=flagcheck[i];
				}
				else
				{	flag[g]=0;	
				}
			}
			//insertion sort to sort flags
			for(i=1;i<=no_of_elements;i++)
			{	y = flag[i];
				j=i-1;
				while(j>=1 && flag[j]>y)
				{	flag[j+1]=flag[j];
					j=j-1;
				}
				flag[j+1]=y;
			}
			fprintf(fp,"%d\n",maxweight);
			fprintf(fp,"%d\n",maxprofit);
			for(i=1;i<=no_of_elements;i++)
			{	if(flag[i]!=0)
				{	fprintf(fp,"%d",flag[i]-1);				
					if(counter!=1)
					{	fprintf(fp,", ");
						counter--;
					}
				}
			}
			fclose(fp);
		}
	}
	return 0;
}