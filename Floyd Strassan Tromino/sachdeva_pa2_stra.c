#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//checks if n is the power of 2 or not
int Checkn(int n1)
{	int i,check=1;
	if(n1==1)
	{	return 1;
	}
	else
	{	for(i=0;i<n1;i++)
		{	check=check*2;
			if(check==n1)
			{	return 1;
			}
		}
	}
	return 0;
}
// normal matrix multiplication 
void normal_Matrix_multiply(int n,int a[n][n],int b[n][n],int c1[n][n])
{	int i,j,k,sum=0;
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{	for(k=0;k<n;k++)
			{	sum+=a[i][k]*b[k][j];
			}
			c1[i][j]=sum;
			sum=0;
		}
	}	
}
//applying strassan for when n is equal to one.
void strassan_for_one(int n,int a[n][n],int b[n][n],int c2[n][n])
{	int i,j,k,sum=0;
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{	for(k=0;k<n;k++)
			{	sum=sum+a[i][k]*b[k][j];
			}
			c2[i][j]=sum;
			sum=0;
		}
	}	
}
//applying strassan for when n is equal to two
void strassan_for_two(int n,int a2[n][n],int a1[n][n],int c2[n][n])
{	int a,b,c,d,e,f,g;
	a=(a2[0][0]+a2[1][1])*(a1[0][0]+a1[1][1]);
	b=(a2[1][0]+a2[1][1])*a1[0][0];
	c=a2[0][0]*(a1[0][1]-a1[1][1]);
	d=a2[1][1]*(a1[1][0]-a1[0][0]);
	e=(a2[0][0]+a2[0][1])*a1[1][1];
	f=(a2[1][0]-a2[0][0])*(a1[0][0]+a1[0][1]);
	g=(a2[0][1]-a2[1][1])*(a1[1][0]+a1[1][1]);
	c2[0][0]=a+d-e+g;
	c2[0][1]=c+e;
	c2[1][0]=b+d;
	c2[1][1]=a+c-b+f;     
}
// applying strassan for when n is greater than two. Recursive calls made in the function
void strassan_Matrix_Multiply(int n,int a[n][n],int b[n][n], int c2[n][n])
{	int i,j,m,l,k=0;
	int a11[n/2][n/2], a12[n/2][n/2], a21[n/2][n/2], a22[n/2][n/2];
	int b11[n/2][n/2], b12[n/2][n/2], b21[n/2][n/2], b22[n/2][n/2];
	int m1[n/2][n/2], m2[n/2][n/2], m3[n/2][n/2], m4[n/2][n/2], m5[n/2][n/2], m6[n/2][n/2], m7[n/2][n/2];
	int m11[n/2][n/2], m12[n/2][n/2], m21[n/2][n/2], m31[n/2][n/2], m41[n/2][n/2], m51[n/2][n/2], m61[n/2][n/2], m62[n/2][n/2], m71[n/2][n/2], m72[n/2][n/2];
	
	if(n==2)
	{	strassan_for_two(n,a,b,c2); 
	}   
	else
	{	for(i=0,m=0;i<n/2,m<n/2;i++,m++)
		{	for(j=0,l=0;j<n/2,l<n/2;j++,l++)
			{	a11[m][l]=a[i][j];
			}
		}
		for(i=0,m=0;i<n/2,m<n/2;i++,m++)
		{	for(j=n/2,l=0;j<n,l<n/2;j++,l++)
			{	a12[m][l]=a[i][j];
			}
		}
		for(i=n/2,m=0;i<n,m<n/2;i++,m++)
		{	for(j=0,l=0;j<n/2,l<n/2;j++,l++)
			{	a21[m][l]=a[i][j];
			}
		}
		for(i=n/2,m=0;i<n,m<n/2;i++,m++)
		{	for(j=n/2,l=0;j<n,l<n/2;j++,l++)
			{	a22[m][l]=a[i][j];
			}
		}
		for(i=0,m=0;i<n/2,m<n/2;i++,m++)
		{	for(j=0,l=0;j<n/2,l<n/2;j++,l++)
			{	b11[m][l]=b[i][j];
			}
		}
		for(i=0,m=0;i<n/2,m<n/2;i++,m++)
		{	for(j=n/2,l=0;j<n,l<n/2;j++,l++)
			{	b12[m][l]=b[i][j];
			}
		}
		for(i=n/2,m=0;i<n,m<n/2;i++,m++)
		{	for(j=0,l=0;j<n/2,l<n/2;j++,l++)
			{	b21[m][l]=b[i][j];
			}
		}
		for(i=n/2,m=0;i<n,m<n/2;i++,m++)
		{	for(j=n/2,l=0;j<n,l<n/2;j++,l++)
			{	b22[m][l]=b[i][j];
			}
		}
		for(i=0;i<n/2;i++)
		{	for(j=0;j<n/2;j++)
			{	m11[i][j]=a11[i][j]+a22[i][j];
				m12[i][j]=b11[i][j]+b22[i][j];
				m21[i][j]=a21[i][j]+a22[i][j];
				m31[i][j]=b12[i][j]-b22[i][j];
				m41[i][j]=b21[i][j]-b11[i][j];
				m51[i][j]=a11[i][j]+a12[i][j];
				m61[i][j]=a21[i][j]-a11[i][j];
				m62[i][j]=b11[i][j]+b12[i][j];
				m71[i][j]=a12[i][j]-a22[i][j];
				m72[i][j]=b21[i][j]+b22[i][j]; 
			}
		}         
		strassan_Matrix_Multiply(n/2,m11,m12,m1);
		strassan_Matrix_Multiply(n/2,m21,b11,m2);
		strassan_Matrix_Multiply(n/2,a11,m31,m3);
		strassan_Matrix_Multiply(n/2,a22,m41,m4);
		strassan_Matrix_Multiply(n/2,m51,b22,m5);
		strassan_Matrix_Multiply(n/2,m61,m62,m6);
		strassan_Matrix_Multiply(n/2,m71,m72,m7);

		for(i=0;i<n/2;i++)
		{	for(j=0;j<n/2;j++)
			{	c2[i][j]=m1[i][j]+m4[i][j]-m5[i][j]+m7[i][j];
			}
		}
		for(i=0,m=0;i<n/2,m<n/2;i++,m++)
		{	for(j=n/2,l=0;j<n,l<n/2;j++,l++)
			{	c2[i][j]=m3[m][l]+m5[m][l];
			}
		}
		for(i=n/2,m=0;i<n,m<n/2;i++,m++)
		{	for(j=0,l=0;j<n/2,l<n/2;j++,l++)
			{	c2[i][j]=m2[m][l]+m4[m][l];
			}
		}
		for(i=n/2,m=0;i<n,m<n/2;i++,m++)
		{	for(j=n/2,l=0;j<n,l<n/2;j++,l++)
			{	c2[i][j]=m1[m][l]+m3[m][l]-m2[m][l]+m6[m][l];
			}
		}
	}
}
//main function
int main(int argc, char* argv[])
{	int n,i,j,x;
	int flag=0;
	//check for number of arguments passed in the command line
	if(argc!=2)
	{	printf("Provide input as per assignment requirement\n");
		exit(0);
	}
	else	
	{	n=atoi(argv[1]);
		if(n<1)
		{	printf("Value of n cannot be less than 1");
		}
		else
		{	int a[n][n],b[n][n],c1[n][n],c2[n][n];
			x=Checkn(n);
			if(x==1)
			{	//generate first matrix
				printf("First Matrix\n");
				srand(time(NULL));
				for(i=0;i<n;i++)
				{	for(j=0;j<n;j++)
					{	a[i][j]=rand()%(10+1-(-10))+(-10);
					}
				}
				for(i=0;i<n;i++)
				{	for(j=0;j<n;j++)
					{	printf("%d\t",a[i][j]);
					}
					printf("\n");
				}
				//generate second matrix
				printf("Second Matrix\n");
				for(i=0;i<n;i++)
				{	for(j=0;j<n;j++)
					{	b[i][j]=rand()%(10+1-(-10))+(-10);
					}
				}
				for(i=0;i<n;i++)
				{	for(j=0;j<n;j++)
					{	printf("%d\t",b[i][j]);
					}
					printf("\n");
				}
				//normal multiplication 
				normal_Matrix_multiply(n,a,b,c1);
				//calling strassan for n equal to one
				if(n==1)
				{	strassan_for_one(n,a,b,c2);
				}
				//calling strassan for n eual to two
				if(n==2)
				{	strassan_for_two(n,a,b,c2);
				}
				//calling strassan for n greater than two
				else if(n>2)
				{	strassan_Matrix_Multiply(n,a,b,c2);
				}
				//check if result of normal multiplication matches with strassan algorithm
				for(i=0;i<n;i++)
				{	for(j=0;j<n;j++)
					{	if(c1[i][j]!=c2[i][j])
						{	flag=1;
						}
					}
				}
				//Print result if both the results match
				if(flag!=1)
				{	printf("Result for Strassan match with normal multiplication\n");
					printf("The result is:\n");
					for(i=0;i<n;i++)
					{	for(j=0;j<n;j++)
						{	printf("%d\t",c1[i][j]);
						}
						printf("\n");
					}
				}
				else
				{	printf("Result for strassan and normal multiplication do not match\n");
				}
			}
			else
			{	printf("Value of n should be power of 2\n");
				exit(0);
			}
		}
		
	}
	return 0;
}