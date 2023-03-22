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
    int *array; 
    int arrSize; 
    int wait; 
};

//bubble sort function without using swap and used a temp var instead
void *bubbleSort(void *arr)
{
    list *arg = (list *) arr;
    int *arrayL = arg->array;
    int arrSize = arg->arrSize;
    int wait = arg->wait;

    
    for (int i = 0; i < arrSize; i++)
    {
        for (int j = 0; j < arrSize-i-1; j++)
        {
            if (arrayL[j] > arrayL[j+1])
            {
                int temp = arrayL[j];
                arrayL[j] = arrayL[j+1];
                arrayL[j+1] = temp;
            }
        }
    }
    return NULL;
}

void merge(int *arr, int left, int mid, int right)
{
    int i = left;
    int j = mid;
    int k = 0;
    int *temp = new int[right - left];
    
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
        cerr << "Usage: " << argv[0] << "Input Output" << endl;
        return 1;
    }

    list argList[8];

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
    int size = count/8;

    for (int i = 0; i < 8; i++)
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

    int subSize = argList[1].arrSize;

    for (int i = 0; i < 8; i+=2)
    {
        merge(numbers, (i)*(subSize), (i+1)*(subSize), (i+2)*(subSize));
    }

    for (int j=0; j < 4; j+=2)
    {
        merge(numbers, (j)*(2)*(subSize), (j+1)*(2)*(subSize), (j+2)*(2)*(subSize));
    }

    merge(numbers, 0, (4)*(subSize), (8)*(subSize));


    ofstream ofile(argv[2]); //output file that holds sorted array
    if (!ofile.is_open())
    {
        cerr << "Cannot open output file" << argv[2] << endl;
    }

    for (int i = 0; i < sizeArr - 1; i++)
    {
        ofile << numbers[i] << endl;
    }
    ofile << numbers[sizeArr - 1];

    ofile.close();
    return 0;

}


