/****************************************************************************************************************************
Title        : binarytree.cpp
Author       : Lanique Peterson
Description  : Implementation file for the BinaryTree class
****************************************************************************************************************************/

#include "binarytree.h"
#include <iostream>

BinaryTree::BinaryTree()
{
    root = nullptr;
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

ContactNode* BinaryTree::insert(std::string contactName,std::string number) ///returns a pointer to the node generated; this node should be correctly placed in the tree; assume no duplicate contactNames.
{
    ContactNode* newContact = new ContactNode(contactName, number);
    
        if(size == 0)
        {
            root = newContact;
        }
        else
        {
            ContactNode* currentNode = root;
            ContactNode* parentNode = nullptr;
            
            while(currentNode != nullptr)
            {
                parentNode = currentNode; ///our crawler, to get to the position we want.
                    if(currentNode->name > contactName) ///comparing alphabet as per project instructions.
                        currentNode = currentNode->left; ///less than first
                    else
                        currentNode = currentNode->right; ///greater than second
            }
            
            if(parentNode->name > contactName) ///assigning the new contact.
                parentNode->left = newContact;
            else
                parentNode->right = newContact;
        }
    size++; ///inevitable.
    return newContact;
}

ContactNode* BinaryTree::findByName(std::string contactName) ///returns a pointer to the node where the contactName matches; returns NULL if contactName not in tree.
{
    ContactNode* willThisNodeMatch = root; ///our traveling pointer we will use to compare each current node's data given.
    
    while(willThisNodeMatch != nullptr)
    {
        if(willThisNodeMatch->name == contactName) ///checker.
            return willThisNodeMatch;
        else if(willThisNodeMatch->name > contactName) ///if not, go left. else go right.
            willThisNodeMatch = willThisNodeMatch->left;
        else
            willThisNodeMatch = willThisNodeMatch->right;
    }
    
    return nullptr; ///if name does not exist, return nullptr.
}

ContactNode* BinaryTree::update(std::string contactName,std::string newNumber) ///returns a pointer to the node where the contactName matches; return NULL if contactName not in tree.
{
    
    ContactNode* updateThisContact = findByName(contactName); ///have to find the name if it is in our contacts list. we already made a function, so use this as a helper.
    
    if(updateThisContact == nullptr)
        return nullptr;
    else
        updateThisContact->phone = newNumber; ///update the contact with the new number given!
    
    return updateThisContact; ///return the pointer.
}

std::string BinaryTree::contactStringHelp(ContactNode* currentContact) /// format, " <name> : <phone> " example, " Albert : 555-555-5555 ", each contact should be on their own line and the last character in your string should be a new line UNLESS the tree is empty.
{
    std::string contactInformation = "";
    
    if(currentContact == nullptr) ///our base case.
        return "";
    else
    {
        contactInformation = contactStringHelp(currentContact->left);
        contactInformation = contactInformation + currentContact->name + " : " + currentContact->phone + "\n";
        contactInformation = contactInformation + contactStringHelp(currentContact->right);
    }
    return contactInformation;
}

std::string BinaryTree::getSortedContactString() ///return a string with all the contact information in the tree, in sorted order; if the tree is empty, return a empty string
{
    return contactStringHelp(root);
}

BinaryTree::~BinaryTree() ///delete all heap allocated nodes
{
}
