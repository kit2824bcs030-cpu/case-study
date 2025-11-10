#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

class Config {
private:
    map<string, string> settings; 

public:
   
    Config(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error: Could not open configuration file!" << endl;
            return;
        }

        string key, value;
        while (file >> key >> value) {
            settings[key] = value; 
        }

        cout << "Configuration loaded successfully from file: " << filename << endl;
        file.close();
    }

  
    Config(const Config& other) {
        settings = other.settings;
        cout << "Copy constructor called. Configuration duplicated.\n";
    }

   
    void display() const {
        cout << "\n--- Configuration Settings ---\n";
        for (auto& pair : settings) {
            cout << pair.first << " = " << pair.second << endl;
        }
        cout << "-------------------------------\n";
    }
};

int main() {
    
    ofstream file("settings.txt");
    file << "username admin\n";
    file << "password 1234\n";
    file << "timeout 30\n";
    file.close();


    Config config1("settings.txt");
    config1.display();


    Config config2 = config1;
    config2.display();

    return 0;
}

