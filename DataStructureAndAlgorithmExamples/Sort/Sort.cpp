#include <iostream>
#include <vector>
using namespace std;

//quick sort
void QuickSort(vector<int>& array, int low, int high) {	
    if (low >= high) {	
        return;
    }
    int i = low;	
    int j = high;	
    int key = array[low];
    while (i < j) {
        while (array[j] >= key && i < j) {	
            j--;	
        }
        array[i] = array[j];	
        while (array[i] <= key && i < j) {	
            i++;	
        }
        array[j] = array[i];	
    }
    array[i] = key;	
    QuickSort(array, low, i - 1);	
    QuickSort(array, i + 1, high);	
}

//bubble sort
void bubbleSort(int a[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}
