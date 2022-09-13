//
//  main.cpp skeleton
//  lab3
//
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018 Tarek Abdelrahman. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <valarray>

using namespace std;

#include "globals.h"
#include "shape.h"

// This is the shape array, to be dynamically allocated
shape** shapesArray;

// The number of shapes in the database, to be incremented 
// everytime a shape is successfully created
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;

bool checkValidCommand (string commandEntered);
bool checkValidName (string nameEntered);
bool checkNameExists (string validName);
bool checkValidType (string typeEntered);
bool checkValidValue (int value, int angle, int x_location, int y_location, 
        int x_size, int y_size);
bool checkFullArray ();
void maxShapes ();
void createShape (string name, string type, int x_location, int y_location, 
        int x_size, int y_size);
void moveShape (string name, int x_location, int y_location);
void rotateShape (string name, int angle);
void drawShape (string name);
void drawAll ();
void deleteShape (string name);
void deleteAll ();
void createCommand(stringstream& inputStream);
void moveCommand (stringstream& inputStream);
void rotateCommand (stringstream& inputStream);
void drawCommand (stringstream& inputStream);
void deleteCommand(stringstream& inputStream);


int main() {
    string line;
    string command;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);   // Get a line from standard input
    

    while (!cin.eof()) {
        stringstream lineStream (line);
        lineStream >> command;
        
        if (checkValidCommand(command) == false) {
            cout << "Error: invalid command" << endl;
            command.clear();
        }
        if (command == keyWordsList[1]) { //maxShapes command
            lineStream >> max_shapes;
            if (checkValidValue(max_shapes, 0, 0, 0, 0, 0) == false) {
                cout << "Error: invalid value" << endl;
            } else{
                maxShapes(); //Allocate and initialize array
                cout << "New database: max shapes is " << max_shapes << endl;
            }
            command.clear(); 
        }
        if (command == keyWordsList[2]) { //Create command
            createCommand(lineStream);
            command.clear();
        }
        if (command == keyWordsList[3]) { //Move command
            moveCommand(lineStream);
            command.clear();
        }
        if (command == keyWordsList[4]) { //Rotate command
            rotateCommand(lineStream);
            command.clear();
        }
        if (command == keyWordsList[5]) { //Draw command
            drawCommand(lineStream);
            command.clear();
        }
        if (command == keyWordsList[6]) { //Delete command
            deleteCommand(lineStream);
            command.clear();
        }
        cout << "> ";          // Prompt for input
        getline(cin, line);   // Get the command line
    }  // End input loop until EOF.
    return 0;
}

//Check if a valid command is entered
bool checkValidCommand (string commandEntered) {
    for (int keyIndex = 1; keyIndex < NUM_KEYWORDS; keyIndex++) {
        if (commandEntered == keyWordsList[keyIndex]) {
            return true; //Command is valid
        }
    }
    return false; //Command is invalid
}

//Check if shape name matches any reserved words
bool checkValidName (string nameEntered) {
    for (int keyIndex = 0; keyIndex < NUM_KEYWORDS; keyIndex++) {
        if (nameEntered == keyWordsList[keyIndex]) {
            return false; //Name matches a keyword
        }
    }
    for (int typeIndex = 0; typeIndex < NUM_TYPES; typeIndex++) {
        if (nameEntered == shapeTypesList[typeIndex]) {
            return false; //Name matches a shape type
        }
    } 
    return true; //Name is valid
}

//Check if a valid shape name already exists
bool checkNameExists (string validName) {
    //Loop through array and check if name of shapes pointed to matches validName
    //also use this function to look for an entered shape
    for (int arrayIndex = 0; arrayIndex < shapeCount; arrayIndex++) {
        if (shapesArray[arrayIndex] != NULL) {
            if (validName == (*(shapesArray[arrayIndex])).getName()) {
                return true;
            }
        }
    }
    return false;
}

//Check if one of the allowed shape types is used
bool checkValidType (string typeEntered) {
    for (int typeIndex = 0; typeIndex < NUM_TYPES; typeIndex++) {
        if (typeEntered == shapeTypesList[typeIndex]) {
            return true; //An allowed type is used
        }
    }
    return false; //An allowed type is not used
}

