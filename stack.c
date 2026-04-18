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
    struct stackNode* currentNode = *stack;
    struct stackNode* nextNode;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }

    *stack = NULL;
}

int getStackSize (struct stackNode* stack) {
    int count = 0;
    while (stack != NULL) {
        count++;
        stack = stack->next;
    }

    return count;
}

void printStack (struct stackNode* stack) {
    while (stack != NULL) {
        printf("%d -> ", stack->data);
        stack = stack->next;
    }
    printf("NULL");
}

void reverseStack (struct stackNode** stack) {
    struct stackNode* prevNode = NULL;
    struct stackNode* currentNode = *stack;
    struct stackNode* nextNode;

    while (currentNode != NULL) {
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }

    *stack = prevNode;
}