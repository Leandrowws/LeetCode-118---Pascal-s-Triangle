#include<stdio.h>
#include<stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);

    int **triangulo = (int**)malloc(sizeof(int*) * numRows);
    
    for(int i = 0; i < numRows; i++) {

        (*returnColumnSizes)[i] = i + 1;

        int *linha = (int*)malloc(sizeof(int) * (i + 1));

        for(int j = 0; j < i + 1; j++) {

            if(j == 0 || j == i) {
                linha[j] = 1;
            } 
            else {
                linha[j] = triangulo[i-1][j-1] + triangulo[i-1][j];
            }
        }

        triangulo[i] = linha;
    }

    return triangulo;
}


int main() {
    
    int returnSize;
    int *returnColumnSizes;
    int **triangulo = generate(5, &returnSize, &returnColumnSizes);


    for(int i=0; i<5; i++) {
        for(int j=0; j<i+1; j++)
            printf("%d", triangulo[i][j]);
        printf("\n");
    }

    for(int i=0; i<5; i++) {
        free(triangulo[i]);
    }

    
    free(triangulo);
    free(returnColumnSizes);
    

    return 0;
}
