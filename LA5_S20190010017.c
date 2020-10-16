#include<stdio.h>
#include<stdlib.h>

//both UPPERCASE and LOWERCASE are considered as SAME...

struct Trie
{
 struct Trie *alphabetArr[26];
 int flag;
};

struct Trie * rootNode;

struct Trie * newnode()
{
  struct Trie * node=(struct Trie*) malloc(sizeof(struct Trie));
  int i=0;
  for(;i<26;i++)
  node->alphabetArr[i]=NULL;
  node->flag=0;
  return node;
}

int InsertSearchDel(struct Trie *,char *,char);
   
void main()
{
 int ch;
 char keys[][11] = {"the", "a", "there", "answer", "any", "by", "bye", "their","hello","hi","therefore"};
  for (int i = 0; i < 11; i++) 
        InsertSearchDel(rootNode, keys[i],'i');
  printf("THE WORDS CONTAINING IN THE TRIE ARE :\n");
  for (int j = 0; j < 11; j++) 
        printf("\n%s",keys[j]);
 while(1)
 {
  char word[30];
  int result;
  printf("\n\n1. Insert a word into the Trie \n2. Search any word from the Trie \n3. Delete any word from the Trie \n4. Exit the loop \n\nEnter your choice: ");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1: printf("\nEnter the word to be inserted into the Trie: ");
                  scanf("%s",word);
                  result=InsertSearchDel(rootNode,word,'i');
                  if(!result) { printf("\nInsertion SUCCESSFUL!"); }
                  break;
    case 2: printf("\nEnter the word to be searched in the Trie: ");    
                  scanf("%s",word);            
                  result=InsertSearchDel(rootNode,word,'s');
                  if(result==0) printf("\nSearch SUCCESSFUL!\nThe word is PRESENT in the Trie."); 
                  else printf("\nSearch UNSUCCESSFUL!\nThe word is NOT PRESENT in the Trie!");
                  break;   
    case 3 : printf("\nEnter the word to be deleted in the Trie: ");    
                   scanf("%s",word);            
                   result=InsertSearchDel(rootNode,word,'d');
                   if(result==0) printf("\nDeletion SUCCESSFUL!"); 
                   else printf("\nSearch UNSUCCESSFUL!\nThe word is NOT PRESENT in the Trie!");
                   break;    
    case 4 :  break;
    default: break; 
  }
  if(ch==4)break;
 }

}                   

int InsertSearchDel(struct Trie *node, char *word, char mode)
{
  if(!node) 
 {
   if(mode=='i') 
  {
   printf("\nCreating rootNode node..."); 
   node=newnode(); 
   rootNode=node; 
  }
  else if(mode=='s' || mode=='d') 
  {
    printf("\nRoot node does NOT exist."); 
    return 1;
  }
 }
 while(*word)
 {
   int index=(*word|('A'^'a'))-'a';
   if(!node->alphabetArr[index]) 
   {
     if(mode=='i') 
     {
       printf("\nCreating node for character '%c'...",*word); 
       node->alphabetArr[index]=newnode();
     }
     else if(mode=='s' || mode=='d') 
    {  
      printf("\nNo node found for character '%c'.",*word); 
      return 1;  
    }
   }
   node=node->alphabetArr[index];
   word++;
 }
 if(!node->flag) 
 {
   if(mode=='i') 
  { 
    printf("\n"); 
    node->flag=1; 
    return 0;
  }
  else if(mode=='s' || mode=='d') 
  {  
    printf("\n"); return 1;  }
  }
  else if(mode=='d') 
  {
    printf("\n"); 
    node->flag=0; 
    return 0;
  }
  else return 0; 
}