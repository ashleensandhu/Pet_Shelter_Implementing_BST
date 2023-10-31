/* ShelterBST.h Class declarations */
#ifndef SHELTERBST_H
#define SHELTERBST_H
#include <string>

class ShelterBST 
{
    private:
    // Pet and TreeNode struct declaration
        struct Pet
        {
          std::string name;
          int age;

         // constructor
          Pet(std::string n, int a)
          {
             name = n;
             age = a;
          }
        };

      struct TreeNode
      {
         Pet* pet; // Pet pointer
         TreeNode* left;
         TreeNode* right;
         
         //TreeNode constructor
         TreeNode(Pet* p)
         {
            pet = p;
            left = nullptr;
            right = nullptr;
         }
      };

    TreeNode* root;
    // private function declarations (prototypes)

    TreeNode* insert(TreeNode* root, Pet* pet);

    TreeNode* search(TreeNode *root, int age);

    void inorder(TreeNode * root);

    void preorder(TreeNode * root);

    void postorder(TreeNode * root);

    TreeNode* findParent(TreeNode *root, int age);

    //succesor helper function
    TreeNode* findMin(TreeNode* root);

    TreeNode* succesor(TreeNode* root, int age);

    int numOfNodes(TreeNode* root);

    int numOfLeafNodes(TreeNode* root);

    int numOfLevelNodes(TreeNode* root, int level, int currentLevel=0);

    int height(TreeNode*root);

    bool isBalanced(TreeNode* root);

    TreeNode* Delete(TreeNode* root, int age);

    TreeNode* destroyTree(TreeNode* root);

    public:
    // public function declarations (prototypes)
    ShelterBST();

    void insertPet(std::string name, int age);

    void searchPet(int age);

    void inorderDisplay();

    void preorderDisplay();

    void postorderDisplay();

    void parent(int age); 

    void successor(int age);

    void numOfNodes();

    void numOfLeafNodes();

    void numOfLevelNodes(int level);

    void height();

    void isBalanced();

    void Delete(int age);

    void destroyTree();



};

#endif
