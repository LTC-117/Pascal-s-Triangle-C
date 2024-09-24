#include <stdio.h>
#include <stdlib.h>

//Variables:
int num;

//Functions:
long long int fact(int a){ //Factorial function.
    if(a == 0){
        return 1;
    }

    long long int result = 1;
    for(int i=1; i<=a; i++){
        result *= i;
    }
    
    return result;
}

int main(){
    int **face = (int **)malloc(21 * sizeof (int *));
        for(int i=0; i<21; i++){
            face[i] = (int *)malloc((i+1) * sizeof (int));
        }

    for(int i=0; i<21; i++){
        for (int j=0; j<=i; j++){
            face[i][j] = fact(i)/(fact(j)*fact(i-j)); //Combination 'C(i, j)', that defines each element of the triangle.
            printf(" %d", face[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<21; i++){
        free(face[i]);
    }

    free(face);

    return 0;
}
