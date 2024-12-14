#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 200001

typedef struct Node {
    char data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
    int size;
} Pilha;

Pilha initstack() {
    Pilha s;
    s.top = NULL;
    s.size = 0;

    return s;
}

Node* create_node(char it, Node* nextvalue){
    Node* n = (Node*) malloc (sizeof(Node));

    n->data = it;
    n->next = nextvalue;

    return n;
}

int isEmpty(Pilha *stack) {
    return stack->top == NULL;
}

void push(Pilha *stack, char c) {

    stack->top = create_node(c, stack->top);
    stack->size++;
}


char pop(Pilha *stack) {
    if(stack->top == NULL){
        return -1;
    }

    char c = stack->top->data;
    stack->top = stack->top->next;
    stack->size--;

    return c; 

}

void clear(Pilha *stack) {
     while(stack->top != NULL){
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
     }
}

int main() {
    char string[MAXSIZE];

    fgets(string, sizeof(string), stdin);

    Pilha stack = initstack();


    int tam = strlen(string);

    for (int i = 0; i < tam; i++) {
        if (string[i] == 'C' && !isEmpty(&stack) && stack.top->data == 'B') {
            pop(&stack);
            if (!isEmpty(&stack) && stack.top->data == 'A') {
                pop(&stack);
            } else {
                push(&stack, 'B');
                push(&stack, 'C');
            }
        } else {
            push(&stack, string[i]);
        }
    }

    // Armazena os caracteres na ordem inversa em um array
    char reversed[MAXSIZE];
    int index = 0;
    while (!isEmpty(&stack)) {
        reversed[index++] = pop(&stack);
    }

    // Imprime os caracteres na ordem original
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", reversed[i]);
    }
    printf("\n");

    // Liberar a memória alocada para a pilha ligada
    clear(&stack);

    return 0;
}