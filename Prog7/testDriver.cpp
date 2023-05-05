//	Trevor Dang
//	CECS 325-02
//	Prog 7 - 3N + 1 (BigInt)
//	05/04/2023
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
            char dig;
            while (n > 9)
            {
                dig = n % 10;
                n /= 10;
                v.push_back(dig);
            }
            dig = n;
            v.push_back(dig);
        }
        BigInt(string s)
        {
            for (char c : s)
            {
                if (isdigit(c))
                {
                    v.push_back(c);  
                }
                    
            }
            if (v.empty())
            {
                v.push_back(0);
            }
                
        }


        BigInt operator+(BigInt a) 
        {
            BigInt res;
            char car = 0;
            char dig = 0;
            int i = 0;
            res.v.clear();

            while (i < min(v.size(), a.v.size()))
            {
                car += v[i] + a.v[i];
                dig = car % 10;
                res.v.push_back(dig);
                car = car / 10; 
                i++;
            }
            while (i < v.size())
            {
                car += v[i];
                dig = car % 10;
                res.v.push_back(dig);
                car = car / 10;
                i++;
            }
            while (i < a.v.size())
            {
                car += a.v[i];
                dig = car % 10;
                res.v.push_back(dig);
                car = car / 10;
                i++;
            }
            if (car > 0)
            {
                res.v.push_back(car);
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
            BigInt temp = *this;
            *this = *this + BigInt(1);
            return temp;
        }

        BigInt operator*(BigInt a)
        {
            BigInt res;
            int car;
            res.v.resize(v.size() + a.v.size());

            for (int i = 0; i < v.size(); i++)
            {
                car = 0;
                for (int j = 0; j < a.v.size(); j++)
                {
                    car += res.v[i + j] + v[i] * a.v[j];
                    res.v[i + j] = car % 10;
                    car = car / 10;
                }
                res.v[i + a.v.size()] = car;
            }

            while (res.v.size() > 1 && res.v.back() == 0)
            {
                res.v.pop_back();
            }

            return res;
        }


        BigInt half() 
        {
            BigInt res = *this;
            int num;
            int car = 0;

            for (int i = res.v.size() - 1; i >= 0; i--)
            {
                num = res.v[i] + (10 * car);
                res.v[i] = num / 2;
                car = num % 2;
            }
            while (res.v.back() == 0)
            {
                res.v.pop_back();
            }
            return res;
        }

        bool operator<(BigInt a) 
        {
            if (v.size() < a.v.size())
            {
            return true; 
            }
                
            if (v.size() > a.v.size())
            {
                return false;
            }
                
            for (int i = v.size() - 1; i >= 0; i--)
            {
                if (v[i] < a.v[i])
                {
                    return true;
                }
                    
                else if (v[i] > a.v[i])
                {
                    return false;
                }
            }

            return false; 
        }
        bool isOdd() 
        {
            return v[0] % 2 != 0;
        }
        bool isEven() 
        {
            return v[0] % 2 == 0;
        }


        bool operator==(BigInt a) 
        {
            if (v.size() != a.v.size())
                return false;
            return v == a.v;
        }

    friend ostream& operator<<(ostream& os, const BigInt& n) 
    {
        if (n.v.size() <= 8)
        {
            for (int i = n.v.size() - 1; i >= 0; i--)
            {
                os << +n.v[i];
            }
        }
        else
        {
            os << +n.v[n.v.size() - 1] << ".";
            for (int i = n.v.size() - 2; i >= n.v.size() - 8; i--)
            {
                os << +n.v[i];
            }
            os << 'e' << n.v.size() - 1;
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
        findThreeNp1(tempN*BigInt(3)+BigInt(1), Np1, printSteps);
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
    cout << "The largest integer is " << MAX << endl;
    cout << "Twice the largest integer is " << MAX + MAX << endl;
    BigInt start(INT_MAX);
    bool printSteps = false;
    ThreeNp1 N = {start, 0, 0, 0, 0};
    findThreeNp1(start, N, printSteps);
    cout << endl;
    print(N);

    return 0;
}
