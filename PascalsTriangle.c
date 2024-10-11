#include <stdio.h>
#include <stdlib.h>

//New type definition for llu
typedef unsigned long long ullong;

//Factorial function:
ullong fact(int a){
    if(a == 0){
        return 1;
    }

    ullong result = 1;
    for(int i=1; i<=a; i++){
        result *= i;
    }

    return result;
}

int main(){
    ullong **pascals_triangle = malloc(21 * sizeof (ullong *));
    if(pascals_triangle == NULL){
        fprintf(stderr, "ERROR ALOCATING MEMORY!");
        return 1;
    }

    for(int i=0; i<21; i++){
        pascals_triangle[i] = malloc((i+1) * sizeof (ullong));
        if(pascals_triangle[i] == NULL){
            fprintf(stderr, "ERROR ALOCATING MEMORY!");
            return 1;
        }
    }

    for(int i=0; i<21; i++){
        for (int j=0; j<=i; j++){
            pascals_triangle[i][j] = fact(i)/(fact(j)*fact(i-j));
            printf(" %llu", pascals_triangle[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<21; i++){
        free(pascals_triangle[i]);
    }

    free(pascals_triangle);

    return 0;
}
