#include<iostream>

using namespace std;

class TreeNode {
  public:
    int info;
    TreeNode *left, *right;
    TreeNode() {
      left = right = NULL;
    }
    TreeNode(int iData); {
      iInfo = iData;
      left = right = NULL;
    }
}

class BST {
  private:
    TreeNode *root;
  public:
    BST() {
      root = NULL;
    }
    ~BST(){}
    bool searchnode (int iValue) {
      TreeNode *pP = root;
      while (pP != NULL) {
        if (pP ->  iInfo == iValue)
          return true
        else
          pP = (pP -> iInfo > iValue ? pP -> left: pP -> right);
      }
      return false;
    }
    inorder() {
      displayinorder(root);
    }
    displayinorder(TreeNode * pR) {
      if (pR != NULL) {
        displayinorder (pR -> left);
        cout << pR -> iInfo;
        displayinorder (pR -> right);
      }


    }
    /* Process to insert node:
        The new value doesnt exist, the new node will be a leaf node.
       Procedure:
        Search for the parent node, add node.
    */
    TreeNode *findparent(int iValue) {
      TreeNode *pParent, *pChild;
      pChild = root;
      pParent = NULL;
      while (pChild != NULL && pChild -> iInfo != iValue){
        pParent = pChild;
        pChild = (pChild -> iInfo > iValue? pChild -> left : pChild -> right)
      }
      return pParent;
    }
    void add(int iValue) {
      TreeNode *pParent = findparent(iValue);
      TreeNode *pNew = new TreeNode(iValue);
      if (pParent == NULL) {
        root = pNew;
      }
      else {
        if (pParent -> iInfo > iValue)
          pParent -> left = pNew;
        else
          pParent -> right = pNew;
      }
    }
    /* Process to delete node:
        Leaf Node:
          Search parent node
          disconect
          Free node
        Node with 1 child:
          Search parent node
          Connect child with the current node's parent
          Free node
        Node with 2 childs:
          Locate the predecesor or successor node of the current node
          Copy the info
          delete predecesor or successor according to the case
       Procedure:
        Search for the parent node, add node.
    */
    TreeNode *predecesor(TreeNode *pActual) { // pActual points to the node to errase
      TreeNode *pP = pActual -> left;
      while (pP -> right != NULL)
        pP = pP -> right;
      return pP;
    }
    TreeNode *successor(TreeNode *pActual) { // pActual points to the node to errase
      TreeNode *pP = pActual -> left;
      while (pP -> left != NULL)
        pP = pP -> left;
      return pP;
    }
    void deleteelem(int iValue) {
      TreeNode *pParent = findparent(iValue);
      TreeNode *pDelete;
      if (pParent == NULL)
        pDelete = root;
      else
        pDelete = (pParent -> iInfo > iValue ? pParent -> left : pParent -> right)

      // find substitute when the node to delete has 2 childs
      if (pDelete -> left != NULL && pDelete -> right != NULL) {
        TreeNode *pSubstitute = predecesor(pDelete);
        int iNewValue = pSubstitute -> iInfo;
        deleteelem(pSubstitute -> iInfo);
        pDelete -> iInfo = iNewValue;
      }
      // Delete root with 1 child.
      else if (pParent == NULL) {
        if (pDelete -> right == NULL)
          root = pDelete -> left;
        else
          root = pDelete -> right;
      }
      // Delete node with 0 or 1 child
      else if (pParent -> iInfo > iValue) {
        if (pDelete -> left == NULL)
          pParent -> left = pDelete -> right;
        else
          pParent -> left = pDelete -> left;

        else if (pDelete -> right == NULL)
          pParent -> right = pDelete -> left;
        else
          pParent -> right = pDelete -> right;
      }


    }
}
