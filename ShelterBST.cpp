#include <iostream>
#include "ShelterBST.h"

using namespace std;

/*
ShelterBST constructor
*/
ShelterBST::ShelterBST()
{
     root = nullptr;
}
/*
The insert function firt checks if the root passed in null, if so then it
creates a new tree node. If not it will then check if the pet age is
greater than the roots age and it will use recursion to call the function again
to insert in the correct position. It will not insert pets with duplicate ages.
*/
ShelterBST::TreeNode* ShelterBST::insert(TreeNode* root, Pet* pet)
{
    if(root == nullptr)
    {
        return new TreeNode(pet);
    }

    if (root->pet->age == pet->age) //for case of duplicates
    {
        cout << "Cannot accept pets with duplicate Ages" << endl;
        return root;
    }

    if(pet->age > root->pet->age)
    {
        root->right = insert(root->right, pet);
    }
    else
    {
        root->left = insert(root->left, pet);
    }

    return root;

}
/*
The search function first checks if the root is null. It then checks for equality
with the age, then it checks if the age we are looking for is greater than the
age we are currently on. It then uses recursion to repeat this process until the age we
want is found.
*/
ShelterBST::TreeNode* ShelterBST::search(TreeNode* root, int age)
{
     if(root == nullptr)
    {
        return nullptr;
    }

    if(root->pet->age == age)
    {
        return root;
    }
    
    if(age > root->pet->age)
    {
        return search(root->right, age);
    }
    else
    {
        return search (root->left, age);
    }
}
/*
The inorder function checks if the root is null and it then returns. Then it
uses recursion to print out the pets in a left, middle, right format.
*/
void ShelterBST::inorder(TreeNode * root)
{
    if(root==nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << root->pet->name << ", " << root->pet->age << endl;
    inorder(root->right);
}
/*
The preorder function checks if the root is null and it then returns. Then it
uses recursion to print out the pets in a middle, left, right format.
*/
void ShelterBST::preorder(TreeNode * root)
{
    if(root==nullptr)
    {
        return;
    }

    cout << root->pet->name << ", " << root->pet->age << endl;
    preorder(root->left);
    preorder(root->right);
}
/*
The postorder function checks if the root is null and it then returns. Then it
uses recursion to print out the pets in a left, right, middle format.
*/
void ShelterBST::postorder(TreeNode * root)
{
    if(root==nullptr)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->pet->name << ", " << root->pet->age << endl;
}
/*
The findParent method takes a age already stored in our BST and a root.
It then returns the parent of the root with the specified age.
*/
ShelterBST::TreeNode* ShelterBST::findParent(TreeNode* root, int age)
{
    //checks if null
    if(root == nullptr)
    {
        return nullptr;
    }
    //if it is the parent of the left pet, return root we are on
    if(root->left != nullptr && root->left->pet->age == age) 
    {
        return root;
    }
    //if it is the parent of the right pet, return root we are on
    if(root->right != nullptr && root->right->pet->age == age)
    {
        return root;
    }
    //if the left pet's age is greater than the pets age return find parent on left root
    if(age > root->pet->age)
    {
        return findParent(root->right, age);
    }
    //if the left pet's age is greater than the pets age return find parent on left root
    else
    {
        return findParent(root->left, age);
    }
}
/*
findMin is a helper function for the succesor function.
It takes a right subtree and return the minimum value.
*/
ShelterBST::TreeNode* ShelterBST::findMin(TreeNode* root)
{
    if(root->left == nullptr)
    {
        return root;
    }
    return findMin(root->left);
}
/*
succesor function takes a age stored in our BST return the successor
of that pet. It first searches for where the age is then finds the
minimum of the right subtree.
*/
ShelterBST::TreeNode* ShelterBST::succesor(TreeNode* root, int age)
{
    //find where the pet is based on age given
    TreeNode* result = search(root, age);

    //create a instance of TreeNode where we will save value of the min value from right sub tree
    TreeNode* rightSubTreeMin = nullptr;

    //if right subtree has something which we can always assume is true
    if(result->right != nullptr)
    {
        rightSubTreeMin = findMin(result->right);
    }

    return rightSubTreeMin;
}
/*
numOfNodes counts all the nodes in our BST and returns the number of 
nodes.
*/
int ShelterBST::numOfNodes(TreeNode* root)
{
    //base case, if our root is null
    if(root == nullptr)
    {
        return 0;
    }

    //if not null begin counting and pass the left and right children as well
    return 1 + numOfNodes(root->left) + numOfNodes(root->right);

}
/*
numOfLeafNodes counts all the leaf nodes in our BST and returns the number of 
leaf nodes.
*/
int ShelterBST::numOfLeafNodes(TreeNode* root)
{
    //base case
    if(root == nullptr)
    {
        return 0;
    }
    //if the root has no children it is a leaf node
    if(root->left==nullptr && root->right==nullptr)
    {
        return 1;
    }
    //if not leaf not check the children of the root we are on
    else
    {
        return numOfLeafNodes(root->left) + numOfLeafNodes(root->right);
    }
}
/*
numOfLevelNodes takes a given level and return the number of nodes
on that level. It uses another variable currentLevel which keeps track of 
which level we are on.
*/
int ShelterBST::numOfLevelNodes(TreeNode* root, int level, int currentLevel)
{
    //base case
    if(root==nullptr)
    {
        return 0;
    }
    //if we are at desired level, so return 1 to count
    if(currentLevel == level)
    {
        return 1;
    }
    //run function again with children and update level we are on
    int leftCount = numOfLevelNodes(root->left, level, currentLevel+1);
    int rigthCount = numOfLevelNodes(root->right, level, currentLevel+1);

    return leftCount+rigthCount;

}
/*
height return the height of our binary search tree. It starts the height from
-1 and it increases from there detemining the heigh of the left and right
sub tree passed.
*/
int ShelterBST::height(TreeNode*root)
{ 
    //base case
    if(root==nullptr)
    {
        return -1;
    }
    //determine the height of left and right child
    int lefth = height(root->left);
    int righth = height(root->right);

    //compare heights
    if(lefth > righth)
    {
        return 1 + lefth;
    }
    else
    {
        return 1 + righth;
    }
    
}
/*
isBalanced checks to see if our BST in balanced or not. It uses our height
function to check is the difference between the levels is less than or equal
to one for each level.
*/
bool ShelterBST::isBalanced(TreeNode* root)
{
    if(root == nullptr)//do i need to do this?
    {
        return true;
    }

    //check height of each left and right child
    int leftSubTree = height(root->left);
    int rightSubTree = height(root->right);

    //if the difference is less than one for each child then return true
    if(abs(leftSubTree - rightSubTree) <= 1 && isBalanced(root->left) && isBalanced(root->right))
    {
        return true;
    }
    return false;
    
}
/*
Delete deletes a node specified with the age passed in. It delets according
to whether the node has zero, one, or two children. For no children the node is deleted.
For one child the node is replaced with the grandchild. For two children the node
is replaced with the inorder successor, we then use our succesor function to get
this value and replace it.
*/
ShelterBST::TreeNode* ShelterBST::Delete(TreeNode* root, int age)
{
    if(root==nullptr)
    {
        return root;
    }

    //search for pet with specified age
    if(age < root->pet->age)
    {
        root->left = Delete(root->left, age);
    }
    else if (age > root->pet->age)
    {
        root->right = Delete(root->right, age);
    }
    else
    {
        //assumes root is found

        //Case 1: Node has no children
        if(root->left==nullptr && root->right==nullptr)
        {
            delete root->pet;
            delete root;
            root = nullptr;
            return root;
        }

        // Case 2: Node with only one child
        else if(root->left==nullptr)
        {
            TreeNode* temp = root->right;
            delete root->pet;
            delete root;
            root = nullptr;
            return temp;

        }
        else if(root->right==nullptr)
        {
            TreeNode* temp = root->left;
            delete root->pet;
            delete root;
            root=nullptr;
            return temp;
        }
        //Case 3: where Node has two children
        else
         {
            //succ has the nodes inorder successor value
            TreeNode* succ = findMin(root->right);
            //creating a new pet with the succ name and age so when the succ pet is deleted the root still has a pet
            Pet* p = new Pet(succ->pet->name, succ->pet->age);
            //setting root pet to new pet p
            root->pet = p;
            //use recusrion to delete succ and succ pet
            root->right = Delete(root->right, succ->pet->age);
        }
    }
       
    return root;
}
/*
destroyTree destroys the whole BST 
and returns a null pointer
*/
ShelterBST::TreeNode* ShelterBST::destroyTree(TreeNode* root)
{
    if(root==nullptr)
    {
        return nullptr;
    }

    root->left = destroyTree(root->left);
    root->right = destroyTree(root->right);

    delete root->pet;

    delete root;

    return nullptr;

}



//Public Methodsf5

/*
calls on private insert pet method to insert pet to BST
*/
void ShelterBST::insertPet(string name, int age)
{
    Pet* pet = new Pet(name, age);
    root = insert(root, pet);
}
/*
calls on private search method to search for pet with this age.
It will print out results of search.
*/
void ShelterBST::searchPet(int age)
{
    TreeNode* result = search(root, age);

    if(result != nullptr)
    {
        cout << "found " << result->pet->name << " age " << result->pet->age << "!" << endl;
    }
    else
    {
        cout << "no matching pet found" << endl;
    }
}
/*
calls on private inorder method and prints out what is it doing
*/
void ShelterBST::inorderDisplay()
{
    cout << "Inorder Traversal: " << endl;
    inorder(root);
}
/*
calls on private preorder method and prints out what is it doing
*/
void ShelterBST::preorderDisplay()
{
    cout << "Preorder Traversal: " << endl;
    preorder(root);
}
/*
calls on private postorder method and prints out what is it doing
*/
void ShelterBST::postorderDisplay()
{
    cout << "Postorder Traversal: " << endl;
    postorder(root);
}
/*
calls on private findParent method and 
prints out result.
*/
void ShelterBST::parent(int age)
{
    TreeNode* result = findParent(root, age);
    cout << "The parent of the your pet is: " << result->pet->name << " with age: " << result->pet->age << endl;
}
/*
calls on private succesor method and 
prints out result.
*/
void ShelterBST::successor(int age)
{
    TreeNode* result = succesor(root, age);
    cout << "The inorder successor of the your pet is: " << result->pet->name << " with age: " << result->pet->age << endl;
}
/*
calls on private numOfNodes method and 
prints out result.
*/
void ShelterBST::numOfNodes()
{
    int num = numOfNodes(root);// is this right?

    cout << "The number of nodes in your tree: " << num << endl;
}
/*
calls on private numOfLeafNodes method and 
prints out result.
*/
void ShelterBST::numOfLeafNodes()
{
    int num = numOfLeafNodes(root);// is this right?

    cout << "The number of leaf nodes in your tree: " << num << endl;
}
/*
calls on private numOfLevelNodes method and 
prints out result.
*/
void ShelterBST::numOfLevelNodes(int level)
{
    int num = numOfLevelNodes(root, level);// is this right?

    cout << "The number of nodes on level " << level << " is: " << num << endl;
}
/*
calls on private height method and 
prints out result.
*/
void ShelterBST::height()
{
    int num = height(root);// is this right?

    cout << "The height of your tree: " << num << endl;
}
/*
calls on private isBalanced method and 
prints out result.
*/
void ShelterBST::isBalanced()
{
    bool bal = isBalanced(root);// is this right?

    if(bal == true)
    {
        cout << "The Tree is Balanced." << endl;
    }
    else
    {
        cout << "The Tree is not Balanced." << endl;
    }
    
}
/*
calls on private Delete method 
to delete node
*/
void ShelterBST::Delete(int age)
{
    cout << "Deleting pet with age " << age << endl;
    root = Delete(root, age);
}
/*
calls on private destroyTree method 
to destroy tree
*/
void ShelterBST::destroyTree()
{
    cout << "Destroying Binary Search Tree" << endl;
    root = destroyTree(root);
}

