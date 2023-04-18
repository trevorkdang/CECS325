//	Trevor Dang
//	CECS 325-02
//	Prog 5 - Sorting Contest using Threads
//	04/05/2023
//
//	I certify that this program is my own original work. I did not copy any part of this program 
//	from any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include <mutex>
using namespace std;

//partition function that then plugs into the quicksort function
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

//quicksort function that uses recursion to sort the array
void quickSort(int arr[], int left, int right) 
{
    if (left < right) 
    {
        int p = partition(arr, left, right); //aka the pivot

        quickSort(arr, left, p - 1);

        quickSort(arr, p + 1, right);
    }
}

//merge function that merges the sections back into one large array
void merge(int* arr, int left, int mid, int right)
{
    int i = left;
    int j = mid;
    int k = 0;
    int l = right - left + 1; //temp index
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
    ifstream infile(argv[1]);//opens the input file

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
    thread threads[num_threads];//initializes the threads

    for (int i = 0; i < num_threads; i++) //loop that goes through each thread and sorts it individually
    {
        int left = i * subSize;
        int right = (i + 1)*(subSize) - 1;

        if (i == num_threads - 1) {
            right = count - 1;
        }

        threads[i] = thread(quickSort, numbers, left, right);
    }

    for (int i = 0; i < num_threads; i++) //joins all the threads back together
    {
        threads[i].join();
    }

    int merge_num = subSize;
    while (merge_num < count) //while loops that makes sure the # of numbers in the subSize arrays are less than the total number inputed
    {
        for (int i = 0; i < count; i += (2)*(merge_num)) 
        {
            int left = i;
            int mid = i + merge_num;
            int right = min(i + (2)*(merge_num) - 1, count - 1);
            
            merge(numbers, left, mid, right); //merge function that uses a left, middle, and right bound to merge the numbers into one large sorted array
        }
        merge_num *= 2;
    }

    for (int i = 0; i < count; i++) 
    {
        cout << numbers[i] << "\n"; //sends the values to stdout
    }

    return 0;
}



