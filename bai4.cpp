#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

bool isSuperPrime(int n)
{
    if (!isPrime(n))
        return false;
    int numDigits = floor(log10(n)) + 1;
    while (numDigits > 1)
    {
        n = n / 10;
        if (!isPrime(n))
            return false;
        numDigits--;
    }
    return true;
}

void findSuperPrimes(int n, queue<int> &superPrimes)
{
    for (int i = 2; i <= n; i++)
    {
        if (isSuperPrime(i))
        {
            superPrimes.push(i);
        }
    }
}

int main()
{
    int n;
    cout << "Nhap so n: ";
    cin >> n;

    queue<int> superPrimes;
    findSuperPrimes(n, superPrimes);

    cout << "Cac so sieu nguyen to nho hon hoac bang " << n << " la: ";
    while (!superPrimes.empty())
    {
        cout << superPrimes.front() << " ";
        superPrimes.pop();
    }
    cout << endl;

    return 0;
}