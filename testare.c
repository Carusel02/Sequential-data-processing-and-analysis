#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int elem;
    double data;
    int flag;
    struct node *next;
    struct node *prev;
} node, *pnode ;

void insert_at_end(pnode *pheadNode, int elem, double data) {
  pnode currentNode = (pnode)malloc(sizeof(node));

  if (NULL == pheadNode)
  {
    return;
  }
  
  // currentNode = malloc(sizeof(node));
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

void insertAfter(pnode prev_node, int elem, double data) {

    // check if previous node is NULL
    if (prev_node == NULL) {
        printf("previous node cannot be NULL");
        return;
    }

    // allocate memory for newNode
    pnode newNode;
    newNode = malloc(sizeof( *newNode));

    // assign data to newNode
    newNode->data = data;
    newNode->elem = elem;

    // set next of newNode to next of prev node
    newNode->next = prev_node->next;

    // set next of prev node to newNode
    prev_node->next = newNode;

    // set prev of newNode to the previous node
    newNode->prev = prev_node;

    // set prev of newNode's next to newNode
    if (newNode->next != NULL)
        newNode->next->prev = newNode;
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

int main() {
    
    pnode head = NULL ;

    insert_at_end(&head,1,1);
    insert_at_end(&head,2,2);
    insert_at_end(&head,3,3);
    insert_at_end(&head,4,4);
    insert_at_end(&head,5,5);

    pnode test = head->next ;

    insertAfter(test,2,100);
    printList(head);
    free_list(head);

}