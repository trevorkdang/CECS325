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
        BigInt()
        {
            v.push_back(0);
        }

        BigInt(int n)
        {
            char digit;
            while (n > 9)
            {
                digit = n % 10;
                n /= 10;
                v.push_back(digit);
            }
            digit = n;
            v.push_back(digit);
        }

        BigInt(string str)
        {
            for (int i = str.size() - 1; i >= 0; i--)
            {
                v.push_back(str[i]);
            }
        }

        BigInt operator+(BigInt b)
        {
            BigInt res;
            int car = 0;
            int i = 0, j = 0;
            while (i < v.size() || j < b.v.size() || car > 0)
            {
                int sum = car;
                if (i < v.size())
                {
                    sum += v[i];
                }
                if (j < b.v.size())
                {
                    sum += b.v[j];
                }

                res.v.push_back(sum % 10);
                car = sum / 10;
                i++;
                j++;
            }
            return res;
        }

        BigInt operator++()
        {
            *this = *this + BigInt(1);
            return *this;
        }

        BigInt operator++(int)
        {
            BigInt temp(*this);
            *this = *this + BigInt(1);
            return temp;
        }

        BigInt operator*(BigInt b)
        {
            BigInt res;
            int car = 0;
            for (int i = 0; i < v.size(); i++)
            {
                car = 0;
                BigInt temp;
                for (int j = 0; j < i; j++)
                {
                    temp.v.push_back(0);
                }
                for (int j = 0; j < b.v.size(); j++)
                {
                    int ans = v[i] * b.v[j] + car;
                    temp.v.push_back(ans % 10);
                    car = ans / 10;
                }
                if (car > 0)
                {
                    temp.v.push_back(car);
                }
                res = res + temp;
            }
            return res;
        }

        BigInt half() const
        {
            BigInt res; // this is just the Bigint num
            int car = 0; // made a carry value
            for (int i = v.size() - 1; i >= 0; i--) //just a loop that goes through each digit in the BigINt
            {
                int cur = (v[i] + car * 10) /2;
                if (i != 0 || cur != 0)
                {
                    res.v.push_back(cur);
                }
                car = v[i] % 2;
            }
            return res;
        }
        bool isOdd() const
        {
            return v[0] % 2 != 0;
        }
        bool isEven() const
        {
            return v[0] % 2 == 0;
        }

        bool operator==(BigInt b) const
        {
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] != b.v[i])
                {
                    return false;
                }
            }
            return true;
        }

        bool operator<(BigInt b) const
        {
            if (v.size() > b.v.size())
            {
                return false;
            }
            for (int i = v.size() - 1; i >= 0; i--)
            {
                if (v[i] < b.v[i])
                {
                    return true;
                }
                if (v[i] > b.v[i])
                {
                    return false;
                }
            }
            return false;
        }

    friend ostream& operator<<(ostream& os, const BigInt& num)
    {
        for (int i = 0; i < num.v.size(); i++)
        {
            cout << (int)num.v[i];
        }
        return os;
    }

};



struct ThreeNp1
{
    BigInt start;
    BigInt steps;
    BigInt max;
    BigInt odd;
    BigInt even;
};

void print(ThreeNp1 temp)
{
    cout << "start:"<<temp.start<<endl;
    cout << "steps:"<<temp.steps<<endl;
    cout << "max:"<<temp.max<<endl;
    cout << "odd:"<<temp.odd<<endl;
    cout << "even:"<<temp.even<<endl;
}

void findThreeNp1(BigInt n, ThreeNp1& Np1, bool printSteps = false)
{
    if (printSteps)
    {
        cout << "->"<<'('<< n <<')';
    }
    
    if (Np1.max < n)
    {
        Np1.max = n;
    }

    if (n == BigInt(1))
    {
        return;
    }

    else if (n.isEven())
    {
        Np1.even++;
        Np1.steps++;
        findThreeNp1(n.half(), Np1, printSteps);
    }

    else if (n.isOdd())
    {
        Np1.odd++;
        Np1.steps++;
        BigInt tempN(n);
        findThreeNp1(n*BigInt(3)+BigInt(1), Np1, printSteps);
    }

    else
    {
        cout << "How the hell did I get here?\n";
        return;
    }
}

int main()
{
    BigInt MAX(INT_MAX);
    cout << "The Largest integer is " << MAX << endl;
    cout << "Twice the largest integer is " << MAX + MAX << endl;
    BigInt start(12);
    bool printSteps = false;
    ThreeNp1 N = {start, 0, 0, 0, 0};
    findThreeNp1(start, N, printSteps);
    cout << endl;
    print(N);

    return 0;
}
