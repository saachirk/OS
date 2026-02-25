// Write a program in C to find the sum of the left diagonals of a matrix.

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
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < N; j++){
            if(i > j){
                sum = sum + arr[i][j];
            }
        }
    }
    printf("The sum of left diagonal is : %d",sum);
}