#include <iostream>
#include <fstream>
#include<string.h>
#include <ctime>
using namespace std;

class EditTask{
public:
    void edit();
private:
    bool editTaskByID(int taskID);
};

void EditTask::edit() {
    int taskID;
    cout << "Enter Task ID to edit: ";
    cin >> taskID;
    if (editTaskByID(taskID)) {
        cout << "Task with ID " << taskID << " edited successfully.\n";
    } else {
        cout << "Task with ID " << taskID << " not found.\n";
    }
}

bool EditTask::editTaskByID(int taskID) {
    ifstream fin;
    fin.open("Task.txt");
    ofstream temp;
    temp.open("temp.txt");
    string line;
    bool found = false;
    time_t now = time(0);
    while (getline(fin, line)) {
        if (line.find("Task ID:" + to_string(taskID)) != string::npos) {
            found = true;
            string content, expire_date;
            string timestamp = ctime(&now);
            timestamp.pop_back();
            cin.ignore(); // Clear the input buffer
            cout << "Enter task content: ";
            getline(cin, content);
            cout << "Enter task expire date (YYYY-MM-DD): ";
            getline(cin, expire_date);
            temp <<"Task ID:"<<taskID<<" "<< content << "   "; // Write content to the file
            temp << "current date at the creation: " << timestamp << "   "; // Write current timestamp to the file
            temp << "task expiring date: "<< expire_date << "\n"; // Write expire date to the file
            std::cout << "Task modified!"<< std::endl;
        } else {
            temp << line << endl;
        }
    }

    temp.close();
    fin.close();
    remove("Task.txt");
    rename("temp.txt", "Task.txt");

    return found;
}