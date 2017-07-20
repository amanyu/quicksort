#include<stdio.h>
#include<stdlib.h>

void read_into_array(int *ar, int n, int flag)
{
	if(flag == 0)
	{
		for(int i = 0; i<n; i++)
			scanf("%d",ar+i);
	}
	else
		for(int i = 0; i<n; i++)
			printf("%d ",*(ar+i));
}	

void swap(int *ar,int li,int ri)
{
	int temp = ar[li];
	ar[li] = ar[ri];
	ar[ri] = temp;
}

int partition(int *ar, int upper,int lower,int size)
{
	int left_index = lower,right_index = upper;
	int pivot = ar[lower];
	
	while(left_index < right_index)
	{
		while(ar[left_index]<=pivot && left_index <= upper)
			left_index++;
		while(ar[right_index] > pivot && right_index >= lower)
			right_index--;
		
		if(left_index < right_index)
		{
			swap(ar, left_index, right_index);
			left_index++;
			right_index--;
		}
	}
	swap(ar,lower,left_index-1);

	return left_index;
}

void quicksort(int* ar,int lower,int upper, int size)
{
	if(lower >= upper)
		return;
	//int pivot = ar[0];
	int pi = partition(ar,upper,lower,size);
	
	quicksort(ar,lower,pi-1,size);
	quicksort(ar,pi,upper,size);
}

int main()
{
	int n;
	scanf("%d",&n);
	int *ar = (int*) malloc(sizeof(int)*n);
	
	read_into_array(ar,n,0);
	
	quicksort(ar,0,n-1,n);
	
	read_into_array(ar,n,1);

	return 0;
}
	
