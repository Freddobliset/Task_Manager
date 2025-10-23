#include<iostream>
#include <fstream>
#include <string>
using namespace std;
class Removetask {
public:
    void removeTask();  
private:
    bool deleteTaskByID(int taskID);
};

void Removetask::removeTask() {
    int taskID;
    cout << "Enter Task ID to remove: ";
    cin >> taskID;
    if (deleteTaskByID(taskID)) {
        cout << "Task with ID " << taskID << " removed successfully.\n";
    } else {
        cout << "Task with ID " << taskID << " not found.\n";
    }  
}

bool Removetask::deleteTaskByID(int taskID){
    ifstream fin;
    fin.open("Task.txt");
    ofstream temp;
    temp.open("temp.txt");
    string line;
    while(getline(fin, line)){
        if(line.find("Task ID:"+to_string(taskID))==string::npos){ 
            temp<<line<<endl;
        }
    }
    temp.close();
    fin.close();
    remove("Task.txt");
    rename("temp.txt","Task.txt");
}