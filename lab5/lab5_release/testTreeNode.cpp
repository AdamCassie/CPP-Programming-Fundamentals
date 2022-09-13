#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "DBentry.h"
#include "TreeNode.h"

int main () {
    DBentry* p = new DBentry;
    DBentry* q = new DBentry;
    DBentry* r = new DBentry;
    
//    DBentry* p = NULL;
//    DBentry* q = NULL;
//    DBentry* r = NULL;
    
    TreeNode apple(p);
    TreeNode plum(q);
    TreeNode mango(r);
    
//    TreeNode* i = &apple;
    TreeNode* j = &plum;
    TreeNode* k = &mango;
    
    apple.setLeft(j);
    apple.setRight(k);
    
    cout << "Address of apple's left is: ";
    cout << apple.getLeft() << endl;
    cout << "Address of plum is:  ";
    cout << j << endl << endl;
    
    cout << "Address of apple's right is: ";
    cout << apple.getRight() << endl;
    cout << "Address of mango is: ";
    cout << k << endl << endl;
    
    cout << "Address of apple's entry is: ";
    cout << apple.getEntry() << endl;
    cout << "Address of the respective DBentry is: ";
    cout << p << endl << endl;
    
    return 0;
}