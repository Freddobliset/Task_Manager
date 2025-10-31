#include<iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Showtask {
public:
    void Showtasks();
};  


/* shows the tasks from lowest to highest task ID and reverse,
shows the task by date of creation,
shows the tasks by date of expire
shows the task by priority */
void Showtask::Showtasks() {
    ifstream file("Task.txt");
    if (!file) {
        cerr << "Unable to open file tasks.txt";
        return;
    }
    cout<<"--choose the filtering option--"<<endl;
    cout<<"1. Show tasks from lowest to highest task ID"<<endl;
    cout<<"2. Show tasks from highest to lowest task ID"<<endl;
    cout<<"3. Show tasks by date of creation"<<endl;
    cout<<"4. Show tasks by date of expire"<<endl;
    cout<<"5. Show tasks by priority"<<endl;
    cout<<"0. Exit"<<endl;
    int choice;
    do{
        cin>>choice;
    if(choice == 1){
        cin.ignore();
        if (file.is_open()) {
        cout << "\n===== Current Tasks =====\n";
        string lines;
        while (getline(file, lines)) {
            cout << lines << endl;
        }
        cin.ignore();
        file.clear();  // Clear EOF flag
        file.seekg(0); // Move to the beginning of the file
    }
 } else if(choice == 2){
        cin.ignore();
        if (file.is_open()) {
            cout << "\n===== Current Tasks =====\n";
            file.clear();                    // Clear any error flags
            file.seekg(0, ios::beg);        // Move pointer to beginning
            
            vector<string> lines;
            string line;
            while (getline(file, line)) {
                lines.push_back(line);       // Fixed: use 'line' not 'lines'
            }
            
            // Print in reverse
            for (int i = lines.size() - 1; i >= 0; i--) {
                cout << lines[i] << endl;
            }
            cin.ignore();
        }
    } else if(choice == 3){
        // Implementation for showing tasks by date of creation
        cin.ignore();
        if(file.is_open()){
            file.clear();                    // Clear any error flags
            file.seekg(0, ios::beg);        // Move pointer to beginning
            cout << "\n===== Current Tasks =====\n";
            string line;
            string Date;
            cout<<"Enter the date of creation (example: Thu Oct 23): "; //date with example
            getline(cin,Date);
            while(getline(file, line)){
                if(line.find("current date at the creation: "+(Date))!=string::npos){ 
                cout<<line<<endl;
                }
            }
        }
        cin.ignore();
        cin.clear();
        cin.seekg(0);
    }
    else if(choice == 4){
        cin.ignore();
        if(file.is_open()){
            file.clear();                    // Clear any error flags
            file.seekg(0, ios::beg);        // Move pointer to beginning
            cout << "\n===== Current Tasks =====\n";
            string line;
            string Date;
            cout<<"Enter the task expiring date (Y/M/D): "; //date with example
            getline(cin,Date);
            while(getline(file, line)){
                if(line.find("task expiring date: "+(Date))!=string::npos){ 
                cout<<line<<endl;
                }
            }
        }
        cin.ignore();
        cin.clear();
        cin.seekg(0);
    }
    else if(choice == 5){
        cin.ignore();
        if(file.is_open()){
            file.clear();                    // Clear any error flags
            file.seekg(0, ios::beg);        // Move pointer to beginning
            cout << "\n===== Current Tasks =====\n";
            string line;
            string Priority;
            cout<<"Enter the task priority (Low/Medium/High): "; //priority with example
            getline(cin,Priority);
            while(getline(file, line)){
                if(line.find("priority: "+(Priority))!=string::npos){ 
                cout<<line<<endl;
                }
            }
        }
        cin.ignore();
        cin.clear();
        cin.seekg(0);
    }
    else{
        cout<<"Invalid choice!"<<endl;
    }
    }while(choice!=0);
    }