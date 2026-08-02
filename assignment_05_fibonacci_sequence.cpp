// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
using namespace std;


vector<int> generate_fibonacci_numbers(int n)
{
    vector<int> nums = {0, 1};

    if (n < 0)
    {
        return {};
    }

    if (n == 1)
    {
        return {nums[0]};
    }

    for (int i = 0; i < n - 2; i++)
    {
        int fibonacci_number = nums[i] + nums[i + 1];
        nums.push_back(fibonacci_number);
    }

    return nums;
}

bool check_fibonacci_number(int n)
{
    vector<int> nums = generate_fibonacci_numbers(n + 1);

    for (int num : nums)
    {
        if (num == n)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int number_of_terms;

    cout << "How many terms? ";
    cin >> number_of_terms;

    vector<int> fibonacci_numbers = generate_fibonacci_numbers(number_of_terms);

    if (!fibonacci_numbers.empty())
    {
        for (int num : fibonacci_numbers)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Invalid Input" << endl;
    }

    int check_number;
    cout << "Enter a number to check: ";
    cin >> check_number;

    if (check_fibonacci_number(check_number))
    {
        cout << check_number << " is a fibonacci number" << endl;
    }
    else
    {
        cout << check_number << " is not a fibonacci number" << endl;
    }

    return 0;
}
