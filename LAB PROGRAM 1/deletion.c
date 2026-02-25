//Write a program in C to delete an element at a desired position from an array.

#include <stdio.h>

int main() {
    int n, pos;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    if(pos < 1 || pos > n) {
        printf("Invalid position!\n");
    } else {
        // Shift elements to the left
        for(int i = pos - 1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        n--;  // Reduce size of array

        printf("Array after deletion:\n");
        for(int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}