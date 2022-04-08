#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct node {
    int elem;
    double data;
    int flag;
    struct node *next;
    struct node *prev;
} node, *pnode ;

void insert_at_end(pnode *pheadNode, int elem, double data) {
  pnode currentNode;

  if (NULL == pheadNode)
  {
    return;
  }
  
  currentNode = malloc(sizeof *currentNode);
  pnode i = *pheadNode;
  currentNode->elem = elem;
  currentNode->data = data;
  currentNode->flag = 0 ;
  currentNode->next = NULL;
  currentNode->prev = NULL;

  if (*pheadNode == NULL) {
    *pheadNode = currentNode;
    return;
  }

  while (i->next != NULL) { /* Go to the end of the list */
    i = i->next;
  }

  i->next = currentNode;
  currentNode->prev = i;
}

void deleteNode(pnode *head_ref, pnode del)
{
    if (del->next != NULL)
        del->next->prev = del->prev;
 
    if (del->prev != NULL)
        del->prev->next = del->next;
 
    free(del);
    return;
}

void printList_explicit(pnode node) 
{
    pnode last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printf(" %f ", node->data);
        // printf(" %d ", node->flag);
        last = node;
        node = node->next;
    }
 
    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %f ", last->data);
        // printf(" %d ", last->flag);
        last = last->prev;
    }
}

void printList(pnode node) 
{
    while (node != NULL) {
        printf("%d %.2lf\n", node->elem, node->data);
        node = node->next;
    }
   
}


void free_list(pnode node) {
  while (node != NULL) {
    pnode next = node->next;
    free(node);
    node = next;
  }
}


double bubbleSort(pnode start)
{   int swapped;
    pnode ptr1;
    pnode lptr = start->next->next->next->next;

    do
    {
        swapped = 0;
        ptr1 = start;
        float aux;
  
        while (ptr1 != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {   aux = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = aux;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);

    return (double)start->next->next->data;
}

double medie_aritmetica(pnode start) {
    double s = 0 ;
    for(int i = 0 ; i < 5 ; i++){
        s = s + start->data;
        start = start->next;
    } 
    
    return (double)(s/5);
}



int main() {
    pnode head = NULL ;
    int n;
    scanf("%d", &n);
    int x_elem;
    double y_data;
    for(int i = 0 ; i < n ; i++) {
    scanf("%d %lf", &x_elem, &y_data);
    insert_at_end(&head,x_elem,y_data);
    }

    printf("%d\n",n-4);
    pnode position = head;
    for(int i = 0 ; i < n - 4; i++) {
    printf("%d %.2lf\n",position->next->next->elem, medie_aritmetica(position));
    position=position->next;
    }
    free_list(head);
    return 0;
}