#include<iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

class Taskcreation {
public:
    void createTask();
private:    
    void WriteFile(const std::string& content, const std::string& expire_date);
    int getNextTaskID();
};

int Taskcreation::getNextTaskID() {
    ifstream infile("Task.txt");
    if (!infile.is_open()) return 1; // Primo task

    string line;
    int lastID = 0;

    while (getline(infile, line)) {
        if (line.rfind("Task ID:", 0) == 0) { //if the line starts with "Task ID:"
            try {
                int id = stoi(line.substr(8)); // Prende il numero dopo "Task ID:"
                if (id > lastID) lastID = id;
            } catch (...) {
                continue;
            }
        }
    }

    infile.close();
    return lastID + 1;
}

//WriteFile opens the Task.txt file writes the content and close it afterwards
void Taskcreation::WriteFile( const std::string& content, const std::string& expire_date) {
    int id = getNextTaskID();
    ofstream file("Task.txt", std::ios::app); // Create and open the file
    time_t now = time(0);
    int i=0;
    if (file.is_open()) {
        string timestamp = ctime(&now);
        timestamp.pop_back(); // Remove newlin
        
        file <<"Task ID:"<<id<<" "<< content << "   "; // Write content to the file
        file << "current date at the creation: " << timestamp << "   "; // Write current timestamp to the file
        file << "task expiring date: "<< expire_date << "\n"; // Write expire date to the file
        file.close();    // Close the file
        cout << "File '" << "Task.txt" << "' created and written successfully.\n";
    } else {
        std::cerr << "Failed to create or open the file.\n";
    }
}


void Taskcreation::createTask() {
    string content, expire_date;
    cin.ignore(); // Clear the input buffer
    cout << "Enter task content: ";
    getline(cin, content);
    cout << "Enter task expire date (YYYY-MM-DD): ";
    getline(cin, expire_date);
    WriteFile(content,expire_date);
    std::cout << "Task created!"<< std::endl;
}
