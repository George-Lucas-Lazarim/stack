#include "stack.h"

struct stackNode* push (struct stackNode* stack, int data) {
    struct stackNode* newNode = (struct stackNode*) malloc (sizeof(struct stackNode));
    newNode->data = data;
    newNode->next = stack;
    
    return newNode;
}

int pop (struct stackNode** stack) {
    if (*stack == NULL) {
        printf("Error! The stack is empty");
        return -1;
    } else {
        struct stackNode* tempNode = *stack;
        int popedData = tempNode->data;

        *stack = tempNode->next;
        free(tempNode);

        return popedData;
    }
}

int peek (struct stackNode* stack) {
    if (stack != NULL) return stack->data;
    else {
        printf("Error! The stack is empty");
        return -1;
    }
}

bool isEmpty (struct stackNode* stack) {
    if (stack == NULL) return true;
    else return false;
}

void clearStack (struct stackNode** stack) {
    struct stackNode* currentNode;
    struct stackNode* freeNode = *stack;

    while (currentNode != NULL) {
        currentNode = freeNode->next;
        free(freeNode);
        freeNode = currentNode;
    }

    *stack = NULL;
}