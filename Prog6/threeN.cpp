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
    int large = INT_MAX;
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
        return;
    }

    stats.steps++;
    //cout << "->(" << n << ")";

    if (n % 2 == 0)
    {
        stats.evens++;
        int even = n/2;
        cout << "->(" << even << ")";
        rec(even, stats);
    }
    else
    {
        stats.odds++;
        int odd = (3*n)+1;
        if (odd < n)
        {
            throw "overflow detected for n:";
        }
        cout << "->(" << odd << ")";
        rec(odd, stats);
    }
}


int main(int argc, char* argv[])
{
    vector<Stats> stat_Vec;
    //int max = INT_MAX;
    int odds = 0;
    int evens = 0;

    if (argc == 1)
    {
        int n;
        cout << "Enter a 3n+1 candidate number: ";
        cin >> n;
        cout << "->(" << n << ")";

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
            cerr << "->(###overflow###)" << endl;
            cerr << msg << stats.max << endl;
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
        for (int i = 1; i < argc; i++)
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
                rec(n, stats);
            }
            catch(const char* msg)
            {
                //cerr << "Solving 3n+1 - starting value:" << n << endl;
                cerr << "->(###overflow###)\n" << endl;
                cerr << msg << n << endl;
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



/*
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

        cout << "->(" << n << ")\n";
        cout << "start:" << n << endl;
        cout << "steps:" << n << endl;
        cout << "max:" << n << endl;
        cout << "odds:" << n << endl;
        cout << "evens:" << n << endl;
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
            
            cout << "start:" << n << endl;
            cout << "steps:" << stats.steps << endl;
            cout << "max:" << stats.max << endl;
            cout << "odds:" << stats.odds << endl;
            cout << "evens:" << stats.evens << endl;
        }
    }
    return 0;

    
}*/