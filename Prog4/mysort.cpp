//	Trevor Dang
//	CECS 325-02
//	Prog 4 - Sorting Contest (pthread)
//	03/07/2023
//
//	I certify that this program is my own original work. I did not copy any part of this program 
//	from any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <pthread.h>
using namespace std;

struct list {
    int *arr; 
    int arrSize; 
    int wait; 
};

//bubble sort function without using swap and used a temp var instead
void *bubbleSort(void *arr)
{
    list *arg = (list *) arr
    int *arr = arg->arr;
    int arrSize = arg->arrSize;
    int wait = arg->wait;

    
    for (int i = 0; i < arrSize-1; i++)
    {
        for (int j = 0; j < arrSizze-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid;
    int k = 0;
    int temp[right - left];
    
    while (i < mid && j < right)
    {
        if arr[i] <= arr[j]
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i < mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j < right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int x = 0; x < k; x++)
    {
        arr[left + x] = temp[x];
    }
}


int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cerr << "Usage: " << argv[0] << "Input Output" << endl;
        return 1;
    }

    pthread_args argList[8];
    /*for (int i = 0; i < 4; i++)
    {
        argList[i].arr = arr[i];
        argList[i].left = l
        argList[i].right = r
    }*/

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

    int sizeArr = nums;
    int size = nums/8;

    for (int i = 0; i <8; i++)
    {
        argList[i].arrSize = size;
        if (i == 0)
        {
            argList[i].arr = numbers;
        }
        else
        {
            argList[i].arr = argList[i-1].arr + argList[i].arrSize;
        }
        argList[i].wait = rand()%8;
    }


    pthread_t thread0, thread1, thread2, thread3, thread4, thread5, thread6, thread7;
    int iret0, iret1, iret2, iret3, iret4, iret5, iret6, iret7;
    
    iret0 = pthread_create(&thread0, NULL, bubbleSort, (void*) &argList[0]);
    iret1 = pthread_create(&thread1, NULL, bubbleSort, (void*) &argList[1]);
    iret2 = pthread_create(&thread2, NULL, bubbleSort, (void*) &argList[2]);
    iret3 = pthread_create(&thread3, NULL, bubbleSort, (void*) &argList[3]);
    iret4 = pthread_create(&thread4, NULL, bubbleSort, (void*) &argList[4]);
    iret5 = pthread_create(&thread5, NULL, bubbleSort, (void*) &argList[5]);
    iret6 = pthread_create(&thread6, NULL, bubbleSort, (void*) &argList[6]);
    iret7 = pthread_create(&thread7, NULL, bubbleSort, (void*) &argList[7]);

    pthread_join(thread0, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);
    pthread_join(thread6, NULL);
    pthread_join(thread7, NULL);

    int subArrSize = argList[1].arrSize;

    for (int i = 0; )


    

    ofstream ofile(argv[2]); //output file that holds sorted array
    if (!ofile.is_open())
    {
        cerr << "Cannot open output file" << argv[2] << endl;
    }

    for (int i = 0; i < count; i++)
    {
        ofile << numbers[i] << endl;
    }

    ofile.close();
    return 0;

}
