#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "DBentry.h"

// Implementation of DBentry class below

DBentry::DBentry() { // the default constructor
} // should this initialize the values to be anything in particular?

 DBentry::DBentry (string _name, unsigned int _IPaddress, bool _active) { // 3 arg constructor
     name = _name;
     IPaddress = _IPaddress;
     active = _active;
 }

DBentry::~DBentry() { // the destructor
}

void DBentry::setName(string _name) { // name mutator
    name = _name;
}

void DBentry::setIPaddress(unsigned int _IPaddress) { // IPaddress mutator
    IPaddress = _IPaddress;
}

void DBentry::setActive (bool _active) { // active mutator
    active = _active;
}

string DBentry::getName() const { // name accessor
    return name;
}

unsigned int DBentry::getIPaddress() const { // IPaddress accessor
    return IPaddress;
}

bool DBentry::getActive() const { // active accessor
    return active;
}

ostream& operator<< (ostream& out, const DBentry& rhs) { // prints the entry
    out << rhs.name << " : " << rhs.IPaddress << " : ";
    if (rhs.active) {
        out << "active" << endl;
    } else{
        out << "inactive" << endl;
    }
    return out;
}
