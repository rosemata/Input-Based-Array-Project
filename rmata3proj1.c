#include <stdio.h>
#include <stdlib.h>

// function that will make a copy the values from one array to another array
void arrayCopy (int fromArray[], int toArray[], int size) {
    if (size > 0) { // check if array is not empty
        printf("Array Copy: ");
        for (int i = 0; i < size; ++i) {
            toArray[i] = fromArray[i];
        }
    }    

    else {
        printf("Array empty");
    }
}

// function that will sort an array in ascending order
void myFavorateSort (int arr[], int size) {
    if (size > 0) { // check if array is not empty
    printf("Array Sort: ");
        for (int i = 0; i < size-1; i++) {
            if (arr[i] > arr[i+1]) {    // if true
                int val = arr[i];   // swap value
                arr[i] = arr[i+1];
                arr[i+1] = val;
                i = -1; // begin from original position
            }
        }
        // print the values
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else {
        printf("Array empty");
    }
}

// function that will perform a linear search on an array with the given target value
void linSearch (int arr[], int size, int target, int* pos, int* numComparisons) {
    *numComparisons = 0;
    int found = 0;
    for (int i = 0; i < size; i++) {
        *numComparisons = *numComparisons + 1; // keep track how many comparisons needed
        if (arr[i] == target) { // compare current value to target value
            *pos = i;
            i = size;
            found = 1;
        }
    }
    if (found == 1) { // if found
        printf("Target %d: Found!\n", target);
        printf("Number Comparisons: %d\n", *numComparisons);
        printf("Position: %d\n", *pos);
    }
    else { // not found
        printf("Target %d: Not Found!\n", target);
    }
}


// function that will perform a binary search on an array with the given target value
void binSearch (int arr[], int size, int target, int* pos, int* numComparisons) {
    int l = 0;
    int r = size - 1;
    int found = 0; // keep track if value found/not found

    *numComparisons = 0;
    while (l <= r) {
        *numComparisons = *numComparisons + 1; // keep track how many comparisons needed
        int mid = (l + r) / 2; // divide in half Array Copy: 21 43 90 85 34 32 
        
        if (arr[mid] == target) { // if target found end loop
            *pos = mid;
            found = 1;
            l = size;
        }
        if (target < arr[mid]) { // decreases right size by 1
            r = mid - 1; // 6 5 4 3 2 1
        }               
        else {  // increase left side by 1
            l = mid + 1; // 0 1 2 3 4 5 6
        }
    }

    if (found == 1) { // if found 
        printf("Target %d: Found!\n", target);
        printf("Number Comparisons: %d\n", *numComparisons);
        printf("Position: %d\n", *pos);
    }
    else { // not found
        printf("Target %d: Not Found!\n", target);
    }
}

int main () {
    int *fromArray; // This pointer will hold the address of the array created
    int size = 100; 
    int num_elements = 0;
    fromArray = (int *) malloc (size * sizeof(int) ); // allocate 100 bytes of memory
    // Read in a list of integers from standard input
    int val;
    scanf("%d", &val);
    while (val != -999) {
        // if reach size 100, double the size
        if (num_elements == size-1) {
            int *temp = fromArray;
            fromArray = (int *) malloc ( size * 2 * sizeof(int) ); int i;
            for ( i = 0 ; i < size ; i++)
            fromArray[i] = temp[i]; free (temp);
            size = size * 2;
        }
        // store those values into an array.
        if (val > -999) {
            fromArray[num_elements] = val;
            num_elements++;
        }
        scanf("%d", &val);
    }
    // int fromArray[size];
    int toArray[size];
    // Make a copy of that array
    arrayCopy(fromArray, toArray, num_elements);
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", toArray[i]);
    }
    printf("\n");
    // Sort the copy of the array
    myFavorateSort(toArray, num_elements);
    int target = 0;
    int pos = 0;
    int numComparisons = 0;
    scanf("%d", &target);
    // Read in a second list of integers from standard input, stop at -999
    // Do a linear search on that value in the unsorted array
    // Do a binary search on that value in the sorted array
    // Print out i. value found or not found 
    // Print out ii. How many comparisons were needed to determine found
    // Print out iii. Position was the value found in each array
    while (target != -999) {
        printf("Linear Search: ");
        linSearch (fromArray, num_elements, target, &pos, &numComparisons);
        printf("Binary Search: ");
        binSearch (toArray, num_elements, target, &pos, &numComparisons);
        scanf("%d", &target);
    }

    free(fromArray);

    return 0;
}