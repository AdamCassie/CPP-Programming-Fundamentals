#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "DBentry.h"
#include "TreeNode.h"
#include "TreeDB.h"

int main () {
    cout << "TreeDB tree being constructed" << endl;
    TreeDB tree;

    DBentry* newEntry1 = new DBentry("Rama", 1010, true);
    bool flag1 = tree.insert(newEntry1);
    cout << "Entry with key Rama inserted? " << flag1 << endl; 
    // inserting new entry into empty tree

    DBentry* newEntry2 = new DBentry("Rama", 20165, false);
    bool flag2 = tree.insert(newEntry2);
    cout << "Entry with key Rama inserted? " << flag2 << endl; 
    // inserting new entry with same key as only existing entry

    DBentry* newEntry3 = new DBentry("Zain", 20165, false);
    bool flag3 = tree.insert(newEntry3);
    cout << "Entry with key Zain inserted? " << flag3 << endl; 
    // inserting new entry with different key as only existing entry

    // insert function seems to have a bug

    cout << "Number of probes is ";
    tree.printProbes();

    DBentry* newEntry4 = tree.find("Rama"); // search for existing node
    if (newEntry4 == NULL) {
        cout << "Node with name Rama NOT found" << endl;
    } else {
        cout << "Node with name Rama found" << endl;
    }

    cout << "Number active is ";
    tree.countActive();

    DBentry* newEntry5 = new DBentry("Vishal", 5, true);
    bool flag6 = tree.insert(newEntry5);
    cout << "Entry with key Vishal inserted? " << flag6 << endl; 
    // inserting new entry with different key as existing entries

    cout << "Number active is ";
    tree.countActive();

    cout << "Number of probes is ";
    tree.printProbes();

    operator<<(cout, tree); 

    DBentry* newEntry7 = new DBentry("Adrian", 9999, true);
    bool flag7 = tree.insert(newEntry7);
    cout << "Entry with key Adrian inserted? " << flag7 << endl; 
    // inserting new entry with different key as existing entries

    DBentry* newEntry8 = new DBentry("Adrian", 6969, false);
    bool flag8 = tree.insert(newEntry8);
    cout << "Entry with key Adrian inserted? " << flag8 << endl; 
    // inserting new entry with different key as existing entries

    operator<<(cout, tree); 

    DBentry* newEntry9 = tree.find("Keere"); // search for existing node
    if (newEntry9 == NULL) {
        cout << "Node with name Keere NOT found" << endl;
    } else {
        cout << "Node with name Keere found" << endl;
    }

    cout << "Number of probes is ";
    tree.printProbes();

    cout << "Number active is ";
    tree.countActive();

    tree.clear();
    operator<<(cout, tree); 
    cout << "Tree should be empty" << endl;
    cout << "Number of probes is (should be same as above) ";
    tree.printProbes();

    flag1 = tree.insert(newEntry1);
    cout << "Entry with key Rama inserted? " << flag1 << endl; 
    operator<<(cout, tree); 
    flag3 = tree.insert(newEntry3);
    cout << "Entry with key Zain inserted? " << flag3 << endl; 
    flag6 = tree.insert(newEntry5);
    cout << "Entry with key Vishal inserted? " << flag6 << endl; 
    flag8 = tree.insert(newEntry8);
    cout << "Entry with key Adrian inserted? " << flag8 << endl; 
    cout << "New tree is" << endl;
    operator<<(cout, tree); 






    // errors from here
    cout << endl << "Errors from here" << endl;

    bool flag4 = tree.remove("Keere");
    cout << "Entry with key Keere removed? " << flag4 << endl;
    // removing name which is not present in tree

    bool flag5 = tree.remove("Rama");
    cout << "Entry with key Rama removed? " << flag5 << endl;
    // removing the only existing entry

    operator<<(cout, tree); 

    return 0;
}