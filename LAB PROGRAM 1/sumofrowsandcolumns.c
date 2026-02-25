//Write a program in C to find the sum of rows and columns of a matrix.

#include <stdio.h>
#define N 3

int main(){
    int i;
    int arr[N][N];
    printf("Enter elements of array : ");
    for(i = 0; i < N; i++){
        for(int j = 0; j < N ;j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int sum = 0;
    for(i = 0; i<N; i++){
        for(int j = 0; j < N;j++){
            sum = sum + arr[i][j];
        }
        printf("\nThe sum of row %d is %d",(i+1),sum);
        sum = 0;
    }

    for(int j = 0 ; j < N; j++){
        for(i = 0 ; i < N; i++){
            sum = sum + arr[i][j];
        }
        printf("\nThe sum of column %d is %d",(j+1),sum);
        sum = 0;
    }
}