//Check if value specified as an argument is valid
bool checkValidValue (int value, int angle, int x_location, int y_location, 
        int x_size, int y_size) {
    if ((value < 0) || (angle < 0) || (angle > 360) || (x_location < 0) ||
        (y_location < 0) || (x_size < 0) || (y_size < 0)) {
        return false;
    } else {
        return true;
    }
}

//Check if the shape array is full
bool checkFullArray () {
    if (shapeCount == max_shapes) {
        return true;
    } else {
        return false;
    }
}

//To allocate and initialize array
void maxShapes () {
    shapesArray = new shape*[max_shapes];
    for (int arrayIndex = 0; arrayIndex < max_shapes; arrayIndex++) {
        shapesArray[arrayIndex] = NULL;
    }
}

//To create shape object
void createShape (string name, string type, int x_location, int y_location, 
        int x_size, int y_size) {
    shapesArray[shapeCount] = new shape(name, type, x_location, y_location, 
                                x_size, y_size);
    shapeCount++;
}

//To change the location of the shape object
void moveShape (string name, int x_location, int y_location) {
    for (int arrayIndex = 0; arrayIndex < shapeCount; arrayIndex++) {
        if (shapesArray[arrayIndex] != NULL) {
            if (name == (*(shapesArray[arrayIndex])).getName()) {
                (*(shapesArray[arrayIndex])).setXlocation(x_location);
                (*(shapesArray[arrayIndex])).setYlocation(y_location);
                break;
            }
        }
    }
}

//To rotate the shape object
void rotateShape (string name, int angle) {
    for (int arrayIndex = 0; arrayIndex < shapeCount; arrayIndex++) {
        if (shapesArray[arrayIndex] != NULL) {
            if (name == (*(shapesArray[arrayIndex])).getName()) {
                (*(shapesArray[arrayIndex])).setRotate(angle);
                break;
            }
        }
    }
}

//To draw a single shape object
void drawShape (string name) {
    for (int arrayIndex = 0; arrayIndex < shapeCount; arrayIndex++) {
        if (shapesArray[arrayIndex] != NULL) {
            if (name == (*(shapesArray[arrayIndex])).getName()) {
                (*(shapesArray[arrayIndex])).draw();
            }
        }
    }
}

//To draw all shape objects
void drawAll () {
    for (int arrayIndex = 0; arrayIndex < shapeCount; arrayIndex++) {
        if (shapesArray[arrayIndex] != NULL){
            (*(shapesArray[arrayIndex])).draw();
        }
    }
}

//To delete a single shape
void deleteShape (string name) {
    for (int arrayIndex = 0; arrayIndex < shapeCount; arrayIndex++) {
        if (shapesArray[arrayIndex] != NULL) {
            if (name == (*(shapesArray[arrayIndex])).getName()) {
                delete shapesArray[arrayIndex];
                shapesArray[arrayIndex] = NULL;
                break;
            }
        }
    }
}

//To delete all shapes
void deleteAll () {
    for (int arrayIndex = 0; arrayIndex < shapeCount; arrayIndex++) {
        if (shapesArray[arrayIndex] != NULL) {
            delete shapesArray[arrayIndex];
            shapesArray[arrayIndex] = NULL;
        }
    }  
    shapeCount = 0; //Reset number of shapes stored to zero
}

