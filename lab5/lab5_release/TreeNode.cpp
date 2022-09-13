#include "TreeNode.h"

// Implementation of TreeNode class below

TreeNode::TreeNode(DBentry* _entryPtr) { // constructor
    entryPtr = _entryPtr;
    left = NULL;
    right = NULL;
}

TreeNode::~TreeNode() { // destructor
    if (entryPtr != NULL){ // is this condition necessary?
        delete entryPtr; // should this be deleted here?
    }
}        

void TreeNode::setLeft(TreeNode* newLeft) { // left child mutator
    left = newLeft;
}

void TreeNode::setRight(TreeNode* newRight) { // right child mutator
    right = newRight;
}

TreeNode* TreeNode::getLeft() const { // left child accessor
    return left;
}

TreeNode* TreeNode::getRight() const { // right child accessor
    return right;
}

DBentry* TreeNode::getEntry() const { // entryPtr accessor
    return entryPtr;
}