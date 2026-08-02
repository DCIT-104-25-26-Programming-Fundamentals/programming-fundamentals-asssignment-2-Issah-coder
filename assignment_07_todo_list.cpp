// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void add(vector<string> &todo)
{
    string task;

    cout << "Enter Task: ";
    cin.ignore();
    getline(cin, task);

    todo.push_back(task);

    cout << "Task added: " << task << endl;
}

void remove(vector<string> &todo)
{
    int del;

    cout << "Enter task number to delete: ";
    cin >> del;

    string deleted_item = todo[del - 1];
    todo.erase(todo.begin() + (del - 1));

    cout << "Task '" << deleted_item << "' has been removed." << endl;
}

void view(vector<string> &todo)
{
    for (int i = 0; i < todo.size(); i++)
    {
        cout << i + 1 << ". " << todo[i] << endl;
    }
}

int main()
{
    vector<string> todo;
    int choice;

    while (true)
    {
        cout << "\n============================" << endl;
        cout << "      TO-DO LIST MENU" << endl;
        cout << "============================" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Delete task" << endl;
        cout << "4. Quit" << endl;

        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1)
        {
            add(todo);
        }
        else if (choice == 2)
        {
            view(todo);
        }
        else if (choice == 3)
        {
            remove(todo);
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

