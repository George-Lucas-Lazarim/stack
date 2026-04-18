#include "stack.h"
#include <time.h>

int main() {
    int n;
    struct stackNode* stack = NULL;

    printf("\nEnter the number of random elements you want to insert into the stack: ");
    scanf("%d", &n);

    srand(time(NULL));
    for (int i=0; i < n; i++) {
        stack = push(stack, rand() % 1000);
    }

    if (!isEmpty(stack)) printf("\nRandom element assignment worked!");
    else {
        printf("\nRandom element assignment didn't work");
        return 0;
    }

    printf("\nPrinting the stack with %d elements: ", getStackSize(stack));
    printStack(stack);

    printf("\nRemoving the first element from the stack and then peeking: ");
    printf("\nElement removed: %d", pop(&stack));
    printf("\nNew first element: %d", peek(stack));
    printf("\nPrinting again: ");
    printStack(stack);
    printf("\nReversing the stack: ");
    reverseStack(&stack);
    printStack(stack);
    printf("\nDeleting random list... ");
    clearStack(&stack);
    printf("Deleted!\n");

    return 0;
}