void createCommand(stringstream& inputStream) { //Create command
    string name, type, argDummy; //Dummy variable to check for extra args
    int x_location, y_location, x_size, y_size;
    inputStream >> name;
    if (inputStream.fail()) { //No argument read
        cout << "Error: too few arguments" << endl;
        return;
    }
    if (checkValidName(name) == false){ //Name entered is invalid
        cout << "Error: invalid shape name" << endl;
        return;
    }
    if (checkNameExists(name) == true) { //Name entered is already used
        cout << "Error: shape " << name << " exists" << endl;
        return;
    }
    inputStream >> type;
    if (inputStream.fail()) { //No argument read
        cout << "Error: too few arguments" << endl;
        return;
    }
    if (checkValidType(type) == false) { //Type entered is invalid
        cout << "Error: invalid shape type" << endl;
        return;
    }
    inputStream >> x_location;
    if (inputStream.fail()) {
        if (inputStream.eof()) { //No argument read
            cout << "Error: too few arguments" << endl;
            return;
        }
    }
    if (inputStream.fail() || ((inputStream.peek() != ' ') && 
        (inputStream.peek() != EOF))) { //Char or floating pt
        cout << "Error: invalid argument" << endl;
        return;
    }
    if ((checkValidValue(0, 0, x_location, 0, 0, 0)) == false) { //Value below 0
        cout << "Error: invalid value" << endl;
        return;
    }
    inputStream >> y_location;
    if (inputStream.fail()) {
        if (inputStream.eof()) { //No argument read
            cout << "Error: too few arguments" << endl;
            return;
        }
    }
    if (inputStream.fail() || ((inputStream.peek() != ' ') && 
        (inputStream.peek() != EOF))) { //Char or floating pt
        cout << "Error: invalid argument" << endl;
        return;
    }
    if ((checkValidValue(0, 0, 0, y_location, 0, 0)) == false) { //Value below 0
        cout << "Error: invalid value" << endl;
        return;
    }
    inputStream >> x_size;
    if (inputStream.fail()) {
        if (inputStream.eof()) { //No argument read
            cout << "Error: too few arguments" << endl;
            return;
        }
    }
    if (inputStream.fail() || ((inputStream.peek() != ' ') && 
        (inputStream.peek() != EOF))) { //Char or floating pt
        cout << "Error: invalid argument" << endl;
        return;
    }
    if ((checkValidValue(0, 0, 0, 0, x_size, 0)) == false) { //Value below 0
        cout << "Error: invalid value" << endl;
        return;
    }
    inputStream >> y_size;
    if (inputStream.fail()) {
        if (inputStream.eof()) { //No argument read
            cout << "Error: too few arguments" << endl;
            return;
        }
    }
    if (inputStream.fail() || ((inputStream.peek() != ' ') && 
        (inputStream.peek() != EOF))) { //Char or floating pt
        cout << "Error: invalid argument" << endl;
        return;
    }
    if ((checkValidValue(0, 0, 0, 0, 0, y_size)) == false) { //Value below 0
        cout << "Error: invalid value" << endl;
        return;
    }
    inputStream >> argDummy;
    if (!inputStream.fail()) { //Extra argument extracted
        cout << "Error: too many arguments" << endl;
        return;
    }
    if (checkFullArray() == false) {
    createShape(name, type, x_location, y_location, x_size, y_size);
    cout << "Created " << name << ": " << type << " " << x_location
            << " " << y_location << " " << x_size << " " << y_size << endl;
    } else {
        cout << "Error: shape array is full" << endl;
    }
}

void moveCommand (stringstream& inputStream) { //Move command
    string name, argDummy; //Dummy variable to check for extra args
    int x_location, y_location;
    inputStream >> name;
    if (inputStream.fail()) {
        cout << "Error: too few arguments" << endl;
        return;
    }
    if (checkValidName(name) == false){
        cout << "Error: invalid shape name" << endl;
        return;
    }
    if (checkNameExists(name) == false) {
        cout << "Error: shape " << name << " not found" << endl;
        return;
    }
    inputStream >> x_location;
    if (inputStream.fail()) {
        if (inputStream.eof()) { //No argument read
            cout << "Error: too few arguments" << endl;
            return;
        }
    }
    if (inputStream.fail() || ((inputStream.peek() != ' ') && 
        (inputStream.peek() != EOF))) { //Char or floating pt
        cout << "Error: invalid argument" << endl;
        return;
    }
    if ((checkValidValue(0, 0, x_location, 0, 0, 0)) == false) { //Value below 0
        cout << "Error: invalid value" << endl;
        return;
    }
    inputStream >> y_location;
    if (inputStream.fail()) {
        if (inputStream.eof()) { //No argument read
            cout << "Error: too few arguments" << endl;
            return;
        }
    }
    if (inputStream.fail() || ((inputStream.peek() != ' ') && 
        (inputStream.peek() != EOF))) { //Char or floating pt
        cout << "Error: invalid argument" << endl;
        return;
    }
    if ((checkValidValue(0, 0, 0, y_location, 0, 0)) == false) { //Value below 0
        cout << "Error: invalid value" << endl;
        return;
    }
    inputStream >> argDummy;
    if (!inputStream.fail()) { //Extra argument extracted
        cout << "Error: too many arguments" << endl;
        return;
    }
    if (checkNameExists(name) == true) {
        moveShape(name, x_location, y_location);
        cout << "Moved " << name << " to " << x_location << " " << y_location << endl;
    }
}

