#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct trie
{
	int isLeaf;
	struct trie* child[26];
};

struct trie* create()
{
	struct trie* node = (struct trie*)malloc(sizeof(struct trie));
	
    node->isLeaf = 0;
	for (int i = 0; i < 26; i++)
    {
		node->child[i] = NULL;
    }
	return node;
}

void insert(struct trie *head, char* str)
{
	struct trie* temp = head;
	while (*str)
	{
		if (temp->child[*str - 'a'] == NULL)
        {
			temp->child[*str - 'a'] = create();
        }
		temp = temp->child[*str - 'a'];
		str++;
	}
	temp->isLeaf = 1;
}

int search(struct trie* head, char* str)
{
	if (head == NULL)
		return 0;

	struct trie* temp = head;
	while (*str)
	{
		temp = temp->child[*str - 'a'];
		if (temp == NULL)
			return 0;

		str++;
	}
	return temp->isLeaf;
}

int isEmpty(struct trie* root)
{
	for (int i = 0; i < 26; i++)
    {
		if (root->child[i])
			return 1;
    }
	return 0;
}
int delete(struct trie **temp, char* str)
{
	if (*temp == NULL)
		return 0;

	if (*str)
	{
		if (*temp != NULL && (*temp)->child[*str - 'a'] != NULL && delete(&((*temp)->child[*str - 'a']), str + 1) && (*temp)->isLeaf == 0)
		{
			if (!isEmpty(*temp))
			{
				free(*temp);
				(*temp) = NULL;
				return 1;
			}
			else 
            {
				return 0;
			}
		}
	}
	if (*str == '\0' && (*temp)->isLeaf)
	{
		if (!isEmpty(*temp))
		{
			free(*temp);
			(*temp) = NULL;
			return 1;
		}
		else
		{
			(*temp)->isLeaf = 0;
			return 0;
		}
	}

	return 0;
}

int main()
{
	struct trie* root = create();

    int n;
    char s[10];
    while(1)
    {
        printf("===========TRIE===========\n");
        printf("1.Insert\n2.Search\n3.Delete\n4.Quit\n");
        printf("Enter choice: ");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            printf("Enter key to be inserted: ");
            scanf("%s",s);
            insert(root,s);
            break;
        case 2:
            printf("Enter key to search: ");
            scanf("%s",s);
            if(search(root,s))
                printf("Key found in trie\n");
            else
                printf("Key not found\n");
            break;
        case 3 :
            printf("Enter key to be deleted: ");
            scanf("%s",s);
            delete(&root,s);
            break;
        case 4: return 0;
        default: printf("Wrong Input.\n");
        }
    }
	return 0;
}
