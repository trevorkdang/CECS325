//	Trevor Dang
//	CECS 325-02
//	Prog 5 - Sorting Contest using Threads
//	04/05/2023
//
//	I certify that this program is my own original work. I did not copy any part of this program 
//	from any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <mutex>
using namespace std;

int partition(int arr[], int left, int right) 
{
    int pivot = arr[right];
    int l = left - 1;

    for (int i = left; i <= right - 1; i++) 
    {
        if (arr[i] < pivot) 
        {
            l++;
            swap(arr[l], arr[i]);
        }
    }
    swap(arr[l + 1], arr[right]);
    return (l + 1);
}

void quickSort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        int p = partition(arr, left, right);

        quickSort(arr, left, p - 1);

        quickSort(arr, p + 1, right);
    }
}

void merge(int* arr, int left, int mid, int right)
{
    int i = left;
    int j = mid;
    int k = 0;
    int l = right - left + 1;
    int *temp = new int[l];
    
    while (i < mid && j <= right)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i < mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (int i = 0; i < l; ++i)
    {
        arr[left + i] = temp[i];
    }
    delete [] temp;
}



int main(int argc, char* argv[]) 
{
    ifstream infile(argv[1]);
    
    const int max_num = 1000000;
    const int num_threads = 8;
    int numbers[max_num];
    int count = 0;
    int num;

    while (infile >> num) 
    {
        numbers[count++] = num;
    }
    infile.close();

    int subSize = count / num_threads;
    thread threads[num_threads];

    for (int i = 0; i < num_threads; i++) 
    {
        int left = i * subSize;
        int right = (i + 1)*(subSize) - 1;

        if (i == num_threads - 1) {
            right = count - 1;
        }

        threads[i] = thread(quickSort, numbers, left, right);
    }

    for (int i = 0; i < num_threads; i++) 
    {
        threads[i].join();
    }

    int merge_num = subSize;
    while (merge_num < count) 
    {
        for (int i = 0; i < count; i += (2)*(merge_num)) 
        {
            int left = i;
            int mid = i + merge_num;
            int right = min(i + (2)*(merge_num) - 1, count - 1);
            
            merge(numbers, left, mid, right);
        }
        merge_num *= 2;
    }

    for (int i = 0; i < count; i++) 
    {
        cout << numbers[i] << "\n";
    }

    return 0;
}