void rotateCommand (stringstream& inputStream) {
    string name, argDummy; //Dummy variable to check for extra args
    int angle;
    inputStream >> name;
    if (inputStream.fail()) {
        cout << "Error: too few arguments" << endl;
        return;
    }
    if (checkValidName(name) == false){
        cout << "Error: invalid shape name" << endl;
        return;
    }
    if (checkNameExists(name) == false) {
        cout << "Error: shape " << name << " not found" << endl;
        return;
    }
    inputStream >> angle;
    if (inputStream.fail()) {
        if (inputStream.eof()) { //No argument read
            cout << "Error: too few arguments" << endl;
            return;
        }
    }
    if (inputStream.fail() || ((inputStream.peek() != ' ') && 
        (inputStream.peek() != EOF))) { //Char or floating pt
        cout << "Error: invalid argument" << endl;
        return;
    }
    if (checkValidValue(0, angle, 0, 0, 0, 0) == false) { //Value not in range
        cout << "Error: invalid value" << endl;
        return;
    }
    inputStream >> argDummy;
    if (!inputStream.fail()) { //Extra argument extracted
        cout << "Error: too many arguments" << endl;
        return;
    }
    if (checkNameExists(name) == true) {
        rotateShape(name, angle);
        cout << "Rotated " << name << " by " << angle << " degrees" << endl;
    }
}

void drawCommand (stringstream& inputStream) { //Draw command
    //Do case for a single shape and case for all shapes
    string nextArgument, argDummy;
    inputStream >> nextArgument;
    if (inputStream.fail()){
        cout << "Error: too few arguments" << endl;
        return;
    }
    if (nextArgument == keyWordsList[0]) { //Case for all shapes
        inputStream >> argDummy;
        if (!inputStream.fail()) {
            cout << "Error: too many arguments" << endl;
            return;
        }
        cout << "Drew all shapes" << endl;
        drawAll();
        return;
    } else { //Case for single shape
        if (checkValidName(nextArgument) == false){
            cout << "Error: invalid shape name" << endl;
            return;
        }
        if (checkNameExists(nextArgument) == false) {
             cout << "Error: shape " << nextArgument << " not found" << endl;
             return;
        }
        inputStream >> argDummy;
        if (!inputStream.fail()) {
            cout << "Error: too many arguments" << endl;
            return;
        }
        if (checkNameExists(nextArgument) == true) {
            cout << "Drew " << nextArgument << endl;
            drawShape(nextArgument);
            return;
        }
    }
}
    
void deleteCommand(stringstream& inputStream) {//Delete command
    //Do case for a single shape and case for all shapes
    string nextArgument, argDummy;
    inputStream >> nextArgument;
    if (inputStream.fail()){
        cout << "Error: too few arguments" << endl;
        return;
    }
    if (nextArgument == keyWordsList[0]) { //Case for all shapes
        inputStream >> argDummy;
        if (!inputStream.fail()) {
            cout << "Error: too many arguments" << endl;
            return;
        }
        deleteAll();
        cout << "Deleted: all shapes" << endl;
        return;
    } else { //Case for single shape
        if (checkValidName(nextArgument) == false){
            cout << "Error: invalid shape name" << endl;
            return;
        }
        if (checkNameExists(nextArgument) == false) {
            cout << "Error: shape " << nextArgument << " not found" << endl;
            return;
        }
        inputStream >> argDummy;
        if (!inputStream.fail()) {
            cout << "Error: too many arguments" << endl;
            return;
        }
        if (checkNameExists(nextArgument) == true) {
            deleteShape(nextArgument);
            cout << "Deleted shape " << nextArgument << endl;
            return;
        }
    }
}
    
    
    
    