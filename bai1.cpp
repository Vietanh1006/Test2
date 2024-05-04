#include <iostream>
using namespace std;

int sum_of_divisors(int n)
{
    int sum_divisors = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            sum_divisors += i;
        }
    }
    return sum_divisors;
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int n;
        cin >> n;
        cout << sum_of_divisors(n) << endl;
    }

    return 0;
}