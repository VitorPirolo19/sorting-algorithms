#include <stdio.h>

void swap(int *a, int *b);
void quicksort(int array[], int length);
void quicksort_recursion(int array[], int start, int end);
int partition(int array[], int start, int end);

int main()
{
    int list[] = {5,9,1,3,7,6,4,4,2,8};
    int length = 10;

    quicksort(list, length);

    for(int i = 0; i < length; i++){
        printf("%d", list[i]);
    }

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int array[], int length)
{
    quicksort_recursion(array, 0, length -1);
}

void quicksort_recursion(int array[], int start, int end)
{
    if(start < end)
    {
    int pivot_index = partition(array, start, end);
    quicksort_recursion(array, start, pivot_index);
    quicksort_recursion(array, pivot_index +1, end);
    }
}

int partition(int array[], int start, int end)
{
    int pivot_value = array[start];
    int i = start -1;
    int j = end +1;

    while(1){

        do{
            i++;
        }while(array[i] < pivot_value);

        do{
            j--;
        }while(array[j] > pivot_value);
        if(i >= j){
            return j;
        }

        swap(&array[i], &array[j]);
    }
}