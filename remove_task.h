#include<iostream>
#include <fstream>
#include <string>
using namespace std;
class Removetask {
public:
    void removeTask();  
private:
    bool deleteTaskByID(int taskID);
    bool deleteTaskByDate(const string& date);
};

void Removetask::removeTask() {
    cout << "Remove Task by:\n1. Task ID\n2. Date\nChoose an option (1 or 2): ";
    int choice;
    cin >> choice;
    if (choice == 1) {
    int taskID;
    cout << "Enter Task ID to remove: ";
    cin >> taskID;
    if (deleteTaskByID(taskID)) {
        cout << "Task with ID " << taskID << " removed successfully.\n";
    } else {
        cout << "Task with ID " << taskID << " not found.\n";
    }  
    } else if (choice == 2) {
        string date;
        cout << "Enter Date (YYYY-MM-DD) to remove tasks: ";
        cin >> date;
        if (deleteTaskByDate(date)) {
            cout << "Tasks on date " << date << " removed successfully.\n";
        } else {
            cout << "No tasks found on date " << date << ".\n";
        }
    } else {
        cout << "Invalid choice. Please select 1 or 2.\n";
    }
}

bool Removetask::deleteTaskByID(int taskID){
    ifstream fin;
    fin.open("Task.txt");
    ofstream temp;
    temp.open("temp.txt");
    string line;
    bool found = false;
    while(getline(fin, line)){
        if(line.find("Task ID:"+to_string(taskID))==string::npos){ 
            temp<<line<<endl;
        } else {
            found = true;
        }
    }
    temp.close();
    fin.close();
    remove("Task.txt");
    rename("temp.txt","Task.txt");
    return found;
}

bool Removetask::deleteTaskByDate(const string& date){
    ifstream fin;
    fin.open("Task.txt");
    ofstream temp;
    temp.open("temp.txt");
    string line;
    bool found = false;
    while(getline(fin, line)){
        if(line.find("task expiring date: "+date)==string::npos){ 
            temp<<line<<endl;
        } else {
            found = true;
        }
    }
    cin.ignore();
    temp.close();
    fin.close();
    remove("Task.txt");
    rename("temp.txt","Task.txt");
    return found;
}