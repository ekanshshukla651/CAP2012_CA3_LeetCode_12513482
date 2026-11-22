#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} MyStack;

MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));

    stack->capacity = 100;
    stack->arr = (int*)malloc(stack->capacity * sizeof(int));
    stack->front = 0;
    stack->rear = -1;
    stack->size = 0;

    return stack;
}

void myStackPush(MyStack* obj, int x) {
    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->arr[obj->rear] = x;
    obj->size++;

    int n = obj->size;

    for (int i = 0; i < n - 1; i++) {
        int frontElement = obj->arr[obj->front];
        obj->front = (obj->front + 1) % obj->capacity;

        obj->rear = (obj->rear + 1) % obj->capacity;
        obj->arr[obj->rear] = frontElement;
    }
}

int myStackPop(MyStack* obj) {
    int top = obj->arr[obj->front];
    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;

    return top;
}

int myStackTop(MyStack* obj) {
    return obj->arr[obj->front];
}

bool myStackEmpty(MyStack* obj) {
    return obj->size == 0;
}

void myStackFree(MyStack* obj) {
    free(obj->arr);
    free(obj);
}
