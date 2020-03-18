#include <stdio.h>
#include <time.h>

void funA() {
    int result = 0;

    for(int i = 1; i <= 100; i++) {
        result += i;    
    }

    printf("funA() %d \n", result);
}

void funB() {
    int result = 0;
    int i = 1;

    for(;i <= 100; i++) {
        result += i;
    }

   printf("funB() %d \n", result);
}

void funC() {
    printf("funC() %d\n", 101*50);
}

void time_taker(void (*f)()) {
    clock_t t;
    t = clock();
    (*f)();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;

    printf("fun took %f seconds to execute \n", time_taken);
}

int main() {
    
    time_taker(funA);
    time_taker(funB);
    time_taker(funC);

    
    return 0;
}


