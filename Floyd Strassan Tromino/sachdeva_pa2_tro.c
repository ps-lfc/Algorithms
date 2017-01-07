#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void tromino(int n,int a[n][n],int start_x,int start_y,int random_x,int random_y)
{	int i,j,quadrant1_x,quadrant1_y,quadrant2_x,quadrant2_y,quadrant3_x,quadrant3_y,quadrant4_x,quadrant4_y,middle_x,middle_y;
	middle_x=start_x+(n/2);
	middle_y=start_y+(n/2);
	if(random_x<middle_x)
	{	quadrant1_x = quadrant4_x = middle_x;
		quadrant1_y = middle_y;
		quadrant4_y = middle_y - 1;
		if(random_y < middle_y)
		{	quadrant2_x = middle_x - 1;
			quadrant2_y = middle_y;
			quadrant3_x = random_x;
			quadrant3_y = random_y;
		}
		else
		{	quadrant2_x = random_x;
			quadrant2_y = random_y;
			quadrant3_x = middle_x - 1;
			quadrant3_y = middle_y - 1;
		}
	}
	else
	{	quadrant2_x = quadrant3_x = middle_x - 1;
		quadrant2_y = middle_y;
		quadrant3_y = middle_y - 1;

		if ( random_y < middle_y )
		{	quadrant1_x = middle_x;
			quadrant1_y = middle_y;
			quadrant4_x = random_x;
			quadrant4_y = random_y;
		}
		else
		{   quadrant1_x = random_x;
			quadrant1_y = random_y;
			quadrant4_x = middle_x;
			quadrant4_y = middle_y-1;
		}
	}
	tromino(n/2,a,random_x+(n/2),random_y+(n/2),quadrant1_x,quadrant1_y);
	tromino(n/2,a,random_x,random_y+(n/2),quadrant2_x, quadrant2_y);
	tromino(n/2,a,random_x,random_y,quadrant3_x,quadrant3_y);
	tromino(n/2,a,random_x+(n/2),random_y, quadrant4_x, quadrant4_y);
	
} 
void generate_missing_square(int n,int a[n][n])
{	int i,j,random_x,random_y;
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{	a[i][j]=0;
		}
	}
	srand(time(NULL));
	random_x=rand()%n;
	random_y=rand()%n;
	
	a[random_x][random_y]=-1;
	//tromino(n,a,0,0,random_x,random_y);
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{	printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}

int main(int argc,char* argv[])
{	int size=1,i,k;

	srand(time(NULL));
	if(argc!=2)
	{	printf("Provide input as per assignment requirement\n");
		exit(0);
	}
	else
	{	k=atoi(argv[1]);
		for(i=0;i<k;i++)
		{	size=size*2;	
		}
		int a[size][size];
		generate_missing_square(size,a);
	}
}