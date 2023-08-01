// Program finds maximum of all the integers in an array

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    // prompt input for number of elements
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    // create array
    int arr[n];

    // prompt user to input elements
    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    // display greatest integer in the array
    printf("The max value is %i.\n", max(arr, n));
}

// find the max value in array
int max(int array[], int n)
{
    int big = array[0];

    for (int i = 0; i < n - 1; i++)
    {
        // check for elements greater than big
        if (big < array[i + 1])
        {
            // change value of big to the bigger element
            big = array[i + 1];
        }
    }
    return big;
}
