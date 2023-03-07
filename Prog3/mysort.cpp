//	Trevor Dang
//	CECS 325-02
//	Prog 3 - Sorting Contest
//	02/21/2023
//
//	I certify that this program is my own original work. I did not copy any part of this program 
//	from any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

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
    return 0;
}


const int max_nums = 1000000;

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cerr << "Usage: " << argv[0] << "Input Output" << endl;
    }

    ifstream ifile(argv[1]);
    if (!ifile.is_open())
    {
        cerr << "Failed to open input file" << argv[1] << endl;
    }

    int numbers[max_nums];
    int count  = 0;
    int nums;
    while (ifile >> num)
    {
        numbers[count] = nums;
        count++;
        if (count >= max_nums)
        {
            cerr << "Input file contains too many numbers" << endl;
        }
    }

    ifile.close()

    bubbleSort(numbers, count);

    ofstream ofile(argv[2]);
    if (!ofile.is_open())
    {
        cerr << "Failed to open output file" << argv[2] << endl;
    }

    for (int i = 0; i < count; i++)
    {
        ofile << numbers[i] << endl;
        cout << numbers[i] << endl;
    }

    ofile.close()
    return 0;

}
