/****************************************************************************************************************************
Title        : binarytree.cpp
Author       : Lanique Peterson
Description  : Implementation file for the BinaryTree class
****************************************************************************************************************************/

#include "binarytree.h"

BinaryTree::BinaryTree()
{
//    root = nullptr;
    size = 0;
}

int BinaryTree::getSize() ///amount of contacts in our tree.
{
    return size;
}

ContactNode* BinaryTree::getRoot() ///returns the root node of the tree.
{
    return root;
}

ContactNode* BinaryTree::insert(std::string contactName,std::string number) ///returns a pointer to the node generated; this node should be correctly placed in the tree; return NULL if contactName not in tree.
{
    size++;
}

ContactNode* BinaryTree::findByName(std::string contactName) ///returns a pointer to the node where the contactName matches; returns  NULL if contactName not in tree.
{

}

ContactNode* BinaryTree::update(std::string contactName,std::string newNumber) ///returns a pointer to the node where the contactName matches; return NULL if contactName not in tree.
{
    
}

std::string BinaryTree::getSortedContactString() ///return a string with all the contact information in the tree, in sorted order; if the tree is empty, return a empty string
{
    /// format, " <name> : <phone> " example, " Albert : 555-555-5555 ", each contact should be on their own line and the last character in your string should be a new line UNLESS the tree is empty.
}

BinaryTree::~BinaryTree() ///delete all heap allocated nodes
{

}
