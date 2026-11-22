#include <stdbool.h>
#include <stdlib.h>

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    int* stack = (int*)malloc(pushedSize * sizeof(int));
    int top = -1;
    int j = 0;

    for (int i = 0; i < pushedSize; i++) {
        stack[++top] = pushed[i];

        while (top >= 0 && stack[top] == popped[j]) {
            top--;
            j++;
        }
    }

    free(stack);

    return j == poppedSize;
}
