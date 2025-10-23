#include<iostream>
#include <fstream>
#include <string>
using namespace std;

class Showtask {
public:
    void Showtasks(){
    ifstream file("Task.txt");
    string line;
    if (file.is_open()) {
        cout << "\n===== Current Tasks =====\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "No tasks found.\n";
    }
}
};  