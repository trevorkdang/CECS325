#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 4)
    {
        cerr << "Usage: " << argv[0] << " Count Min Max" << endl;
        return 1;
    }
    
    for (int i = 0; i < argc; i++)
    {
        cout << argv[i] << endl;
    }
    //accepts 3 arguments
    int count = stoi(argv[1]);
    int min = stoi(argv[2]);
    int max = stoi(argv[3]);

    //generates an output file that holds all the pseudo random numbers
    ofstream ofile("numbers.dat"); 
    for (int i = 0; i < count; i++)
    {
        ofile << rand() % (max - min + 1) + min << endl;
    }
    ofile.close();
    return 0;

}