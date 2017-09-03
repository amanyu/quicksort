#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int i,int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void scan(int *a,int n)
{
    for(int i= 0;i<n;++i)
        scanf("%d",a+i);
}

void print(int *a,int i,int j)
{
    for(int k = i; k<j;++k)
        printf("%d ",a[k]);
    printf("\n %d to %d \n",i,j);
}
int * partition(int *a,int p,int r)
{
    int j = p;
    int index[] = {p,p+1};
    int pivot = a[p];
    for(int j = p+1; j<r; ++j)
    {
        if(a[j]<pivot)
        {
            swap(a,index[0],j);
            ++index[0];
            j--;
        }
        else if(a[j] == pivot)
        {
            swap(a,index[1],j);
            ++index[1];
            j--;
        }
    }
    //swap(a,p,index[0]);
    return index;
}
int main()
{
    int n;
    scanf("%d",&n);
    int* a = (int*)malloc(sizeof(int)*n);
    scan(a,n);
    int* index = partition(a,0,n);
    print(a,0,index[0]);
    print(a,index[0],index[1]);
    print(a,index[1],n);

    return 0;
}
