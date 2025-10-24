#include<iostream>
#include "task_creation.h"
#include "remove_task.h"
#include "show_task.h"
#include "edit_task.h"
int main() {

    int choice;
    do {
        cout << "\n===== Task Manager =====\n";
        cout << "1. Create new task\n";
        cout << "2. Remove a task\n";
        cout << "3. Show all tasks\n";
        cout << "4. edit task\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Taskcreation tc;
                tc.createTask();
                break;
            case 2:
                Removetask rt;
                rt.removeTask();
                break;
            case 3:
                Showtask st;
                st.Showtasks();
                break;
            case 4:
                EditTask et;
                et.edit();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option, try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}