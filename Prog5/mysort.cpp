//	Trevor Dang
//	CECS 325-02
//	Prog 5 - Sorting Contest using Threads
//	03/21/2023
//
//	I certify that this program is my own original work. I did not copy any part of this program 
//	from any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <thread>
using namespace std;

int partition(int arr[], int left, int right)
{
    int pivot = arr[left];

    int count = 0;
    for (int i = left + 1; i < right; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotIdx = left + count;
    swap(arr[pivotIdx], arr[left]);
    
    int i = left, j = right;
    while (i < pivotIdx && j > pivotIdx)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
            
        }
        if (i < pivotIdx && j > pivotIdx)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIdx;
}

//quick sort function 
void quickSort(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int p = partition(arr, left, right);

    quickSort(arr, left, p - 1);

    quickSort(arr, p + 1, right);

}

void merge(int *arr, int left, int mid, int right)
{
    int i = left;
    int j = mid;
    int k = 0;
    int *temp = new int[right - left + 1];
    
    while (i < mid && j < right)
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

    while (j < right)
    {
        temp[k++] = arr[j++];
    }

    for (int x = left, y = 0; x < right; x++, y++)
    {
        arr[x] = temp[y];
    }
    delete [] temp;
}


int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cerr << "Usage: " << argv[0] << " Input Output" << endl;
        return 1;
    }


    ifstream ifile(argv[1]); //input file
    if (!ifile.is_open())
    {
        cerr << "Cannot open input file" << argv[1] << endl;
    }

    int numbers[1000000]; //array in file that can hold 1 million numbers
    int count = 0; //counter to keep track of numbers input file
    int nums;
    

    while (ifile >> nums && count < 1000000) //while loop that makes sure number of inputs not more than 1 million
    {
        numbers[count] = nums;
        count++;
        if (count > 1000000)
        {
            cerr << "Input file contains too many numbers" << endl;
            return 1;
        }
    }
    ifile.close();
    


    int sizeArr = count;
    int size = sizeArr/8;

    /*for (int i = 0; i < 8; i++)
    {
        argList[i].arrSize = size;

        if (i == 0)
        {
            argList[i].array = numbers;
        }
        else
        {
            argList[i].array = argList[i-1].array + argList[i].arrSize;
        }

        argList[i].wait = rand()%8;
    }*/

    thread thread1 (quickSort, numbers, 0, size - 1);
    thread thread2 (quickSort, numbers, size, 2 * size - 1);
    thread thread3 (quickSort, numbers, 2 * size, 3 * size - 1);
    thread thread4 (quickSort, numbers, 3 * size, 4 * size - 1);
    thread thread5 (quickSort, numbers, 4 * size, 5 * size - 1);
    thread thread6 (quickSort, numbers, 5 * size, 6 * size - 1);
    thread thread7 (quickSort, numbers, 6 * size, 7 * size - 1);
    thread thread8 (quickSort, numbers, 7 * size, sizeArr - 1);

    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    thread5.join();
    thread6.join();
    thread7.join();
    thread8.join();


    int subSize = size;

    for (int i = 0; i < 8; i+=2)
    {
        merge(numbers, (i)*(subSize), (i+1)*(subSize), (i+2)*(subSize));
    }

    for (int j = 0; j < 4; j+=2)
    {
        merge(numbers, (j)*(2)*(subSize), (j+1)*(2)*(subSize), (j+2)*(2)*(subSize));
    }

    merge(numbers, 0, (4)*(subSize), (8)*(subSize));


    /*ofstream ofile(argv[2]); //output file that holds sorted array
    if (!ofile.is_open())
    {
        cerr << "Cannot open output file" << argv[2] << endl;
    }*/

    for (int i = 0; i < sizeArr - 1; i++)
    {
        //ofile << numbers[i] << endl;
        cout << numbers[i] << endl;
    }
    //ofile << numbers[sizeArr - 1];
    
    cout << numbers[sizeArr - 1];
    // ofile.close();
    return 0;

}


