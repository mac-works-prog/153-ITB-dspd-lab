#include <stdio.h>

int main() {
    int n, i, search, start, mid, high, found = 0;
    int arr[100];

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &search);

    start = 0;
    high = n - 1;

    while (start <= high) {
        mid = (start + high) / 2;

        printf("\nStart = %d, End = %d, Mid = %d\n", start + 1, high + 1, mid + 1);
        printf("Current array elements being searched: ");
        for (i = start; i <= high; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        if (arr[mid] == search) {
            printf("\nThe element %d is found at position %d.\n", search, mid + 1);
            found = 1;
            break;
        } else if (search < arr[mid]) {
            high = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    if (!found) {
        printf("\nThe element %d is not present in the array.\n", search);
    }

    return 0;
}