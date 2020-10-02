#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*******************************Question 1***************************/
void sort(int arr[], int n,int exp,int b)
{
    int result[n];
    int i,temp[b];
    for(i=0;i<b;i++)
    {
        temp[i]=0;
    }
    for(i=0;i<n;i++)
    {
        temp[(arr[i]/exp)%b]++;
    }
    for(i=1;i<b;i++)
    {
        temp[i] += temp[i - 1];
    }
    for(i=n-1;i>=0;i--)
    {
        result[temp[(arr[i]/exp)%b]-1]=arr[i];
        temp[(arr[i]/exp)%b]--;
    }
    for(i=0;i<n;i++)
    {
        arr[i] = result[i];
    }
}
/***************Radix Sort***************/
void radixSort(int a[], int n, int b) 
{
    int max = a[0];   //To get maximum element in array
    for (int i=1; i<n; i++)
    {
        if (a[i]>max)
            max=a[i];
    }
    
    for (int d=1; max/d>0; d*=10)  //To sort elements place wise
        sort(a, n, d, b);
}
/***********Radix Sort Implementation**********/
int question1() 
{
    int n,b;
    printf("Enter the no of elements in array: ");
    scanf("%d",&n);
    printf("Enter base: ");
    scanf("%d",&b);
    int a[n];
    printf("Enter the elements: \n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    double time_spent;
    clock_t begin = clock();
    radixSort(a, n, b);
    clock_t end = clock();
    time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
    printf("Time: %f\n",time_spent);

    printf("Array after sorting:\n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
}

/*******************************Question 2***************************/
struct node 
{ 
	int data; 
	struct node *left, *right; 
}; 
/***********CREATE**********/
struct node *create(int item) 
{ 
	struct node *t = (struct node *)malloc(sizeof(struct node)); 
	t->data = item; 
	t->left = t->right = NULL; 
	return t; 
} 
/***********PRINT**********/
void print(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		print(root->left); 
		printf("%d ", root->data); 
		print(root->right); 
	} 
} 
/************INSERT************/
struct node* insert(struct node* root, int data) 
{ 
    if (root == NULL) 
        return create(data); 

	if (data < root->data) 
		root->left = insert(root->left, data); 
	else
		root->right = insert(root->right, data); 

	return root; 
} 
struct node * leastNode(struct node* node) 
{ 
    struct node* temp = node; 
    
    while (temp && temp->left != NULL) //To get to lefmost node
        temp = temp->left; 
  
    return temp; 
} 
/************DELETE*************/
struct node* Delete(struct node* root, int data) 
{ 
	if (root == NULL) //Case 1
	    return root; 
	    
	if (data < root->data)  
		root->left = Delete(root->left, data); 
	else if (data > root->data) 
		root->right = Delete(root->right, data); 
	else
	{ 
		if (root->left == NULL) //Case 2
		{ 
			struct node *temp = root->right; 
			free(root); 
			return temp; 
		} 
		else if (root->right == NULL) 
		{ 
			struct node *temp = root->left; 
			free(root); 
			return temp; 
		} 
        //Case 3
		struct node* temp = leastNode(root->right); 
		root->data = temp->data; 
		root->right = Delete(root->right, temp->data); 
	} 
	return root; 
} 
/***********SEARCH***********/
int search(struct node* root, int data) 
{ 
    while (root != NULL) 
    { 
        if (data > root->data) 
            root = root->right; 
        else if (data < root->data) 
            root = root->left; 
        else
            return 1; //Found 
    } 
    return 0; //Not Found 
} 
/**********Binary Search Tree**********/
int question2() 
{
	struct node *root = NULL;
	
	while (1)
	{
	    int n, temp;
	    printf("1.Insert\n2.Delete\n3.Search\n4.Print\n5.Quit\n");
	    printf("Enter Your choice:\n");
	    scanf("%d",&n);
	    
	    switch(n)
	    {
	        case 1:
	            printf("Enter data to be inserted: ");
	            scanf("%d",&temp);
	            root=insert(root,temp);
	            break;
	        case 2:
	            printf("Enter data to be deleted: ");
	            scanf("%d",&temp);
	            root=Delete(root,temp);
	            break;
	        case 3:
	            printf("Enter data to be searched: ");
	            scanf("%d",&temp);
	            if (search(root,temp))
	                printf("Found\n");
	            else
	                printf("Not Found\n");
	            break;
	        case 4:
	            printf("BST: ");
	            print(root);
		        printf("\n");
	            break;
	        case 5:
	            return 0;
	        default : printf("Wrong input"); 
	    }
	}
} 

/**************MAIN***************/
int main()
{
    int n;
    printf("Enter Question No: ");
    scanf("%d",&n);
    switch(n)
    {
	case 1: question1(); break;
	case 2: question2(); break;
	default: printf("Wrong Input"); 
    }
}
