#include<stdio.h>
#include<stdlib.h>
#include <time.h>

/**********************QUESTION 1*********************/
//To Shuffle the array using rand() function
void shuffle(int a[],int n)
{
    srand(time(0));
    for(int i=0;i<n;i++)
    {

        int j=rand()%(n);  //swapping with a random element
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
}
int bogosort(int a[],int n)
{
    int c=0;
    while(1)
    {
        int sorted=1;
        shuffle(a,n);   //shuffling
        for(int i=1;i<n;i++)   
        {
            if(a[i]<a[i-1])
            sorted=0;
        }
        ++c;
        if(sorted)    //Checking if array is sorted
            return c;
    }
}
int question1() 
{
    int n;
    printf("\nEnter the no of elements in array:");
    scanf("%d",&n);
    
    int a[n],b[n];
    printf("Enter the array elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    for(int i=0;i<n;i++)
	b[i]=a[i];
    
    double time_spent;
    for(int i=0;i<10;i++)   //To get average time over 10 cases
    {
	printf("\n");
	for(int i=0;i<n;i++)
	    a[i]=b[i];
        
	clock_t begin = clock();
        int c=bogosort(a,n);   
        clock_t end = clock();
        time_spent += (double)(end - begin)/CLOCKS_PER_SEC;
        
	printf("time:%f",(double)(end - begin) / CLOCKS_PER_SEC);  //time of each case
	printf("    Number of iterations:%d   ",c);
    }
    time_spent/=10; // Average time over 10 cases
    
    printf("\nArray after bogosort:\n");  //printing array after sorting
    for(int i=0;i<n;i++)
        printf("%d  ",a[i]);
    printf("\nAverage Time over ten cases: %f\n",time_spent);
}


/**********************QUESTION 2*********************/
//partition function
int partition (int a[], int l, int r)
{ 
    int t;
    
    srand ( time(NULL) );
    int ind=l+rand()%(r-l+1);    //random element as pivot
    t=a[ind];
    a[ind]=a[r];
    a[r]=t;
    
    int pivot = a[r];    
    int i =(l-1);
    
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
//Quick sort function
void quick(int a[], int l, int r)  
{ 
    if (l<r) 
    {
        int pi = partition(a, l, r); 
        quick(a, l, pi-1);   //left sub-array
        quick(a, pi+1, r);   //right sub-array
    } 
} 
int question2() 
{
    int n;
    printf("Enter the no of elements in array:");
    scanf("%d",&n);
    
    int a[n],b[n];
    printf("\nEnter the array elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    shuffle(a,n);     //shuffling

    for(int i=0;i<n;i++)
	b[i]=a[i];
    
    double time_spent;
    for(int i=0;i<10;i++)   //To get average time over 10 cases
    {
	    printf("\n");
	    for(int i=0;i<n;i++)
	        a[i]=b[i];
	    
	    clock_t begin = clock();
        quick(a,0,n-1);   
        clock_t end = clock();
        double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
        
        printf("time:%f",(double)(end - begin) / CLOCKS_PER_SEC);  //time of each case
    }
    time_spent/=10; //Average over 10 cases
    
    printf("\nArray after quicksort:\n");
    for(int i=0;i<n;i++)
        printf("%d  ",a[i]);
    printf("\nAverage Time over ten cases: %f\n",time_spent);
}

/***********************MAIN***********************/

//BOGOSORT
// Average time over 10 cases for 5 elements:  3.3791s
// Standard Deviation for above cases : 6.7135s
// This value changes for every execution
// I couldn't run this for 100 cases as it will take many hours as it is randomized sort

// RANDOMIZED QUICKSORT
// Average time over 10 cases for 10 elements: 0.0000s
// Standard Deviatin for those 10 cases : 0.0000s
// Randomized Quick sort is still fast for us to notice for small input
// We would notice difference for much larger input

int main()
{
   int n;
   printf("Enter the question number:");
   scanf("%d",&n);
   
   switch(n)
   {
	case 1: question1(); break;
	case 2: question2(); break;
	default: printf("Wrong Input");
   }
}
