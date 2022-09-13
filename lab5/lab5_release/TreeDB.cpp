#include <iostream>
#include <sstream>
#include <string>
using namespace std;

#include "DBentry.h"
#include "TreeNode.h"
#include "TreeDB.h"

// Implementation of DBentry class below

TreeDB::TreeDB() { // constructor for empty database
    root = NULL;
    probesCount = 0; //should this be set to zero here?
}

TreeDB::~TreeDB() { // destructor
    delete_tree(root); // write implementation for this recursive function
}

void TreeDB::delete_tree(TreeNode* myroot) { // private helper function to delete tree
    if (myroot == NULL) { // if tree is empty
        return;
    } else { // using LRN traversal
        delete_tree(myroot->getLeft()); // delete left subtree
        delete_tree(myroot->getRight()); // delete right subtree
        delete myroot; // delete node;
        myroot = NULL;
    }    
}

bool TreeDB::insert(DBentry* newEntry) { // inserts new entry into tree
    // should we consider if newEntry is a nullptr?
    TreeNode* ptr = new TreeNode(newEntry);
    if (root == NULL) { // if tree is empty
        root = ptr;
        root->setLeft(NULL);
        root->setRight(NULL);
        return true;
    } else { // tree is not empty
        return insert_entry(ptr, root);
    }
  //  ptr = NULL;
}

//should this function be bool or void?
bool TreeDB::insert_entry(TreeNode*& p, TreeNode* r) { // private helper function to insert entry
    if ((p->getEntry())->getName() == (r->getEntry())->getName()) {
        return false;
    }
    if ((p->getEntry())->getName() < (r->getEntry())->getName()) {
        if (r->getLeft() == NULL) {
            r->setLeft(p);
            return true;
        } else {
            return insert_entry(p, r->getLeft());
        }
    }
    if ((p->getEntry())->getName() > (r->getEntry())->getName()) {
        if (r->getRight() == NULL) {
            r->setRight(p);
            return true;
        } else {
            return insert_entry(p,r->getRight());
        }
    }
  //  return false; // is this correct? is this necessary?
}

//is there anything else to consider for this function?
DBentry* TreeDB::find(string name) { // to find entry with given name
    probesCount = 0;
    return find_name(name, root);
}

DBentry* TreeDB::find_name(string n, TreeNode* r) { // helper function to find entry with given name
    if (r == NULL) {
        return NULL;
    }
    probesCount = probesCount + 1; //where and when is probesCount reset to zero?
    if ((r->getEntry())->getName() == n) {
        return r->getEntry();
    } else if ((r->getEntry())->getName() < n) {
        return find_name(n, r->getRight());
    } else {
        return find_name(n, r->getLeft());
    }
}

// may be wrong
bool TreeDB::remove(string name) { // to remove entry with given name
    if (remove_entry(root, name) == NULL) {
        return false;
    } else {
        return true;
    }
}

TreeNode* TreeDB::remove_entry (TreeNode* r, string n) {
    TreeNode* temp;
    if (r == NULL) { // empty tree
        return r;
    } else if (n < (r->getEntry())->getName()) { // only left child
        r->setLeft(remove_entry(r->getLeft(), n));
    } else if (n > (r->getEntry())->getName()) { // only right child
        r->setRight(remove_entry(r->getRight(), n));
    } else if ((r->getLeft() != NULL) && (r->getRight() != NULL)) { // two children
        temp = findMax(r->getLeft());
        (r->getEntry())->setName((temp->getEntry())->getName()); // recheck this line
        r->setLeft(remove_entry(r->getLeft(), (r->getEntry())->getName()));
    } else { // a leaf or one child
        temp = r;
        if (r->getLeft() == NULL) {
            r = r->getRight();
        } else if (r->getRight() == NULL) {
            r = r->getLeft();
        }
        delete temp;
    }
    return r;
}

TreeNode* TreeDB::findMax(TreeNode* r) {
    if (r != NULL) {
        while ((r->getRight()) != NULL) {
            r= r->getRight();
        }
    }
    return r;
}

void TreeDB::clear() { // to delete all entries
    delete_tree(root);
    root = NULL;
}

void TreeDB::printProbes() const { // to print probesCount
    cout << probesCount << endl;
}

void TreeDB::countActive () const { //to compute and print the number of active entries
    int numActive = 0;
    getNumActive(&numActive, root);
    cout << numActive << endl; // should there be an endl?
}

void TreeDB::getNumActive(int* p, TreeNode* r) const { // helper function to count the number active
    if (r == NULL) {
        return;
    } // using NLR traversal
    if ((r->getEntry())->getActive()) {
        *p = *p + 1;
    }
    getNumActive(p, r->getLeft());
    getNumActive(p, r->getRight());
}


// fix this print section maybe
ostream& operator<< (ostream& out, const TreeDB& rhs) { // to print tree in ascending order
    // if(rhs.root != NULL) {
        rhs.printTree(out, rhs.root);
    // }
    return out;
}

// should this function return ostream by reference instead of void?
void TreeDB::printTree(ostream& out, TreeNode* r) const { //helper function to print tree
    if (r == NULL) {
        return;
    } else {
        printTree(out, r->getLeft());
        operator<<(out, *(r->getEntry()));
        printTree(out, r->getRight());
    }
}
