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
{   
    pnode auxiliar = NULL ;
    for (int i = 0 ; i < 5 ; i++){
     insert_at_end(&auxiliar,0,start->data);
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

    double store = auxiliar->next->next->data;
    free_list(auxiliar);

    return (double)store;
}

double medie_aritmetica(pnode start) {
    double s = 0 ;
    for(int i = 0 ; i < 5 ; i++){
        s = s + start->data;
        start = start->next;
    } 
    
    return (double)(s/5);
}

void insertAfter(pnode prev_node, int elem, double data) {

    // check if previous node is NULL
    if (prev_node == NULL) {
        printf("previous node cannot be NULL");
        return;
    }

    // allocate memory for newNode
    pnode newNode = (pnode)malloc(sizeof(node));

    // assign data to newNode
    newNode->flag = 0;
    newNode->elem = elem;
    newNode->data = data;

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

void uniform(pnode start) { // incearca si cu modul
    if((start->next->elem - start->elem) >= 100 && (start->next->elem - start->elem) <= 1000) {
        start->next->elem = (start->next->elem + start->elem)/2;
        start->next->data = (double)((start->next->data + start->data)/2);
    }
}

void completare(pnode start) {
    
    int tmpR;
    tmpR = start->next->elem;
    
    double l0,l1,l2;
    double r0,r1,r2;
    l2 = start->data;
    l1 = start->prev->data;
    l0 = start->prev->prev->data;
    r2 = start->next->data;
    r1 = start->next->next->data;
    r0 = start->next->next->next->data;

    double w0,w1,w2;
    w0 = (double)0.1/1.425;
    w1 = (double)0.325/1.425;
    w2 = (double)1/1.425;

    double sum_left,sum_right;
    sum_left = l0*w0 + l1*w1 + l2*w2;
    sum_right = r0*w0 +r1*w1 + r2*w2;
        
    double C;
    int left,right;
    int timestamp = start->elem;
    left = start->elem ;
    right = start->next->elem;
    // C = (double)(timestamp - left)/(right - left);
    double final_data;
    
    while(timestamp + 200 < tmpR) {
    timestamp = timestamp + 200; 
    C = (double)(timestamp - left)/(right - left);
    final_data = (1 - C)*sum_left + C*sum_right;

    insertAfter(start,timestamp,final_data);
    start = start->next;
    }

}

int printNumber(pnode node) 
{   int numar = 0 ;
    while (node != NULL) {
        numar++;
        node = node->next;
    }
    return numar;  
}

void actualizare(pnode *pheadNode, pnode copiere) {
  pnode currentNode;

  if (NULL == pheadNode)
  {
    return;
  }
  
  currentNode = malloc(sizeof *currentNode);
  pnode i = *pheadNode;
  currentNode->elem = copiere->elem;
  currentNode->data = copiere->data;
  currentNode->flag = copiere->flag ;
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

int main(int argc, char** argv) {
    pnode head = NULL ;
    int n;
    scanf("%d", &n);
    int x_elem;
    double y_data;
    for(int i = 0 ; i < n ; i++) {
    scanf("%d %lf", &x_elem, &y_data);
    insert_at_end(&head,x_elem,y_data);
    }

    
    pnode position = head;
    pnode lista_sort = NULL ;
    pnode lista_medie = NULL ;
    for(int i = 0 ; i < n - 4; i++) {
    insert_at_end(&lista_sort, position->next->next->elem,bubbleSort(position));
    insert_at_end(&lista_medie, position->next->next->elem,medie_aritmetica(position));
    position=position->next;
    }
    
    position = head;
    while(position->next->next != NULL) {
    if(position->next->elem - position->elem > 1000)
    completare(position);
    position = position->next ;
    }

    for(int i = 1 ; i < argc ; i++) {
     if(strcmp(argv[i],"--e1") == 0 ) {
        printf("%d\n",printNumber(head));
        printList(head);
        continue;
     }
     if(strcmp(argv[i],"--e2") == 0 ) {
        printf("%d\n",printNumber(lista_sort));
        printList(lista_sort);
        continue;
     }
     if(strcmp(argv[i],"--e3") == 0 ) {
        printf("%d\n",printNumber(lista_medie));
        printList(lista_medie);
        continue;
     }
     if(strcmp(argv[i],"--c") == 0) {
        printf("%d\n", printNumber(head));
        printList(head);
     }
    
    }
    
    free_list(head);
    head = NULL ;

    pnode indice = lista_sort;
    for(int i = 0 ; i < printNumber(lista_sort) ; i++) {
    actualizare(&head,indice);
    indice = indice->next;
    }
    printList(head);

    
    // position = head ; // uniformizare
    // for(int i = 0 ; i < n - 1 ; i++) {
    // uniform(position);
    // position = position->next;
    // }
     
    // position = head;
    // while(position->next->next != NULL) {
    // if(position->next->elem - position->elem > 1000)
    // completare(position);
    // position = position->next ;
    // }


    

    free_list(lista_sort);
    free_list(lista_medie);
    free_list(head);
    return 0;
}