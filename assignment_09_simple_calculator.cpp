// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int addition(int number1, int number2)
{
    return number1 + number2;
}

int subtraction(int number1, int number2)
{
    return number1 - number2;
}

int multiplication(int num1, int num2)
{
    return num1 * num2;
}

double division(int num1, int num2)
{
    if (num2 == 0)
    {
        cout << "Second Number cannot be zero" << endl;
        return 0;
    }

    return (double)num1 / num2;
}

int modulus(int num1, int num2)
{
    if (num2 == 0)
    {
        cout << "Second Number cannot be zero" << endl;
        return 0;
    }

    return num1 % num2;
}

double expo(int num1, int num2)
{
    return pow(num1, num2);
}

int main()
{
    while (true)
    {
        cout << "\n============================" << endl;
        cout << "     SIMPLE CALCULATOR" << endl;
        cout << "============================" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;

        int choice;
        cout << "Select an operation (1-7): ";
        cin >> choice;

        if (choice == 7)
        {
            cout << "Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 7)
        {
            cout << "Out of range. Must be between 1 - 7" << endl;
            continue;
        }

        int number1, number2;
        cout << "Enter first number: ";
        cin >> number1;

        cout << "Enter second number: ";
        cin >> number2;

        if (choice == 1)
        {
            cout << addition(number1, number2) << endl;
        }
        else if (choice == 2)
        {
            cout << subtraction(number1, number2) << endl;
        }
        else if (choice == 3)
        {
            cout << multiplication(number1, number2) << endl;
        }
        else if (choice == 4)
        {
            cout << division(number1, number2) << endl;
        }
        else if (choice == 5)
        {
            cout << modulus(number1, number2) << endl;
        }
        else if (choice == 6)
        {
            cout << expo(number1, number2) << endl;
        }
    }

    return 0;
}

