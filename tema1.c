// includere librarii
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// declarare lista dublu inlantuita
typedef struct node {
    int elem; // timestamp
    double data; // valoare
    int flag; // marcaj (stergere noduri)
    struct node *next; // nod urmator
    struct node *prev; // nod precedent
} node, *pnode ;


// functie inserare (la final)
void inserare(pnode *head, int elem, double data) {
    pnode nod; // declarare

    nod = malloc(sizeof(node)); // alocare
    nod->elem = elem;
    nod->data = data;
    nod->flag = 0 ;
    nod->next = NULL;
    nod->prev = NULL;

    if (*head == NULL) { // verificare lista goala
        *head = nod;
        return;
    }
    
    pnode position = *head;
    while (position->next != NULL) { // parcurgere lista
        position = position->next;
    }

    position->next = nod; // adaugare la coada
    nod->prev = position;
}

// functie stergere noduri
void deleteNode(pnode delete) {   
    // modificare legaturi
    if (delete->next != NULL)
        delete->next->prev = delete->prev;
 
    if (delete->prev != NULL)
        delete->prev->next = delete->next;
 
    free(delete);

}

// afisare lista
void printList(pnode node) {   
    // parcurgere
    while (node != NULL) {
        printf("%d %.2lf\n", node->elem, node->data);
        node = node->next;
    }
   
}

// free lista
void free_list(pnode node) {
    // parcurgere
    while (node != NULL) {
        pnode next = node->next; // retinere nod
        free(node); // eliberare
        node = next; // pas urmator
    }

}

// functie sortare lista (fereastra 5 noduri)
double bubbleSort(pnode start)
{   // creare lista auxiliara
    pnode auxiliar = NULL ;
    for (int i = 0 ; i < 5 ; i++){
     inserare(&auxiliar,0,start->data);
     start = start->next;
    }
    
    // sortare lista
    int flag;
    pnode first;
    pnode last = auxiliar->next->next->next->next;

    do
    {   flag = 0;
        first = auxiliar;
        double aux;
  
        while (first != last)
        {
            if (first->data > first->next->data)
            {   aux = first->data;
                first->data = first->next->data;
                first->next->data = aux;
                flag = 1;
            }
            first = first->next;
        }
        last = first;
    }
    while (flag);
    
    // extragere element mijloc
    double store = auxiliar->next->next->data;
    free_list(auxiliar);
    return (double)store;
}

// functie medie aritmetica (fereastra 5 noduri)
double medie_aritmetica(pnode start) {
    // transmitere pointer + parcurgere valori
    double s = 0 ;
    for(int i = 0 ; i < 5 ; i++){
        s = s + start->data;
        start = start->next;
    } 
    
    return (double)(s/5);
}

// functie inserare (dupa un nod)
void insertAfter(pnode prev_node, int elem, double data) {
    // alocare nod
    pnode nod = (pnode)malloc(sizeof(node));
    nod->flag = 0;
    nod->elem = elem;
    nod->data = data;
    
    // modificare legaturi
    nod->next = prev_node->next;
    prev_node->next = nod;
    nod->prev = prev_node;
    if (nod->next != NULL)
    nod->next->prev = nod;
}

// functie uniformizare date
void uniform(pnode start) {
    // (tehnic ar fi modul) , am lasat asa pentru simplitate
    if((start->next->elem - start->elem) >= 100 && (start->next->elem - start->elem) <= 1000) {
        start->next->elem = (start->next->elem + start->elem)/2;
        start->next->data = (double)((start->next->data + start->data)/2);
    }
}

// functie completare date
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
    double final_data;

    while(timestamp + 200 < tmpR) {
    timestamp = timestamp + 200; 
    C = (double)(timestamp - left)/(right - left);
    final_data = (1 - C)*sum_left + C*sum_right;
    insertAfter(start,timestamp,final_data);
    start = start->next;
    }

}

// afisare nr noduri
int printNumber(pnode node) 
{   int numar = 0 ;
    while (node != NULL) {
        numar++;
        node = node->next;
    }
    return numar;  
}

// functie copiere lista
void actualizare(pnode *head, pnode copiere) {
  pnode nod;
  
  // alocare nod
  nod = malloc(sizeof(node));
  nod->elem = copiere->elem;
  nod->data = copiere->data;
  nod->flag = copiere->flag ;
  nod->next = NULL;
  nod->prev = NULL;

  if (*head == NULL) { // verificare lista goala
    *head = nod;
    return;
  }
  
  pnode position = *head;
  while (position->next != NULL) { // parcurgere lista
    position = position->next;
  }
  // adaugare in coada
  position->next = nod;
  nod->prev = position;
}

// functie calculare average
double average(pnode node) {
    double medie = 0;

    for(int i = 0 ; i < 5 ; i++) {
        medie = medie + node->data; 
        node = node->next;
    }

    return (double)(medie/5);
}

