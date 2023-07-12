#include <stdio.h>
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int j,i = (low - 1);
    for (j = low; j <= high - 1; j++) {
         if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int piv = partition(arr, low, high);
        quickSort(arr, low, piv - 1);
        quickSort(arr, piv + 1, high);
    }
}
int main()
{ 
    int i,N;
    printf("Enter the Array Size:");
    scanf("%d",&N);
    int arr[N];
    printf("Enter the elements:\n");
    for(i=0;i<N;i++){
    	scanf("%d",&arr[i]);
	}
    quickSort(arr, 0, N - 1);
    printf("Sorted array: \n");
    for (i = 0; i < N; i++)
        printf("%d ", arr[i]);
    return 0;
}
