#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int no_of_elements;
int counter=0;
int capacity_of_knapsack;
//brute function implementing brute force algorithm
int brute(int weights[no_of_elements],int profits[no_of_elements])
{	int i,j,k,l,y,h;
	FILE *fp;
	int decimal_number;
	int best_value=0;
	int best_weight=0;
	int temp_value;
	int z=0;
	int flag1[no_of_elements];
	int temp_weight;
	int power=1;
	int best_choice[no_of_elements];
	int a[no_of_elements];
	int flag[no_of_elements];
	for(i=0;i<no_of_elements;i++)
	{	a[i]=0;
	}
	for(i=0;i<no_of_elements;i++)
	{	power=power*2;
	}
	//main loop implemented 2 raise to power n times to check all brute force cases
	for(i=0;i<power;i++)
	{	j=no_of_elements-1;
		temp_weight=0;
		temp_value=0;
		while(a[j]!=0 && j>0)
		{	a[j]=0;
			j=j-1;
		}
		a[j]=1;
		for(k=0;k<no_of_elements;k++)
		{	if(a[k]==1)
			{	temp_weight=temp_weight+weights[k];
				temp_value=temp_value+profits[k];
			}
		}
		if((temp_value>best_value)&&(temp_weight<=capacity_of_knapsack))
		{	z=0;
			for(y=0;y<no_of_elements;y++)
			{	flag[y]=0;
			}
			best_value=temp_value;
			best_weight=temp_weight;
			decimal_number=i+1;
			while(decimal_number>0)
			{	flag[z]=decimal_number%2;
				z++;
				decimal_number=decimal_number/2;
			}
		}
		for(l=0;l<no_of_elements;l++)
		{	best_choice[l]=a[l];
		}	
	}
	//open file to write
	fp=fopen("brute_output.txt","w+");
	if(fp==0)
	{	printf("File not found exception \n");
		exit(0);			
	}
	for(h=no_of_elements-1,i=0;h>-1,i<no_of_elements;h--,i++)
	{	flag1[i]=flag[h];
	}
	for(h=0;h<no_of_elements;h++)
	{	if(flag1[h]==1)
		{	counter++;
		}
	}
	fprintf(fp,"%d\n",best_weight);
	fprintf(fp,"%d\n",best_value);
	for(h=0;h<no_of_elements;h++)
	{	if(flag1[h]==1)
		{	fprintf(fp,"%d",h);
			if(counter!=1)
			{	fprintf(fp,", ");
				counter--;
			}
		}
		else
		{	continue;
		}
	}
	return 0;
}
//main function
int main(int argc, char* argv[])
{	int elements = 0;
	int temp;
	char *line;
	char *tok ;
	FILE *fp;
	int i;
	//check for command line arguments
	if(argc!=2)
	{	printf("Provide input as per assignment requirement \n");
		exit(0);
	}
	//open file to read
	else
	{	fp=fopen(argv[1],"r");
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
			int weights[no_of_elements];
			int profits[no_of_elements];
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
			elements = 0;
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
			{	
				capacity_of_knapsack = atoi(line);
			}
			else
			{	exit(0);
			}
			//call to  brute function
			brute(weights,profits);
			fclose(fp);
		}
	}
	return 0;
}