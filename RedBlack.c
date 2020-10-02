// S20190010079
#include <stdio.h>
#include <stdlib.h>

enum nodeColor { RED, BLACK };  // To store color
struct NODE 
{
    int data, color;
    struct NODE *link[2];
};

struct NODE *root = NULL;

struct NODE *createNode(int data)  // To create a node
{
    struct NODE *new;
    new = (struct NODE *)malloc(sizeof(struct NODE));
    new->data = data;
    new->color = RED;
    new->link[0] = new->link[1] = NULL; 
    return new;
}

void insert(int data)   // To insert a node
{
    struct NODE *stack[98], *temp, *new, *x, *y;
    int dir[98], height = 0, index;
    temp = root;
    if (!root)  // For empty tree
    {
      root = createNode(data);
      return;
    }

    stack[height] = root;
    dir[height++] = 0;
    while (temp != NULL) 
    {
      if (temp->data == data)  // For duplicates
      {
        printf("Wrong Input.\n");
        return;
      }
      index = (data - temp->data) > 0 ? 1 : 0;
      stack[height] = temp;
      temp = temp->link[index];
      dir[height++] = index;
    }
    
    stack[height - 1]->link[index] = new = createNode(data);
    while ((height >= 3) && (stack[height - 1]->color == RED)) 
    {
      if (dir[height - 2] == 0)  // Case 1
      {
        y = stack[height - 2]->link[1];
        if (y != NULL && y->color == RED)   
        {
          stack[height - 2]->color = RED;
          stack[height - 1]->color = y->color = BLACK;
          height = height - 2;
        } 
        else 
        {
          if (dir[height - 1] == 0)
          {
            y = stack[height - 1];
          } 
          else   // Case 2
          {
            x = stack[height - 1];
            y = x->link[1];
            x->link[1] = y->link[0];
            y->link[0] = x;
            stack[height - 2]->link[0] = y;
          }
          
          x = stack[height - 2];
          x->color = RED;
          y->color = BLACK;
          x->link[0] = y->link[1];
          y->link[1] = x;
          if (x == root) 
          {
            root = y;   
          } 
          else 
          {
            stack[height - 3]->link[dir[height - 3]] = y;
          }
          break;
        }
      } 
      else 
      {
        y = stack[height - 2]->link[0];
        if ((y != NULL) && (y->color == RED))   // Case 3
        {
          stack[height - 2]->color = RED;
          stack[height - 1]->color = y->color = BLACK;
          height = height - 2;
        } 
        else   // Case 4
        {
          if (dir[height - 1] == 1) 
          {
            y = stack[height - 1];
          }
          else 
          {
            x = stack[height - 1];
            y = x->link[0];
            x->link[0] = y->link[1];
            y->link[1] = x;
            stack[height - 2]->link[1] = y;
          }
          
          x = stack[height - 2];
          y->color = BLACK;
          x->color = RED;
          x->link[1] = y->link[0];
          y->link[0] = x;
        
          if (x == root) 
          {
            root = y;   
          }
          else 
          {
            stack[height - 3]->link[dir[height - 3]] = y;
          }
          break;
        }
      }
    }
    root->color = BLACK;
}

