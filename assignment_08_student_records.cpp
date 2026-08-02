// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student
{
    string name;
    int id;
    vector<float> scores;
};

Student add()
{
    Student student;
    int number;

    cout << "Student Name: ";
    cin.ignore();
    getline(cin, student.name);

    cout << "Student Id: ";
    cin >> student.id;

    cout << "How many scores? ";
    cin >> number;

    for (int i = 0; i < number; i++)
    {
        float score;
        cout << "Enter Score " << i + 1 << ": ";
        cin >> score;
        student.scores.push_back(score);
    }

    return student;
}

double average(vector<float> scores)
{
    double sum = 0;

    for (float score : scores)
    {
        sum += score;
    }

    return sum / scores.size();
}

void display(vector<Student> records)
{
    cout << "--------------------------------------------------" << endl;
    cout << "Name\t\tID\tScores\t\tAverage" << endl;

    for (Student record : records)
    {
        cout << record.name << "\t"
             << record.id << "\t";

        for (float score : record.scores)
        {
            cout << score << " ";
        }

        cout << "\t" << average(record.scores) << endl;
    }

    cout << "--------------------------------------------------" << endl;
}

int main()
{
    vector<Student> student_records;

    while (true)
    {
        cout << "\n================================" << endl;
        cout << "   STUDENT RECORD SYSTEM MENU" << endl;
        cout << "================================" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Calculate average score" << endl;
        cout << "4. Quit" << endl;

        int choice;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1)
        {
            Student record = add();
            student_records.push_back(record);
        }
        else if (choice == 2)
        {
            display(student_records);
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter Student Id: ";
            cin >> id;

            for (Student student : student_records)
            {
                if (student.id == id)
                {
                    cout << "Average: " << average(student.scores) << endl;
                }
            }
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }

    return 0;
}

