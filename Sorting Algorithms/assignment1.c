#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int a[1000],n;
int merge_count=1;
int quick_count=1;
//Take input n and randomly generate n numbers based on its value
int generate_numbers()
{	int i,j;
	printf("Specify the number of input data \n");
	scanf("%d",&n);
	if(n<1 && n>1000)
	{	printf("The value of number of input data does not specify the requirements of this program \n");
		exit(0);
	}
	//display unsorted array
	else if(n<=20 && n>=1)
	{	srand(time(NULL));
		printf("Array to be sorted in numerical form\n");
		for(i=0;i<n;i++)
		{	a[i]= rand()%16;
			printf("%d \n",a[i]);
		}
		printf("Array to be sorted in * form\n");
		for(i=0;i<n;i++)
		{	for(j=0;j<a[i];j++)
			{	printf("*");
			}
			printf("\n");
		}
	}
	else if(n>20 && n<=1000)
	{	srand(time(NULL));
		printf("Array to be sorted\n");
		for(i=0;i<n;i++)
		{	
			a[i]= rand();
		}
		for(i=0;i<n;i++)
		{	printf("%d \n", a[i]);
		}
	}
}

//Generate numbers for sounting sort
int generate_numbers_count()
{	int i,j;
	printf("Specify the number of input data \n");
	scanf("%d",&n);
	if(n<1 && n>1000)
	{	printf("The value of number of input data does not specify the requirements of this program \n");
		exit(0);
	}
	else if(n<=20 && n>=1)
	{	srand(time(NULL));
		printf("Array to be sorted in numerical form\n");
		for(i=0;i<n;i++)
		{	
			a[i]= rand()%16;
			printf("%d \n",a[i]);
		}
		printf("Array to be sorted in * form\n");
		for(i=0;i<n;i++)
		{	for(j=0;j<a[i];j++)
			{	printf("*");
			}
			printf("\n");
		}
	}
	//display unsorted array
	else if(n>20 && n<=1000)
	{	srand(time(NULL));
		printf("Array to be sorted\n");
		for(i=0;i<n;i++)
		{	
			a[i]= rand()%100;
		}
		for(i=0;i<n;i++)
		{	printf("%d \n", a[i]);
		}
	}
}
//insertion sort for number of elements greater than 20
void insertion_sort()
{	int i,j,x,k,l;
	for(i=1;i<n;i++)
	{	x=a[i];
		j=i-1;
		while(j>=0 && a[j]>x)
		{	a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=x;
	}
}
//insertion sort for number of elements less than or equal to 20
void brief_insertion_sort()
{	int i,j,x,k,l;
	for(i=1;i<n;i++)
	{	x=a[i];
		j=i-1;
		while(j>=0 && a[j]>x)
		{	a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=x;
		printf("Step %d \n",i);
		for(k=0;k<n;k++)
		{	for(l=0;l<a[k];l++)
			{	printf("*");
			}
			printf("\n");
		}
	}
}
//count sort for number of elements greater than 20
void count_sort()
{	int i,b[100],q;
	for(i=0;i<=99;i++)
	{	b[i]=0;
	}
	for(i=0;i<=n-1;i++)
	{	b[a[i]]+=1;
	}
	q=0;
	for(i=0;i<=99;i++)
	{	while(b[i]>0)
		{	a[q]=i;
			b[i]-=1;
			q=q+1;
		}
	}
}
//count sort for number of elements less than or equal to 20
void brief_count_sort()
{	int i,b[100],q,k,l;
	for(i=0;i<=15;i++)
	{	b[i]=0;
	}
	for(i=0;i<=n-1;i++)
	{	b[a[i]]+=1;
	}
	q=0;
	for(i=0;i<=15;i++)
	{	while(b[i]>0)
		{	a[q]=i;
			b[i]-=1;
			q=q+1;
		}
		printf("Step %d \n",i+1);
		for(k=0;k<n;k++)
		{	for(l=0;l<a[k];l++)
			{	printf("*");
			}
			printf("\n");
		}
	}
}
//merge function called to merge the arrays after de-merging
void merge(int left,int mid,int right)
{	int i,j,k,m1,m2,h,l,q;
	m1=mid-left+1;
	m2=right-mid;
	int b[m1],c[m2];
	for(i=0;i<m1;i++)
	{	b[i]=a[left+i];
	}
	for(i=0;i<m2;i++)
	{	c[i]=a[mid+1+i];
	}
	i=0;
	j=0;
	k=left;
	q=0;
	while(i<m1 && j<m2)
	{	if(b[i]<=c[j])
		{	a[k]=b[i];
			i++;
		}
		else
		{	a[k]=c[j];
			j++;
		}
		k++;
	}
	while(i<m1)
	{	a[k]=b[i];
		i++;
		k++;
	}
	while(j<m2)
	{	a[k]=c[j];
		j++;
		k++;
	}		
}
//merge sort for elements greater than 20
void merge_sort(int l, int r)
{	int mid;
	if(l<r)
	{	mid=(l+r-1)/2;
		merge_sort(l,mid);
		merge_sort(mid+1,r);
		merge(l,mid,r);
	}
}

//merge sort for elements less than or equal to 20 
void brief_merge_sort(int l, int r)
{	int mid,i,j;
	if(l<r)
	{	mid=(l+r-1)/2;
		brief_merge_sort(l,mid);
		brief_merge_sort(mid+1,r);
		merge(l,mid,r);
		printf("After step  %d:\n",merge_count);
		for(i=0;i<n;i++)
		{	for(j=0;j<a[i];j++)
				{	printf("*");
				}
				printf("\n");
		}
		merge_count++;
	}
}
//Partition called be random_partition function to create actual partitions
int partition(int p,int r)
{	int x,i,j,temp;
	x=a[r];
	i=p-1;
	for(j=p;j<=r-1;j++)
	{	if(a[j]<=x)
		{	i=i+1;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	return i+1;
}
//Random partition to generate pivot
int random_partition(int p,int r)
{	int pivot,temp;
	pivot=rand()%(r+1-p)+p;
	temp=a[pivot];
	a[pivot]=a[r];
	a[r]=temp;
	return partition(p,r);
}
//quicksort implementation recursive call for n greater than 20
void random_quicksort(int p,int r)
{	int q;
	if(p<r)
	{	q=random_partition(p,r);
		random_quicksort(p,q-1);
		random_quicksort(q+1,r);
	}
}
//quicksort implementation recursive call for n less than or equal to 20
void brief_random_quicksort(int p,int r)
{	int q,i,j;
	if(p<r)
	{	q=random_partition(p,r);
		brief_random_quicksort(p,q-1);
		brief_random_quicksort(q+1,r);
		printf("After step  %d:\n",quick_count);
		for(i=0;i<n;i++)
		{	for(j=0;j<a[i];j++)
				{	printf("*");
				}
				printf("\n");
		}
		quick_count++;
	}
}
//display function to print the sorted array
void display()
{	int i;
	printf("Sorted numbers are \n");
			for(i=0;i<n;i++)
			{	 printf("%d \n",a[i]);
			}
}	
int main()
{	int choice,i;
	printf("Press 1 for insertion sort \n");
	printf("Press 2 for count sort \n");
	printf("Press 3 for merge sort \n");
	printf("Press 4 for randomized quick sort \n");
	scanf("%d",&choice);
	switch(choice)
	{	case 1:
			generate_numbers();
			//Insertion sort for number of elements greater than 20
			if(n>20)
			{	insertion_sort();
			}
			//Insertion sort for number of elements less than or equal to 20 to print *'s
			else if(n<=20)
			{	brief_insertion_sort();
			}
			display();
		break;
		case 2:
			generate_numbers_count();
			//Count sort for number of elements greater than 20
			if(n>20)
			{	count_sort();
			}
			//Count sort for number of elements less than or equal to 20 to print *'s
			else if(n<=20)
			{	brief_count_sort();
			}
			display();
		break;
		case 3:
			generate_numbers();
			//Call for merge sort
			if(n>20)
			{	merge_sort(0,n-1);
			}
			if(n<=20)
			{	brief_merge_sort(0,n-1);
			}
			display();
		break;
		case 4:
			generate_numbers();
			if(n>20)
			{	random_quicksort(0,n-1);
			}
			if(n<=20)
			{	brief_random_quicksort(0,n-1);
			}
			display();
		break;
		default:
			printf("Wrong Choics of input! \n");	
	}
	return 0;
}