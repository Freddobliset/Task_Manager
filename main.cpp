#include<iostream>
#include "task_creation.h"
#include "remove_task.h"
#include "show_task.h"
#include "edit_task.h"
int main() {

    string choice;
    cout << "use 'help' to see available commands.\n\n";
    do {
        getline(cin, choice);
        if(choice == "create") {
            Taskcreation tc;
            tc.createTask();
        } else if(choice == "remove") {
            Removetask rm;
            rm.removeTask();
        } else if(choice == "show") {
            Showtask st;
            st.Showtasks();
        } else if(choice == "edit") {
            EditTask et;
            et.edit();
        } else if(choice == "exit") {
            cout << "Exiting the program.\n";
        }else if(choice == "help"){
            cout << "Available commands:\n\n";
            cout << "create - Create a new task\n\n";
            cout << "remove - Remove an existing task by ID\n\n";
            cout << "show - Display all current tasks\n\n";
            cout << "edit - Edit an existing task by ID\n\n";
            cout << "exit - Exit the program\n\n";
        }else {
            cout << "Invalid option. Please try again.\n";
        }
    } while (choice != "exit");

    return 0;
}