//	Trevor Dang
//	CECS 325-02
//	Prog 6 - 3N + 1
//	04/18/2023
//
//	I certify that this program is my own original work. I did not copy any part of this program 
//	from any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <vector>
using namespace std;

class BigInt
{
    private:
        vector<char> v;
    public:
        BigInt();
        BigInt
}

struct Stats //uses struct to hold all the variables
{
    int start = 0;
    int steps = 0;
    int max = 0;
    int evens = 0;
    int odds = 0;
    int current = 0;
};

void rec(int n, int current, Stats& stats) //recursion function 
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
        return;
    }

    stats.steps++; //increments steps each time an operation is performed on n
    stats.current = current; //current variable that keeps track of the number being calculated on

    if (n % 2 == 0) //calculates if the number is even and divides it if true, then applies recursion
    {
        stats.evens++;
        int even = n/2;
        cout << "->(" << even << ")";
        rec(even, even, stats);
    }
    else //if the number is odd then mulitplies by 3 and adds 1, then applies recursion
    {
        stats.odds++;
        int odd = (3*n)+1;
        if (odd < n)
        {
            throw "overflow detected for n:"; //throw
        }
        cout << "->(" << odd << ")";
        rec(odd, odd, stats);
    }
}


int main(int argc, char* argv[])
{
    vector<Stats> stat_Vec;
    //int max = INT_MAX;
    int odds = 0;
    int evens = 0;

    if (argc == 1) //used if no command line parameters are inputted 
    {
        int n;
        cout << "Enter a 3n+1 candidate number: ";
        cin >> n; //user input
        cout << "->(" << n << ")";

        Stats stats;

        if (n <= 0)
        {
            cerr << "Invalid Input" << endl;
            return 0;
        }

        try
        {
            rec(n, n, stats);//tries the recursion function and sees if there is an error, with throw already implemented into the recursion function
        }
        catch(const char* msg) //catch function pops if an overflow occurs and uses the throw string to print out an error
        {
            cerr << "->(###overflow###)" << endl;
            cerr << msg << stats.current << endl;
            cerr << "3n+1:" << stats.current * 3 + 1 << endl;
            cerr << "something broke dude\noverflow" << endl;
            return 0;
        }

        stats.start = n;
        stat_Vec.push_back(stats);

        cout << endl;
        cout << "start:" << n << endl;
        cout << "steps:" << stats.steps << endl;
        cout << "max:" << stats.max << endl;
        cout << "odds:" << stats.odds << endl;
        cout << "evens:" << stats.evens << endl;
    }

    else
    {
        for (int i = 1; i < argc; i++)//if there is more than one command line parameter
        {
            int n = stoi(argv[i]);
            cout << "\nSolving 3n+1 - starting value:" << n << endl;
            cout << "->(" << n << ")";

            if (n <= 0)
            {
                cerr << "Invalid Input" << endl;
                continue;
            }

            Stats stats;

            try
            {
                rec(n, n, stats);//again uses try to run the recursion and checks for error
            }
            catch(const char* msg)//again catch is implemented 
            {
                //cerr << "Solving 3n+1 - starting value:" << n << endl;
                cerr << "->(###overflow###)" << endl;
                cerr << msg << stats.current << endl;
                cerr << "3n+1:" << stats.current * 3 + 1 << endl;
                cerr << "something broke dude\noverflow" << endl;
                continue;
            }

            stats.start = n;
            stat_Vec.push_back(stats);

            if (n > stats.max)
            {
                stats.max = n;
            }

            /*cerr << "Solving 3n+1 - starting value:" << n << endl;
            cerr << "->(" << n << ") " << endl;*/
            cout << endl;
            cout << "start:" << n << endl;
            cout << "steps:" << stats.steps << endl;
            cout << "max:" << stats.max << endl;
            cout << "odds:" << stats.odds << endl;
            cout << "evens:" << stats.evens << endl;
            
        }
    }

    return 0;
}
