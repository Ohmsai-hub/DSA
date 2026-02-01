//Insert an Element in an Array
#include <stdio.h>

int main() {
    int n, pos, x;
    
    // Input size of array
    scanf("%d", &n);
    
    int arr[100];  // assuming max size 100 for simplicity
    
    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input position and element
    scanf("%d", &pos);
    scanf("%d", &x);
    
    // Validate position
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position\n");
        return 0;
    }
    
    // Shift elements to the right
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert element
    arr[pos - 1] = x;
    n++;  // array size increases
    
    // Print updated array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}
