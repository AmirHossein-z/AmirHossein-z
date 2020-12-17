#include <iostream>
#include <vector>
using namespace std;

int Combination(int n, int m)
{
    if (n == m || m == 0)
        return 1;
    else
        return Combination(n - 1, m) + Combination(n - 1, m - 1);
}
int main()
{
    vector<int> result;
    int n;
    cout << "Enter number: ";
    cin >> n;
    int p = n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            result.push_back(Combination(i - 1, j));
        }

        for (int q = 0; q <= p; q++)
        {
            cout << '\t';
        }
        p = p - 1;

        for (int k = 0; k < result.size(); k++)
        {
            cout << result[k] << '\t' << '\t';
        }
        cout << endl;
        result.erase(result.begin(), result.end());
    }
}