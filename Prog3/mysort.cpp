//	Trevor Dang
//	CECS 325-02
//	Prog 3 - Sorting Contest
//	03/07/2023
//
//	I certify that this program is my own original work. I did not copy any part of this program 
//	from any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
using namespace std;

//bubble sort function without using swap and used a temp var instead
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
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


int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cerr << "Usage: " << argv[0] << "Input Output" << endl;
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

    bubbleSort(numbers, count); //runs bubble sort

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
