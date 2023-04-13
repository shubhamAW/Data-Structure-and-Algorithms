#include <iostream>
using namespace std;

double calculate_bonus(double pay)
{
    // calculate bonus of employee based on their pay

    if (pay > 3000)
    {
        // if pay is greater than 3000 then bonus is $300
        return 300.0;
    }
    else if (1600 < pay && pay <= 3000)
    {
        // if pay is between 1600 and 3000 then bonus is 10% of pay but not more than $240

        double bonus = pay * (10.0 / 100.0);
        if (bonus >= 240)
        {
            return 240.0;
        }
        else
        {
            return bonus;
        }
    }
    else if (pay <= 1600 && pay > 0)
    {
        // if pay is less than or equal to 1600 then bonus is 15% of pay but not more than $100
        double bonus = pay * (15.0 / 100.0);
        if (bonus >= 100)
        {
            return 100.0;
        }
        else
        {
            return bonus;
        }
    }
    else
    {
        return 0.0;
    }
}

int main()
{
    double pay = 0.0;
    cout << "Enter the pay of employee: ";
    cin >> pay;
    cout << "your bonus is: " << calculate_bonus(pay) << endl;
}
