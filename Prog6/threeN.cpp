//	Trevor Dang
//	CECS 325-02
//	Prog 6 - 3N + 1
//	04/05/2023
//
//	I certify that this program is my own original work. I did not copy any part of this program 
//	from any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <vector>
using namespace std;

struct Stats
{
    int start = 0;
    int steps = 0;
    int max = 0;
    int evens = 0;
    int odds = 0;
};

void rec(int n, Stats& stats)
{
    if (n <= 0)
    {
        return;
    }

    if (n > stats.max)
    {
        stats.max = n;
    }

    if (n == 1)
    {
        stats.steps++;
        stats.odds;
        return;
    }

    stats.steps;

    if (n % 2 == 0)
    {
        stats.evens++;
        int even = n/2;
        rec(even, stats);
    }
    else
    {
        stats.odds++;
        int odd = (3*n)+1;
        if (odd < n)
        {
            throw "Overflow error";
        }
        rec(odd, stats);
    }
}

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        int n;
        cout << "Enter a 3n+1 candidate number: ";
        cin >> n;

        Stats stats;

        if (n <= 0)
        {
            cerr << "Invalid Input" << endl;
            return 0;
        }

        try
        {
            rec(n, stats);
        }
        catch(const char* msg)
        {
            cerr << "Solving 3n+1 - starting value:" << n << endl;
            cerr << "->(" << n << ") " << msg << endl;
            return 0;
        }

        cout << "->(" << n << ")\n"
            << "start:" << n << "\n"
            << "steps:" << n << "\n"
            << "max:" << n << "\n"
            << "odds:" << n << "\n"
            << "evens:" << n << endl;
    }
    else
    {
        Stats stats;
        int max = INT_MIN;
        int odds = 0;
        int evens = 0;

        for (int i = 1; i < argc; i++)
        {
            int n = stoi(argv[i]);

            if (n <= 0)
            {
                cerr << "Invalid Input" << endl;
                continue;
            }

            try
            {
                rec(n, stats);
            }
            catch(const char* msg)
            {
                cerr << "Solving 3n+1 - starting value:" << n << endl;
                cerr << "->(" << n << ") " << msg << endl;
                continue;
            }

            if (n > max)
            {
                max = n;
            }

            cerr << "Solving 3n+1 - starting value:" << n << endl;
            cerr << "->(" << n << ") " << endl;
            
            cout << "start:" << n << "\n"
                << "steps:" << stats.steps << "\n"
                << "max:" << stats.max << "\n"
                << "odds:" << stats.odds << "\n"
                << "evens:" << stats.evens << endl;
        }
    }
    return 0;

    
}