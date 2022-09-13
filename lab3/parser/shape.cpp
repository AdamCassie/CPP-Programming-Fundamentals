//
//  shape.cpp skeleton
//  lab3
//
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018 Tarek Abdelrahman. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#include "shape.h"

// ECE244 Student: 
// Write the implementation (and only the implementation) of the shape
// class below

// Build a shape object with its properties
shape::shape(string n, string t, int x_loc, int y_loc, int x_sz, int y_sz){
    name = n;
    type = t;
    x_location = x_loc;
    y_location = y_loc;
    x_size = x_sz;
    y_size = y_sz;
}
    
//Accessors
string shape::getType() {             // Returns the type 
    return type;
}

string shape::getName() {             // Returns the name of the shape
    return name;
}    

int shape::getXlocation() {           // Returns location of the shape on the x-axis
    return x_location;
}    

int shape::getYlocation() {           // Returns location of the shape on the y-axis
    return y_location;
}
int shape::getXsize() {               // Returns the size of the shape in the x-dimension
    return x_size;
}

int shape::getYsize() {               // Returns the size of the shape in the y-dimension
    return y_size;
}

// Mutators
void shape::setType(string t) {       // Sets the type (see globals.h)
    type = t;
}  

void shape::setName(string n) {       // Sets the name of the shape
    name = n;
}

void shape::setXlocation(int x_loc) { // Sets location of the shape on the x-axis
    x_location = x_loc;
}

void shape::setYlocation(int y_loc) { // Sets location of the shape on the y-axis
    y_location = y_loc;
}

void shape::setXsize(int x_sz) {      // Sets size of the shape in the x-dimension
    x_size = x_sz;
}

void shape::setYsize(int y_sz) {      // Sets size of the shape in the y-dimension
    y_size = y_sz;
}

void shape::setRotate(int angle) {    // sets the rotation of the shape
    rotation = angle;
}

// Utility methods
void shape::draw() {                  // Draws a shape
    cout << name << ": " << type << " " << x_location << " " << y_location 
            << " " << x_size << " " << y_size << endl;
}
