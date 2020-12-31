#include <iostream>
#include <random>
#include <unistd.h>
using namespace std;

int main()
{
    unsigned int number, counter = 0, before, after;
    cout << "Enter your number: ( 0 < x < 100)";
    cin >> number;

    int y;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 100);
    before = 0;
    after = 100;
    int x = distr(gen);
    y = x;

    while (number > 0)
    {
        if (y == number)
        {
            cout << "\n\nyour number: " << y << endl;
            cout << "counter: " << counter << endl;
            break;
        }
        else if (y > number)
        {

            cout << y << endl;
            cout << "smaller" << endl;
            usleep(900000);
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(before, x);
            y = distr(gen);
            after = x;
            x = y;
            counter++;
        }
        else if (y < number)
        {
            cout << y << endl;
            cout << "bigger" << endl;
            usleep(900000);
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(x, after);
            y = distr(gen);
            before = x;
            x = y;
            counter++;
        }
    }
    return 0;
}