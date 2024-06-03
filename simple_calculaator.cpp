#include<iostream>
using namespace std;

int main()
{
    double *number1, *number2;
    char *sign;
    double *total;

    number1 = new double;
    number2 = new double;
    total = new double;
    sign = new char;

    cout << "Enter Two Numbers and the operation sign: ";
    cin >> *number1 >> *number2 >> *sign;

    switch(*sign)
    {
        case '+':
            *total = *number1 + *number2;
            break;
        case '-':
            *total = *number1 - *number2;
            break;
        case '*':
            *total = *number1 * *number2;
            break;
        case '/':
            if (*number2 != 0)
                *total = *number1 / *number2;
            else
                cout << "Division by zero error!" << endl;
            break;
        default:
            cout << "Invalid operation sign!" << endl;
    }
            cout << *number1 << " " << *sign << " " << *number2 << " = " << *total;


    delete number1;
    delete number2;
    delete total;
    delete sign;

    return 0;
}
