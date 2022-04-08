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

// double average(pnode node) {
//     double medie = 0;
//     // printf("\nTraversal in forward direction \n");
//     for(int i = 0 ; i < 5 ; i++) {
//         medie = medie + node->data; 
//         node = node->next;
//     
//     return (double)medie/5;
// }

// double deviation(pnode node) {
//       double error = 0 ;
//       double x = average(node);
//       for(int i = 0 ; i < 5 ; i++) {
//         error = error + (node->data - x) * (node->data - x);
//         node = node->next; 
//     }
//     return (double)sqrt(error/5);
// }

void free_list(pnode node) {
  while (node != NULL) {
    pnode next = node->next;
    free(node);
    node = next;
  }
}


pnode bubbleSort(pnode start)
{   
    pnode auxiliar = NULL ;
    for (int i = 0 ; i < 5 ; i++){
     insert_at_end(&auxiliar,start->elem,start->data);
     start = start->next;
    }
    
    int swapped;
    pnode ptr1;
    pnode lptr = auxiliar->next->next->next->next;

    do
    {
        swapped = 0;
        ptr1 = auxiliar;
        double aux;
  
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

    pnode store = auxiliar->next->next;
    free_list(auxiliar);

    return store;
}

void exec_task(pnode copie, pnode lista) {
    
    insert_at_end(&lista,copie->elem,copie->data);

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

    // pnode position;
    // position = head ;
    // double a,d;
    // for( int i = 0 ; i < n-4 ; i++) {
    //     a = average(position);
    //     d = deviation(position);
    //     if(!(a - d < position->next->next->data && position->next->next->data < a + d)) {
    //     position->next->next->flag = 1 ;
    //     }
    //     position = position->next;
    // }
    // position = head ;
    // int copie_n = n ;
    // for( int i = 0 ; i < n - 2 ; i++ ) {
    //       pnode temp = position->next;
    //       if(position->flag == 1) 
    //       {
    //        deleteNode(&head,position);
    //        copie_n--;
    //       }
    //       position = temp ;
    //  }

    printf("%d\n",n-4);
    pnode position = head;
    pnode lista = NULL ;
    for(int i = 0 ; i < n - 4; i++) {
    pnode NOD = bubbleSort(position);
    exec_task(NOD, lista);
    position=position->next;
    }
    printList(lista);
    free_list(lista);
    free_list(head);
    return 0;
}