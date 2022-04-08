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

void insertEnd(pnode *head, int elem, double data) {
  // allocate memory for node
  pnode newNode = malloc(sizeof(pnode));
  // assign timestamp for node
  newNode->elem = elem;
  // assign data to newNode
  newNode->data = data;
  // assign flag to newNode
  // newNode->flag = 0 ;
  // assign null to next of newNode
  newNode->next = NULL;
  // store the head node temporarily (for later use)
  pnode temp = *head;

  // if the linked list is empty, make the newNode as head node
  if (*head == NULL) {
    newNode->prev = NULL;
    *head = newNode;
    return;
  }
  // if the linked list is not empty, traverse to the end of the linked list
  while (temp->next != NULL)
    temp = temp->next;
  // now, the last node of the linked list is temp
  // assign next of the last node (temp) to newNode
    temp->next = newNode;
  // assign prev of newNode to temp
  newNode->prev = temp;
}

void insert_at_end(pnode *pheadNode, int elem, double data) {
  pnode currentNode;

  if (NULL == pheadNode)
  {
    return;
  }

  /*
  This can, again be done easily by being able to have the previous element.  It 
  would also be even more useful to have a pointer to the last node, which is commonly
  used.
  */
  
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

    /* Change next only if node to be deleted is NOT the last node */
    if (del->next != NULL)
        del->next->prev = del->prev;
 
    /* Change prev only if node to be deleted is NOT the first node */
    if (del->prev != NULL)
        del->prev->next = del->next;
 
    /* Finally, free the memory occupied by del*/
    free(del);
    return;
}

void delete(pnode del)  
{  
  
    /* Change next only if node to be  
    deleted is NOT the last node */
    if (del->next != NULL)  
        del->next->prev = del->prev;  
  
    /* Change prev only if node to be  
    deleted is NOT the first node */
    if (del->prev != NULL)  
        del->prev->next = del->next;  
  
    /* Finally, free the memory occupied by del*/
    free(del);  
    return;  
} 

void printList(pnode node) 
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

void printList_task1(pnode node) 
{
    while (node != NULL) {
        printf("%d %.2lf\n", node->elem, node->data);
        node = node->next;
    }
   
}


double average(pnode node) {
    
    double medie = 0;

    // printf("\nTraversal in forward direction \n");
    for(int i = 0 ; i < 5 ; i++) {
        medie = medie + node->data; 
        node = node->next;
    }

    return (double)medie/5;
}

double deviation(pnode node) {

      double error = 0 ;
      double x = average(node);
      for(int i = 0 ; i < 5 ; i++) {
        error = error + (node->data - x) * (node->data - x);
        node = node->next; 
    }

    return (double)sqrt(error/5);

}

void freeList(pnode head)
{
   pnode tmp;

   while (head != NULL)
    {
       tmp = head;
       head = head->next;
       free(tmp);
    }

}

void free_list(pnode node) {
  while (node != NULL) {
    pnode next = node->next;
    free(node);
    node = next;
  }
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

  
    // calculare medie 
    pnode position;
    position = head ;
    float a,d;
    for( int i = 0 ; i < n-4 ; i++) {
        //printf("medie %d este : %f\n", i , average(position));
        //printf("deviatia %d este : %f\n", i , deviation(position));
        a = average(position);
        d = deviation(position);
        if(!(a - d < position->next->next->data && position->next->next->data < a + d)) {
        //printf("trebuie scos nodul %i cu valoarea %f\n", i , position->next->next->data);
        position->next->next->flag = 1 ;
        }

        position = position->next;
    }


    // eliminare noduri
    position = head ;
    // int ok = 1;
    // printList_task1(position);
    // for( position = head ; position->next != NULL ; position = position->next ) {
    //     if(position->flag == 1) {
    //      if (position->next != NULL)
    //      position->next->prev = position->prev;
    //      if (position->prev != NULL)
    //      position->prev->next = position->next;
    //      free(position);
        
        
    //     // ok = 0 ;  
    //     // delete(position);
    //     n--;
    //     }
    // }
    int copie_n = n ;
    for( int i = 0 ; i < n - 2 ; i++ ) {
          pnode temp = position->next;
          
          if(position->flag == 1) 
          {
           deleteNode(&head,position);
           copie_n--;
          }

          position = temp ;
     }


    printf("%d\n", copie_n);
    printList_task1(head);
    free_list(head);
    return 0;
}