void delete(int data)  // To delete a node
{
    struct NODE *stack[98], *temp, *x, *y;
    struct NODE *a, *b, *c;
    int dir[98], height = 0, d, i;
    enum nodeColor color;

    if (!root)  // If empty tree
    {
      printf("Empty Tree.\n");
      return;
    }

    temp = root;
    while (temp != NULL) 
    {
      if ((data - temp->data) == 0) 
        break;
      
      d = (data - temp->data) > 0 ? 1 : 0;
      stack[height] = temp;
      dir[height++] = d;
      temp = temp->link[d];
    }

    if (temp->link[1] == NULL)  
    {
      if ((temp == root) && (temp->link[0] == NULL)) 
      {
        free(temp);
        root = NULL;
      } 
      else if (temp == root)  
      {
        root = temp->link[0];
        free(temp);
      } 
      else 
      {
        stack[height - 1]->link[dir[height - 1]] = temp->link[0];
      }
    } 
    else   
    {
      x = temp->link[1];
      if (x->link[0] == NULL) 
      {
        x->link[0] = temp->link[0];
        color = x->color;
        x->color = temp->color;
        temp->color = color;

        if (temp == root) 
        {
          root = x;
        } 
        else 
        {
          stack[height - 1]->link[dir[height - 1]] = x;
        }

        dir[height] = 1;
        stack[height++] = x;
      } 
      else   
      {
        i = height++;
        while (1) 
        {
          dir[height] = 0;
          stack[height++] = x;
          y = x->link[0];
          if (!y->link[0])
            break;
          x = y;
        }

        dir[i] = 1;
        stack[i] = y;
        if (i > 0)
          stack[i - 1]->link[dir[i - 1]] = y;

        y->link[0] = temp->link[0];

        x->link[0] = y->link[1];
        y->link[1] = temp->link[1];

        if (temp == root) 
        {
          root = y;
        }

        color = y->color;
        y->color = temp->color;
        temp->color = color;
      }
    }

    if (height < 1)
      return;

    if (temp->color == BLACK) 
    {
      while (1) 
      {
        a = stack[height - 1]->link[dir[height - 1]];
        if (a && a->color == RED) 
        {
          a->color = BLACK;
          break;
        }

        if (height < 2)
          break;

        if (dir[height - 2] == 0) 
        {
          c = stack[height - 1]->link[1];

          if (!c)
            break;

          if (c->color == RED) 
          {
            stack[height - 1]->color = RED;
            c->color = BLACK;
            stack[height - 1]->link[1] = c->link[0];
            c->link[0] = stack[height - 1];

            if (stack[height - 1] == root) 
            {
              root = c;
            } 
            else 
            {
              stack[height - 2]->link[dir[height - 2]] = c;
            }
          
            dir[height] = 0;
            stack[height] = stack[height - 1];
            stack[height - 1] = c;
            height++;
            c = stack[height - 1]->link[1];
          }

          if ((!c->link[0] || c->link[0]->color == BLACK) && (!c->link[1] || c->link[1]->color == BLACK)) 
          {
            c->color = RED;
          } 
          else 
          {
            if (!c->link[1] || c->link[1]->color == BLACK) 
            {
              b = c->link[0];
              c->color = RED;
              b->color = BLACK;
              c->link[0] = b->link[1];
              b->link[1] = c;
              c = stack[height - 1]->link[1] = b;
            }
            c->color = stack[height - 1]->color;
            stack[height - 1]->color = BLACK;
            c->link[1]->color = BLACK;
            stack[height - 1]->link[1] = c->link[0];
            c->link[0] = stack[height - 1];
            if (stack[height - 1] == root) 
            {
              root = c;
            } 
            else 
            {
              stack[height - 2]->link[dir[height - 2]] = c;
            }
            break;
          }
        } 
        else 
        {
          c = stack[height - 1]->link[0];
          if (!c)
            break;

          if (c->color == RED) 
          {
            stack[height - 1]->color = RED;
            c->color = BLACK;
            stack[height - 1]->link[0] = c->link[1];
            c->link[1] = stack[height - 1];

            if (stack[height - 1] == root) 
            {
              root = c;
            } 
            else 
            {
              stack[height - 2]->link[dir[height - 2]] = c;
            }
            dir[height] = 1;
            stack[height] = stack[height - 1];
            stack[height - 1] = c;
            height++;
            c = stack[height - 1]->link[0];
          }
          if ((!c->link[0] || c->link[0]->color == BLACK) && (!c->link[1] || c->link[1]->color == BLACK)) 
          {
            c->color = RED;
          } 
          else 
          {
            if (!c->link[0] || c->link[0]->color == BLACK) 
            {
              b = c->link[1];
              c->color = RED;
              b->color = BLACK;
              c->link[1] = b->link[0];
              b->link[0] = c;
              c = stack[height - 1]->link[0] = b;
            }
            c->color = stack[height - 1]->color;
            stack[height - 1]->color = BLACK;
            c->link[0]->color = BLACK;
            stack[height - 1]->link[0] = c->link[1];
            c->link[1] = stack[height - 1];
            if (stack[height - 1] == root) 
            {
              root = c;
            } 
            else 
            {
              stack[height - 2]->link[dir[height - 2]] = c;
            }
            break;
          }
        }
        height--;
      }
    }
}

void print(struct NODE *node)   // To print contents of tree
{
    if (node) 
    {
      print(node->link[0]);
      printf("%d  ", node->data);
      print(node->link[1]);
    }
    return;
}

int main()  // main 
{
    int n, temp;
    while (1) 
    {
        printf("=====Red Black Tree=====\n");
        printf("1.Insert()\n2.Delete\n3.Print\n4.Quit\n");
        scanf("%d",&n);
        switch(n)
        {
          case 1:
            printf("Enter data to be inserted: ");
            scanf("%d", &temp);
            insert(temp);
            break;
          case 2:
            printf("Enter data to be deleted: ");
            scanf("%d", &temp);
            delete(temp);
            break;
          case 3:
            print(root);
            printf("\n");
            break;
          case 4: return 0; 
          default:
            printf("Wrong Input.\n");
            break;
        }
      printf("\n");
    }
}
