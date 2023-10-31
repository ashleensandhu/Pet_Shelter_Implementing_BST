#include <iostream>
#include <fstream>
#include "ShelterBST.h"

using namespace std;

/*
** Ashleen Sandhu
** Binary Search Tree Operations Implementation
** Assignment 3, CPSC 2430
The purpose of this code is to allow the workers to use the
binary tree search to easily loop up animals by name.
This program creates a binary tree by first inserting items,
it can then search for animals, and traverse through them.
It also has function to find the parent of a root, find the
inorder successor of a root, find the number of nodes in our BST, 
find the number of leaf nodes, find the number of nodes at a 
specified level, find the height of our BST, checks is the BST
is balanced, deletes specified nodes, and destorys the whole BST.
*/

int main(int argc, char* argv[])
{
  ShelterBST tree;

   if(argc != 2)
   {
      cout << "Usage: lab3 <testFileName>" << endl;
      return 1;
   }

   string filename = argv[1];

   ifstream infile(filename);

   if(!infile.is_open())
   {
      cout << "Unable to open file: " << filename << endl;
      return 1;
   }

   string line;

   while(infile >> line)
   {
      string name;
      int age;
      int level;
      char choice = line[0];

      switch(choice)
      {
        case 'i':
           //Insert pet (will be followed by Pet Name and Pet Age)
           infile >> name;

           infile >> age;

           cout << "Adding pet, name: " << name <<", age " << age <<endl;
           tree.insertPet(name, age);
         break;

         case 's':
           //Search pet (will be followed by Pet Name to be searched)
           infile >> age;
           cout << "Searching for pet with age " << age << ": ";
           tree.searchPet(age);
         break;

         case 'n':
           //display in order traversal
           tree.inorderDisplay();
         break;

         case 'e':
           //display pre order traversal
           tree.preorderDisplay();
         break;


         case 'o':
           //display post order traversal
           tree.postorderDisplay();
         break;

          //need to add
         case 'p':
           //Find the parent (will be followed by the Pet Age to find the parent for)
           infile >> age;
           cout << "Searching for Parent with age " << age << ": ";
            tree.parent(age);
           
         break;

         case 'u':
           //Find the successor (will be followed by the Pet Age to find the successor for
           infile >> age;
           cout << "Searching for Sucessor of pet with age " << age << ": ";
           tree.successor(age);
           
         break;

         case 'c':
           //display number of nodes in tree
           tree.numOfNodes();
           
         break;

         case 'f':
           //diplay number of leaf nodes
           tree.numOfLeafNodes();
           
         break;

         case 'l':
           //diplay number of nodes at a given level
           infile >> level;
           tree.numOfLevelNodes(level);
           
         break;

         case 'h':
           //diplay height of tree
           tree.height();
           
         break;

         case 'b':
           //diplay if tree is balanced
           cout << "Checking to see if tree is balanced: " << endl;
           tree.isBalanced();
           
         break;

         case 'd':
           //delete pet, will be followed by the pet age to be deleted
           infile >> age;
           tree.Delete(age);
           
         break;

         case 'y':
           //destroy tree
           tree.destroyTree();
           
         break;


      }
   }

}