// functie calculare deviatie
double deviation(pnode node) {
      double error = 0 ;
      double x = average(node);

      for(int i = 0 ; i < 5 ; i++) {
        error = error + (node->data - x) * (node->data - x);
        node = node->next; 
    }

    return (double)sqrt(error/5);

}


// de aici am ramas
void statistica(pnode node, int interval) {
    int swapped;
    pnode ptr1;
    pnode lptr = NULL;

    do
    {
        swapped = 0;
        ptr1 = node;
        double aux;
  
        while (ptr1->next != lptr)
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
    
    int contor = 0 ;
    double start = floor(node->data);
    double end = floor(node->data + interval);

    while ( node != NULL) 
    {   
       
         if(start <= node->data && node->data <= end)
        {
            contor++;
            node = node->next ;
        }

         else {
           
            if(contor != 0 ) {
                printf("[%d, %d] %d\n", (int)floor(start) , (int)floor(end) , contor);
                contor = 0 ;
            }

            start = start + interval;
            end = end + interval;


         }

    if( node == NULL ) 
    printf("[%d, %d] %d\n", (int)floor(start) , (int)floor(end) , contor);
    

        

    }


}

int main(int argc, char** argv) {
    
    // declarare lista principala
    pnode head = NULL ;

    //citire
    int n;
    int x_elem;
    double y_data;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++) {
    scanf("%d %lf", &x_elem, &y_data);
    inserare(&head,x_elem,y_data);
    }

    
    pnode position = head; // parcurgere
    
    double a,d; // declarare pt task1
    
    // declarare liste auxiliare
    pnode lista_sort = NULL ;
    pnode lista_medie = NULL ; 
    pnode indice;
    pnode temp;
    
    int nr_total;
    int contor = argc - 1;
    int nr = 0;


    for(int i = 1 ; i < argc ; i++) {
     if(strcmp(argv[i],"--e1") == 0 ) {
        position = head ; // marcare noduri de sters
        for( int i = 0 ; i < printNumber(head)-4 ; i++) {
            a = average(position);
            d = deviation(position);
            if(!(a - d < position->next->next->data && position->next->next->data < a + d)) {
            position->next->next->flag = 1 ;
            }
            position = position->next;
        }
        
        position = head ; // stergere noduri
        
        nr_total = printNumber(head);
        for( int i = 0 ; i < nr_total - 2 ; i++ ) {
            temp = position->next;
            if(position->flag == 1) 
            deleteNode(position);
            position = temp ;
        }
        
        contor--;
        if(contor == 0) {
        printf("%d\n",printNumber(head));
        printList(head);
        }
        continue;
     }


     if(strcmp(argv[i],"--e2") == 0 ) {
        position = head ;
        
        for(int i = 0 ; i < printNumber(head) - 4 ; i++) {
            inserare(&lista_sort, position->next->next->elem,bubbleSort(position));
            position = position->next;
        }

        free_list(head);
        head = NULL ;

        indice = lista_sort;
        for(int i = 0 ; i < printNumber(lista_sort) ; i++) {
        actualizare(&head,indice);
        indice = indice->next;
        }

 
        contor--;
        if(contor == 0) {
        printf("%d\n",printNumber(head));
        printList(head);
        }
        continue;
     }

     if(strcmp(argv[i],"--e3") == 0 ) {
        position = head ;


         for(int i = 0 ; i < printNumber(head) - 4; i++) {
            inserare(&lista_medie, position->next->next->elem,medie_aritmetica(position));
            position=position->next;
            }
        
        free_list(head);
        head = NULL ;

        indice = lista_medie;
        for(int i = 0 ; i < printNumber(lista_medie) ; i++) {
        actualizare(&head,indice);
        indice = indice->next;
        }


        contor--;
        if(contor == 0) {
        printf("%d\n",printNumber(head));
        printList(head);;
        }
        continue;
     }

     if(strcmp(argv[i],"--u") == 0) {
        position = head;
        for(int i = 0 ; i < printNumber(head) - 1 ; i++) {
        uniform(position);
        position = position->next;
        }
        
        contor--;
        if(contor == 0) {
        printf("%d\n", printNumber(head));
        printList(head);
        }
        continue;
     }

     if(strcmp(argv[i],"--c") == 0) {
        position = head;
        while(position->next->next != NULL) {
            if(position->next->elem - position->elem > 1000)
            completare(position);
            position = position->next ;
        }
        
        contor--;
        if(contor == 0) {
        printf("%d\n", printNumber(head));
        printList(head);
        }
        continue;
     }

     if(strstr(argv[i],"st") != NULL) {
        for(int j = 4 ; j < strlen(argv[i]) ; j++)
        nr = nr * 10 + (argv[i][j] - 48);
        statistica(head,nr);
     }
    
    }



    // free_list(head);
    // head = NULL ;

    // pnode indice = lista_sort;
    // for(int i = 0 ; i < printNumber(lista_sort) ; i++) {
    // actualizare(&head,indice);
    // indice = indice->next;
    // }
    // printList(head);

    


    free_list(lista_sort);
    free_list(lista_medie);
    free_list(head);
    
    return 0;
}
