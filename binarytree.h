/****************************************************************************************************************************
Title        : binarytree.h
Author       : Lanique Peterson
Description  : Header file for the BinaryTree class
****************************************************************************************************************************/
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <string>

struct ContactNode
{
    ContactNode(std::string contactName,std::string number)
    {
        name = contactName;
        phone = number;
        left = right = nullptr;
    }
    std::string name;
    std::string phone;
    ContactNode* left;
    ContactNode* right;

};

class BinaryTree
{
    private:
        int size;
        ContactNode* root;
    
    public:

        /**
        * Default Constructor 
        * @ param  None
        * @ return None
        */
        BinaryTree();

        /**
        * @ param  None
        * @return Returns the amount of contacts in our tree
        */
        int getSize();

        /**
        * @ param  None
        * @return Returns the root node of the tree
        */
        ContactNode* getRoot();

        /**
        * @param  contactName The name of the contact
        * @param  number The contact's number
        * @return Returns a pointer to the node generated
        *         This node should be correctly placed in the tree
        *         Assume no duplicate contactNames
        */ 
        ContactNode* insert(std::string contactName, std::string number);

        /**
        * @param  contactName The name of the contact we want to search for
        * @return Returns a pointer to the node where the contactName matches
        *         Return NULL if contactName not in tree
        */
        ContactNode* findByName(std::string contactName);

        /**
        * @param  contactName The name of the contact we want to search for
        * @ param  newName   The name we want to update to, if passed an empty string do not update
        * @param  newNumber   The new phone number we want to update to, if passed an empty string do not update
        * @return Returns a pointer to the node where the contactName matches
        *         Return NULL if contactName not in tree
        */
        ContactNode* update(std::string contactName,std::string newNumber);

        /**
        * @ param  None
        * @return Return a string with all the contact information in the tree, in sorted order
        *         If the tree is empty, return a empty string
        * Format:
        *         <name> : <phone>
        * Note: each contact should be on their own line
        *
        * Example:
        *       insert("Kelly","555-555-5555")
        *       insert("Albert","555-555-5555")
        *       insert("Debra","555-555-5555")
        *       insert("Susan","555-555-5555")
        *       insert("Bob","555-555-5555")
        *
        *  The above should print out:
        *       Albert : 555-555-5555
        *       Bob : 555-555-5555
        *       Debra : 555-555-5555
        *       Kelly : 555-555-5555
        *       Susan : 555-555-5555
        *
        * NOTE: The last character in your string should be a new line UNLESS the tree is empty
        * 
        */
        std::string getSortedContactString(); ///we cannot change this method's intake.
        std::string contactStringHelp(ContactNode* currentContact); ///therefore, helper function was created!
       
        /**
        * Deconstructor - Should delete all heap allocated nodes
        * @ param  None
        * @ return None
        */
        ~BinaryTree();

};
#endif
