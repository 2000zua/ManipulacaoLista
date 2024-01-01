/**
 * ESTE PROGRAMA NOS VAMOS CRIAR UMA FUNCAO PARA COPIAR TODOS OS ELEMENTO DE UM
 * VETOR PARA UMA LISTA ENCADEADA
*/

#include <stdio.h>
#include <stdlib.h>


//DEFIFIR A NOSSA STRUCT LIST
typedef struct _node{
    int value;
    struct Node* next;
} Node;

// MOSTRAR OS ELEMENTOS DA LISTA
void printList(Node* head){
    printf("List = [ ");
    while (head != NULL){
        printf(" %d ", head->value);
        head = head->next;
    }
    printf(" ]\n");
}

// FUNCAO PARA COPIAR UM VECTOR NUMA LISTA ENCADEADA
Node* copyArrayToList(int vetor[], int sizeVetor){
    Node* head = NULL;
    Node* tail = NULL;
    
    // interrar sobe os vector e criar um no para cade elemento do vector
    for (int i = 0; i < sizeVetor; i++){
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode ==NULL){
            perror("Erro ao alocar a memoria.");
            exit(EXIT_FAILURE);
        }
        newNode->value = vetor[i];
        newNode->next = NULL;

        if (head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        } 
    }
    return head;
}

// FUNCAO PARA COPIAR UM VECTOR NUMA LISTA ENCADEADA
Node* copyArrayToListRecursiveAuxiliar(int vetor[], int index, int sizeVetor){
    if(index >= sizeVetor) return NULL;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode ==NULL){
        perror("Erro ao alocar a memoria.");
        exit(EXIT_FAILURE);
    }

    newNode->value = vetor[index];
    newNode->next = copyArrayToListRecursiveAuxiliar(vetor, index+1, sizeVetor);
    
    return newNode;
}
Node* copyArrayToListRecursive(int vetor[], int sizeVetor){
    return copyArrayToListRecursiveAuxiliar(vetor, 0, sizeVetor);
}



int main(int argc, char const *argv[]){
    int vetor[] = {12,5,6,56,4,356,3,21,31,263,36,2,3,213,63,453,623,6};
    int sizeVetor = sizeof(vetor)/sizeof(vetor[0]);

    Node* List = copyArrayToListRecursive(vetor, sizeVetor);

    printf("Mostrar a Lista Encadeada\n");
    printList(List);
    return 0;
}

