#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define MAX_BUFFER_SIZE 100

typedef struct stack {
    int data;
    struct stack *next;
} stack;

void push(stack **head, int value){
    stack* node = malloc(sizeof(stack));

    if (node == NULL){
        fputs("error: out of memory\n", stderr);
        exit(1);
    }
    else{
        node->data = value;
        node->next = *head;
        *head = node;
    }
}

int pop(stack **head) {
    if(*head == NULL) {
        fputs("error: bottom of stack!\n", stderr);
        exit(1);
    }
    else{
        stack* top = *head;
        int value = top->data;
        *head = top->next;
        free(top);
        return value;
    }
}

int result(char opnn, stack** head){
    int tmp;
    switch(opnn) {
        case '+': return pop(head) + pop(head);
        case '*': return pop(head) * pop(head);
        case '-': tmp = pop(head); return pop(head) - tmp;
        case '/': tmp = pop(head); return pop(head) / tmp;
    }
    return 0;
}

int need(char opnn){
    switch(opnn) {
        case '+':
        case '*':
        case '-':
        case '/':
            return 2;
        default:
            fputs("invalid operator!!!", stderr);
            exit(1);
    }
}

int check(char* number){
    for( ; *number; number++){
        if(*number < '0' || *number > '9')
            return 0;
    }
    return 1;
}

int main(int argc, char** argv){
    if(argc == 1){
        printf("Usage: %s arg[arg] ...", argv[0]);
        exit(1);
    }
    int temp, stacksize = 0;
    stack* head = NULL;
    for(int i = 1; i < argc; i++) {
        char *token = argv[i];
        char op;
        if(check(token)) {
            temp = atoi(token);
            push(&head, temp);
            ++stacksize;
        }
        else {
            if(strlen(token) != 1) {
                fprintf(stderr, "error: token '%s' is too large.\n", token);
                exit(1);
            }
            op = token[0];
            if(stacksize < need(op)) {
                fputs("too few arguments on stack.\n", stderr);
                exit(1);
            }
            push(&head, result(op, &head));
            stacksize -= need(op) - 1;
        }
    }
    if(stacksize != 1) {
                fputs("too many arguments on stack.\n", stderr);
                exit(1);
    }
    printf("result: %d\n", head->data);
    return 0;
}