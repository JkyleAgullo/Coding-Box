#include <iostream>
#include <iomanip> // for std::setprecision
// This code is intended to be used in dividing your money into 50/30/20. It teaches how to budget your money.
using namespace std;

int main()
{
    double budget = 0.0;
    const double NECESSITIES_PERCENTAGE = 0.5;
    const double WANTS_PERCENTAGE = 0.3;
    const double SAVINGS_PERCENTAGE = 0.2;

    cout << "--------------------------------" << endl;
    cout << "Welcome to (50/30/20) Budget Calculator" << endl;
    cout << "--------------------------------" << endl << endl;

    cout << "Enter Your Initial Budget: Php ";
    cin >> budget;

    double necessities = budget * NECESSITIES_PERCENTAGE;
    double wants = budget * WANTS_PERCENTAGE;
    double savings = budget * SAVINGS_PERCENTAGE;

    cout << fixed << setprecision(2);
    cout << endl << "Budget Allocation:" << endl;
    cout << "------------------" << endl;
    cout << "NECESSITIES (" << (NECESSITIES_PERCENTAGE * 100) << "%): Php " << necessities << endl;
    cout << "WANTS (" << (WANTS_PERCENTAGE * 100) << "%): Php " << wants << endl;
    cout << "SAVINGS AND INVESTMENT (" << (SAVINGS_PERCENTAGE * 100) << "%): Php " << savings << endl;

    return 0;
}
