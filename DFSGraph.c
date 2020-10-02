// S20190010079
#include <stdio.h>
#include <stdlib.h>

struct NODE 
{
    int vertex;
    struct NODE* next;
};
struct GRAPH 
{
    int numOfVertices;
    int* visited; 
    struct NODE** lists;
};

/******************Creating node and graph********************/
struct NODE* createNODE(int temp) 
{
    struct NODE* new = malloc(sizeof(struct NODE));
    new->vertex = temp;
    new->next = NULL;
    return new;
}
struct GRAPH* createGRAPH(int v) 
{
    struct GRAPH* graph = malloc(sizeof(struct GRAPH));
    graph->numOfVertices = v;
    graph->lists = malloc(v * sizeof(struct NODE*));
    graph->visited = malloc(v * sizeof(int));

    for (int i=0; i<v; i++) 
    {
        graph->lists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

/******************Add egde********************/
void add(struct GRAPH* graph, int s, int d) 
{
    struct NODE* new = createNODE(d);
    new->next = graph->lists[s];
    graph->lists[s] = new;
    new = createNODE(s);
    new->next = graph->lists[d];
    graph->lists[d] = new;
}

/*********************DFS***********************/
void DepthFirstSearch(struct GRAPH* graph, int vertex) 
{
    struct NODE* adjList = graph->lists[vertex];
    struct NODE* temp = adjList;

    graph->visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    while (temp != NULL) 
    {
        int connected = temp->vertex;

        if (graph->visited[connected] == 0) 
        {
            DepthFirstSearch(graph, connected);
        }
        temp = temp->next;
    }
}

/*******************Print*****************/
void print(struct GRAPH* graph) 
{
    for (int v=0; v<graph->numOfVertices; v++) 
    {
        struct NODE* temp = graph->lists[v];
        printf("\nAdjacency List of %d\n ", v);
        while (temp) 
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

/*********************MAIN*******************/
int main() 
{
    int n;
    printf("\nEnter no of vertices in the GRAPH: ");
    scanf("%d",&n);
    struct GRAPH* graph = createGRAPH(n);

    while(1)
    {
        int t,a,b,c;
        printf("1.Add an edge\n2.Depth First Search\n3.Print the graph\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&t);
        switch(t)
        {
            case 1:
                printf("Enter the vertices to add an edge: ");
                scanf("%d%d",&a,&b);
                if(a>=n || b>=n || a<0 || b<0 )
                    printf("!! Wrong vertices\n");
                else
                    add(graph,a,b);
                break;
            case 2:
                printf("Enter vertice to start DepthFirstSearch: ");
                scanf("%d",&c);
                if(c>=n || c<0)
                    printf("!! Wrong vertex\n");
                else
                    DepthFirstSearch(graph,c);
                break;
            case 3:
                print(graph);
                break;
            case 4:
                printf("\n");
                return 0;
        }
    }    
}
