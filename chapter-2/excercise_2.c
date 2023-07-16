#include <stdio.h>

void function1(void) {
    printf("function 1 called!\n");
}

void function2(void){
    printf("function 2 called!\n");
}

void function3(void) {
    printf("function 3 called!\n");
}

int main(void) {
    void (*functions[3])(void);
    functions[0] = &function1;
    functions[1] = &function2;
    functions[2] = &function3;

    for(int i = 0; i < 3; i++) {
        (*functions[i])();
    }

    return 0;
}
