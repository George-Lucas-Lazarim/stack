#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stackNode {
    int data;
    struct stackNode* next;
};

struct stackNode* push (struct stackNode* stack, int data);
int pop (struct stackNode** stack);
int peek (struct stackNode* stack);
bool isEmpty (struct stackNode* stack);
void clearStack (struct stackNode** stack);
int getStackSize (struct stackNode* stack);

#endif