#include <iostream>
#include <sstream>
#include <string>
//#include <valarray> // may not be necessary
using namespace std;

#include "DBentry.h"
#include "TreeNode.h"
#include "TreeDB.h"

// Implementation of Parser below

void insertCommand(TreeDB& tree, stringstream& inputStream);
void findCommand(TreeDB& tree, stringstream& inputStream);
void removeCommand(TreeDB& tree, stringstream& inputStream);
void printallCommand(TreeDB& tree);
void printprobesCommand(TreeDB& tree, stringstream& inputStream);
void removeallCommand(TreeDB& tree);
void countactiveCommand(TreeDB& tree);
void updatestatusCommand(TreeDB& tree, stringstream& inputStream);


int main() {
    TreeDB database;
    string line;
    string command;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);   // Get a line from standard input
    

    while (!cin.eof()) {
        stringstream lineStream (line);
        lineStream >> command;
        
        if (command == "insert") { // Insert command
            insertCommand(database, lineStream);
            command.clear();
        }
        if (command == "find") { // Find command
            findCommand(database, lineStream);
            command.clear();
        }
        if (command == "remove") { // Remove command
            removeCommand(database, lineStream);
            command.clear();
        }
        if (command == "printall") { // Printall command
            printallCommand(database);
            command.clear();
        }
        if (command == "printprobes") { // Printprobes command
            printprobesCommand(database, lineStream);
            command.clear();
        }
        if (command == "removeall") { // Removeall command
            removeallCommand(database);
            command.clear();
        }
        if (command == "countactive") { // Countactive command
            countactiveCommand(database);
            command.clear();
        }
        if (command == "updatestatus") { // Updatestatus command
            updatestatusCommand(database, lineStream);
            command.clear();
        }
        cout << "> ";          // Prompt for input
        getline(cin, line);   // Get the command line
    }  // End input loop until EOF.
    database.clear();
    return 0;
}

void insertCommand(TreeDB& tree, stringstream& inputStream) { // Insert Command
    string name, status;
    unsigned int IPaddress;
    bool active, inserted;
    inputStream >> name;
    inputStream >> IPaddress;
    inputStream >> status;
    if (status == "active") {
        active = true;
    } else {
        active = false;
    }
   // DBentry newEntry(name, IPaddress, active);
    DBentry *ptr=new DBentry(name,IPaddress,active);
    inserted = tree.insert(ptr);
    if (inserted == true) {
        cout << "Success" << endl;
    } else {
        cout << "Error: entry already exists" << endl;
    }
}

void findCommand(TreeDB& tree, stringstream& inputStream) { // Find Command
    string name;
    inputStream >> name;
    DBentry* ptr = tree.find(name);
    if (ptr == NULL) {
        cout << "Error: entry does not exist" << endl;
    } else {
        operator<<(cout, *ptr);
    }
}

void removeCommand(TreeDB& tree, stringstream& inputStream) { // Remove Command
    string name;
    inputStream >> name;
    bool removed = tree.remove(name);
    if (removed == true) {
        cout << "Success" << endl;
    } else {
        cout << "Error: entry does not exist" << endl;
    }
}

void printallCommand(TreeDB& tree) { // Printall Command
    operator<<(cout, tree);
}

void printprobesCommand(TreeDB& tree, stringstream& inputStream) { // Printprobes Command
    string name;
    inputStream >> name;
    DBentry* ptr = tree.find(name);
    if (ptr == NULL) {
        cout << "Error: entry does not exist" << endl;
    } else {
        tree.printProbes();
    }
}

void removeallCommand(TreeDB& tree) { // Removeall Command
    tree.clear();
    cout << "Success" << endl;
}

void countactiveCommand(TreeDB& tree) { // Countactive Command
    tree.countActive();
}

void updatestatusCommand(TreeDB& tree, stringstream& inputStream) { // Updatestatus Command
    string name, status;
    bool active;
    inputStream >> name;
    inputStream >> status;
    if (status == "active") {
        active = true;
    } else {
        active = false;
    }
    DBentry* ptr = tree.find(name);
    if (ptr == NULL) {
        cout << "Error: entry does not exist" << endl;
    } else {
        ptr->setActive(active);
        cout << "Success" << endl;
    }
}