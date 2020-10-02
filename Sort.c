#include <stdio.h>
#include <stdlib.h>

/*****************INSERTION SORT********************/
void insertion(int a[], int n) 
{ 
    int i, temp, j; 
    for (i=1; i<n; i++) 
    { 
        temp=a[i]; 
        j=i-1; 
        
        while (j>=0 && a[j]>temp) 
        { 
            a[j+1] = a[j]; 
            j=j-1; 
        } 
        a[j+1] = temp; 
    } 
    
    printf("\nINSERTION SORT:\n");
    for (i=0; i<n; i++) 
        printf("%d ", a[i]); 
    printf("\n");
} 

/*****************MERGE SORT************************/
void merge(int a[], int l, int m, int r) 
{ 
    int i, j, k; 
    int x = m-l+1; 
    int y = r-m; 
  
    int L[x], R[y]; 
  
    for (i=0; i<x; i++) 
        L[i] = a[l+i]; 
    for (j=0; j<y; j++) 
        R[j] = a[m+1+j]; 
  
    i = 0; 
    j = 0; 
    k = l;
    while (i<x && j<y) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k] = L[i]; 
            i++; 
        } 
        else 
        { 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i<x) 
    { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j<y) 
    { 
        a[k] = R[j]; 
        j++; 
        k++; 
    } 
}
void mergeSort(int a[], int l, int r) 
{ 
    if (l<r) 
    { 
        int m=l+(r-l)/2; 
        mergeSort(a,l,m); 
        mergeSort(a,m+1,r); 
  
        merge(a,l,m,r); 
    }
}  
 
/****************QUICK SORT********************/
int partition (int a[], int l, int r) 
{ 
    int pivot = a[r];
    int i =(l-1);
    int t;
  
    for (int j=l; j<=r-1; j++) 
    { 
        if (a[j]<pivot) 
        { 
            i++;
            
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        } 
    } 
    
    t=a[i+1];
    a[i+1]=a[r];
    a[r]=t;
    return (i+1); 
}
void quick(int a[], int l, int r) 
{ 
    if (l<r) 
    {
        int pi = partition(a, l, r); 
        quick(a, l, pi-1); 
        quick(a, pi+1, r); 
    } 
} 

/***************HEAP SORT*****************/
void heapify(int a[], int n, int i) 
{
    int t;
    int max = i;
    int l = 2*i+1;
    int r = 2*i+2;
  
    if (l<n && a[l]>a[max])
        max = l;
  
    if (r<n && a[r]>a[max])
        max = r;
  
    if (max!=i) 
    {
        t=a[i];
        a[i]=a[max];
        a[max]=t;
        heapify(a, n, max);
    }
}
void heap(int a[], int n) 
{
    int t;
    for (int i=n/2-1; i>=0; i--)
        heapify(a,n,i);
  
    for (int i=n-1; i>=0; i--) 
    {
        t=a[0];
        a[0]=a[i];
        a[i]=t;
        heapify(a,i,0);
    }
}


/*******************MAIN********************/
int main()
{
    int n,i,q;
    printf("Enter the no of elements in the array:");
    scanf("%d",&n);
    
    int a[n];
    printf("\nEnter the elements in the array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    printf("\nSelect the sorting method:\n1.Insertion Sort\n2.Merge Sort\n3.Quick Sort\n4.Heap Sort\n");
    scanf("%d",&q);
    switch(q)
    {
        case 1:insertion(a,n);break;
        case 2:mergeSort(a,0,n-1);
                printf("\nMERGE SORT:\n");
                for (int i=0; i<n; i++) 
                    printf("%d ", a[i]); 
                printf("\n");
                break;
        case 3:quick(a,0,n-1);
                printf("\nQUICK SORT:\n");
                for (int i=0; i<n; i++) 
                    printf("%d ", a[i]); 
                printf("\n");
                break;
        case 4:heap(a,n);
                printf("\nHEAP SORT:\n");
                for (int i=0; i<n; i++) 
                    printf("%d ", a[i]); 
                printf("\n");
                break;
        default:printf("Wrong Input"); return 1;
    }
    
}

