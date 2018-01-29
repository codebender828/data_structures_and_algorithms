//
// Created by Jonathan Bakebwa on 29/01/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i, rows, columns, nonZeroNumbers;
    scanf("%d %d %d", &rows, &columns, &nonZeroNumbers);
    int matrix[100][3], num[100], cpot[100], output[100][3], col, q;

    memset(num, 0, sizeof(num));
    for(i = 1; i <= nonZeroNumbers; i++){
        scanf("%d %d %d", &matrix[i][0], &matrix[i][1], &matrix[i][2]);
        num[matrix[i][1]]++;
    }
    printf("num:");

    for(i = 1; i < columns; i++){
        printf("%d", num[i]);
    }
    printf("\n");
    printf("cpot:1,");
    cpot[1] = 1;

    for(i = 2; i <= nonZeroNumbers; i++){
        col = matrix[i][1];
        q = cpot[col];
        output[q][0] = matrix[i][1];
        output[q][1] = matrix[i][0];
        output[q][2] = matrix[i][2];
        ++cpot[col];
    }
    for(i = 1; i <= nonZeroNumbers; i++)
        printf("%d,%d,%d\n", output[i][0], output[i][1], output[i][2]);

}
