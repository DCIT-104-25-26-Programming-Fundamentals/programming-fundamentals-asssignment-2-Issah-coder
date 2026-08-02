// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
using namespace std;
#include <vector>

int the_sum(vector<int> numbers)
{
    int sum = 0;
    for (int number : numbers)
    {
        sum += number;
    }
    return sum;
}

double the_average(vector<int> numbers, int n)
{
    return (double)the_sum(numbers) / n;
}

int the_maximum(vector<int> numbers)
{
    int maximum = numbers[0];
    for (int num : numbers)
    {
        if (num > maximum)
        {
            maximum = num;
        }
    }
    return maximum;
}

int the_minimum(vector<int> numbers)
{
    int minimum = numbers[0];
    for (int number : numbers)
    {
        if (number < minimum)
        {
            minimum = number;
        }
    }
    return minimum;
}

int main()
{
    int n;
    cout << "How many numbers? ";
    cin >> n;

    vector<int> numbers;

    for (int i = 1; i <= n; i++)
    {
        int number;
        cout << "Enter number " << i << ": ";
        cin >> number;
        numbers.push_back(number);
    }

    cout << "Results:" << endl;
    cout << "Sum: " << the_sum(numbers) << endl;
    cout << "Average: " << the_average(numbers, n) << endl;
    cout << "Maximum: " << the_maximum(numbers) << endl;
    cout << "Minimum: " << the_minimum(numbers) << endl;

    return 0;
}

