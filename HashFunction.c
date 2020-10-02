// S20190010079
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

typedef struct NODE
{
    int data;
    struct NODE * next;
}NODE;

void insert(NODE *temp[], int data, int index)
{
    NODE *new = (NODE *)malloc(sizeof(NODE));
    new->data = data;
    new->next = NULL;
    if (temp[index] == NULL)
    {
        temp[index] = new;
    }
    else 
    {
        new->next=temp[index];
        temp[index]=new;
    }
}

/*********************Normal Hash Function*******************/
int hashing(int a,int b)
{
    return a%b;
}
void searchNormalFunc(NODE* b[],int key,int x)
{
    printf("Key to be searched: %d ",key);
    int index = hashing(key,x);
    int flg = 0;
    NODE *temp;
    temp = b[index];
    while(temp!=NULL)
    {
        if(temp->data = key)
        {
            printf(" - Found\n");
            flg = 1;
            break;
        }
        temp=temp->next;
    }
    if(flg == 0)
    {
        printf(" - Not Found\n");
    }
}
void normalHashFunc(int *a, int n)
{
    int bucket = 10;
    NODE *b[bucket];
    
    for(int i=0;i<bucket;i++)
    {
        b[i]=NULL;
    }
    for(int i=0;i<n;i++)
    {
        int index = hashing(a[i],bucket);
        insert(b,a[i],index); 
    }

    for(int i=0;i<bucket;i++)
    {
        NODE *temp = b[i];
        printf("%d ",i);
        while(temp!=NULL)
        {
            printf("%d : ",temp->data);
            temp = temp->next;
        }
        printf("NULL");
        printf("\n");
    }

    double tot = 0.0;
    srand(time(NULL));
    for(int i=0;i<100;i++)
    {
        int key;
        if(i%5==0)
        {
            key = (rand()%10000);
        }
        else
        {
            int index = (rand()%n);
            key = a[index];
        }
                
        clock_t start = clock(); 
        searchNormalFunc(b,key,bucket);
        clock_t end =clock();
        tot+=(double)(end-start)/CLOCKS_PER_SEC;
    }

    printf("Average Time taken to search over 100 cases: %.10lf sec\n",(tot/100));
    
}

/*********************Universal Hash Functon***********************/
int hashing1(int a)
{
    return a%17;
}
int hashing2(int a)
{
    return a%23;
}
void searchUniversalFunc(NODE* root[],int key,int x)
{
    printf("Key to be searched: %d ",key);
    int index=(hashing1(key)^hashing2(key))%x;
    int flg=0;
    NODE *temp=root[index];
    while(temp!=NULL)
    {
        if(temp->data == key)
        {
            flg=1;
            printf(" - Found\n");
            break;
        }
        temp=temp->next;
    }
    if(flg==0)
    {
        printf(" - Not Found\n");
    }
}
void universalHashFunc(int *a,int n)
{
    int bucket=41;
    
    NODE *root[bucket];
    for(int i=0;i<bucket;i++)
    {
        root[i]=NULL;
    }

    for(int i=0;i<n;i++)
    {
        int index = (hashing1(a[i])^hashing2(a[i]))%bucket;
        insert(root,a[i],index); 
    }

    for(int i=0;i<bucket;i++)
    {
        NODE *temp = root[i];
        printf("%d ",i);
        while(temp!=NULL)
        {
            printf("%d : ",temp->data);
            temp = temp->next;
        }
        printf("NULL");
        printf("\n");
    }

    double tot = 0.0;
    srand(time(NULL));
    for(int i=0;i<100;i++)
    {
        int key;
        if(i%5==0)
        {
            key = (rand()%10000);
        }
        else
        {
            int index = (rand()%n);
            key = a[index];
        }
        
        clock_t start = clock(); 
        searchUniversalFunc(root,key,bucket);
        clock_t end =clock();
        tot+=(double)(end-start)/CLOCKS_PER_SEC;
    }
    printf("Average Time taken to search over 100 cases: %.10lf sec\n",(tot/100));
}

/*************************MAIN****************************/
int main()
{
    srand(time(0));

    printf("--------------Normal Hash Function--------------\n");
    
    printf("Entre no of elements: ");
    int n;
    scanf("%d",&n);
    
    int a[n];
    printf("Array :  ");
    for(int i=0;i<n;i++)
    {
        a[i]=1+rand()%100000;
        printf("%d  ",a[i]);
    }
    printf("\n");
    
    normalHashFunc(a,n);

    printf("--------------Universal Hash Function--------------\n");
    
    printf("Entre no of elements: ");
    scanf("%d",&n);
    
    int a2[n];
    printf("Array :  ");
    for(int i=0;i<n;i++)
    {
        a2[i]=1+rand()%100000;
        printf("%d  ",a2[i]);
    }
    printf("\n");
    
    universalHashFunc(a2,n);
}



