#include<iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

//WriteFile opens the Task.txt file writes the content and close it afterwards
void WriteFile( const std::string& content, const std::string& expire_date) {
    ofstream file("Task.txt", std::ios::app); // Create and open the file
    time_t now = time(0);

    if (file.is_open()) {

         string timestamp = ctime(&now);
            timestamp.pop_back(); // Remove newlin

        file << content << "   "; // Write content to the file
        file << "current date at the creation: " << timestamp << "   "; // Write current timestamp to the file
        file << "task expiring date: "<< expire_date << "\n"; // Write expire date to the file
        file.close();    // Close the file
        std::cout << "File '" << "Task.txt" << "' created and written successfully.\n";
    } else {
        std::cerr << "Failed to create or open the file.\n";
    }
}


void createTask() {
    string content, expire_date;
    cout << "Enter task content: ";
    cin>>content;
    cin.ignore(); // Clear the newline character from the input buffer
    cout << "Enter task expire date (YYYY-MM-DD): ";
    cin>>expire_date;
    WriteFile(content,expire_date);
    std::cout << "Task created!" << std::endl;
}
