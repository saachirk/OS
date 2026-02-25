// Write a program in C to count the total number of duplicate elements in an array.

#include <stdio.h>
#define N 5

int main(){
    int arr[N],i,j,count;
    printf("Enter elements of array : ");
    for(i = 0 ; i < N ; i++){
       scanf("%d", &arr[i]);
    }

    for(i = 0 ; i < N; i++){
        for(j = i+1 ; j < N; j++){
            if(arr[i] == arr[j]){
                count++;
                break;
            }
        }
    }
    printf("Total number of duplicate entries is : %d",count);
}
