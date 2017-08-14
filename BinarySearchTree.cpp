#include<iostream>
#include <queue>
#include<list>

using namespace std;

class TreeNode {
  public:
    int iInfo;
    TreeNode *left, *right;
    TreeNode() {
      left = right = NULL;
    }
    TreeNode(int iData) {
      iInfo = iData;
      left = right = NULL;
    }
};

class BST {
  private:
    TreeNode *root;
  public:
    BST() {
      root = NULL;
    }
    ~BST() {}
    bool searchnode (int iValue) {
      TreeNode *pP = root;
      while (pP != NULL) {
        if (pP ->  iInfo == iValue)
          return true;
        else
          pP = (pP -> iInfo > iValue ? pP -> left: pP -> right);
      }
      return false;
    }
    void inorder() {
      displayinorder(root);
    }
    void displayinorder(TreeNode *pR) {
      if (pR != NULL) {
        displayinorder (pR -> left);
        cout << pR -> iInfo;
        displayinorder (pR -> right);
      }
    }
    void PrintTreebyLevels() {
      BreadthFirstTravseral(root);
    }
    void BreadthFirstTravseral(TreeNode *pR) {
      if (root == NULL)
          return;
      queue<TreeNode*> q;
      q.push(root);
      while (!q.empty())
       {
         // nodeCount (queue size) indicates number of nodes at current level.
         int nodeCount = q.size();
         if (nodeCount == 0)
          break;

         // Dequeue all nodes of current level and Enqueue all nodes of next level
         while (nodeCount > 0)
         {
           TreeNode *node = q.front();
           cout << node->iInfo << " ";
           q.pop();
           if (node->left != NULL)
               q.push(node->left);
           if (node->right != NULL)
               q.push(node->right);
           nodeCount--;
         }
         cout << endl;
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
        pChild = (pChild -> iInfo > iValue? pChild -> left : pChild -> right);
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
    // pActual points to the node to errase
    TreeNode *predecesor(TreeNode *pActual)  {
      TreeNode *pP = pActual -> left;
      while (pP -> right != NULL)
        pP = pP -> right;
      return pP;
    }
    // pActual points to the node to errase
    TreeNode *successor(TreeNode *pActual) {
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
        pDelete = (pParent -> iInfo > iValue ? pParent -> left : pParent -> right);

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
        if (pDelete -> left == NULL){
            pParent -> left = pDelete -> right;
        }
        else if (pDelete -> left != NULL) {
          pParent -> left = pDelete -> left;
        }
        else if (pDelete -> right == NULL) {
          pParent -> right = pDelete -> left;
        }
        else if (pDelete -> right != NULL) {
          pParent -> right = pDelete -> right;
        }
      }
    }

};

TreeNode insert(TreeNode *root,  TreeNode *node){
  if (root == NULL)
    return node;
  if (node -> iInfo <= root -> iInfo)
    root -> left = insert(root -> left, node);
  if (node -> iInfo > root -> iInfo)
    root -> right = insert(root -> right, node);
  return root;
} // logn

void findNode(TreeNode *root, int iValue) {
  if (root == NULL)
    return NULL;
  if (root -> iInfo == iValue)
    return root;
  if (iValue < root -> iInfo)
    findNode(root -> left, iValue);
  else
    findNode(root -> right, iValue)
} //logn

void mirrorBST (TreeNode *root) {
  if (root == NULL)
    return;
  mirrorBST(root -> left);
  mirrorBST(root -> right);
  TreeNode *temp = root -> left;
  root -> left = root -> right;
  root -> right = temp;
}

int maxDepth(TreeNode *root) {
  if (root == NULL)
    return 0;
  if (root -> left == NULL && root ->right == NULL) // If leaf node
    return 0;
  int leftMax = 1 + maxDepth(root -> left);
  int rightMax = 1 + maxDepth(root -> right);
  return max(leftMax, rightMax);
}

int UniqueTrees(int NumberNodes) {
  if (NumberNodes <= 1)
    return 1;
  for (int i = 1; i < NumberNodes; i++) {
    int countLeftTrees = UniqueTrees(i - 1);
    int countRightTree = UniqueTrees(NumberNodes - 1);
    sum = sum + (countRightTree * countLeftTrees);
  }
  return sum;
}

void printRannge(TreeNode * Node, int low, int high) {
  if (root == NULL)
    return;
  if (low <= root -> iInfo) {
    printRannge(root -> left, low, high);
  }
  if (low <= root -> iInfo && root -> iInfo <= high) {
    cout << root -> iInfo << " ";
  }
  if (high > root -> iInfo){
    printRannge(root -> right, low, high);
  }
}

bool checkIfBST(TreeNode *root, int min, int max) {
  if (root == NULL)
    return true;
  if (root -> iInfo <= min || root -> iInfo > max)
    return false;
  return (checkIfBST(root -> left, min, root -> iInfo) &&
    checkIfBST(root ->> right, root -> iInfo, max));
}

bool hasPathSum(TreeNode *root, int sum) {
  if (root -> left == NULL && root -> right == NULL)
    return (summ == root -> iInfo)
  int subsum = sum - root -> iInfo;
  if (root -> left != NULL) {
    bool hasPathSum = hasPathSum(root -> left, subsum);
    if (hasPathSum)
      return true;
  }
  if (root -> right != NULL) {
    bool hasPathSum = hasPathSum(root -> right, subsum);
    if (hasPathSum)
      return true;
  }
  return false;







}

void printPath(TreeNode *root, List<TreeNode> pathlist) {
  if (root == NULL)
    return;
  pathlist.insert(root);
  printPath(root -> left, pathlist);
  printPath(root -> right, pathlist);
  if (root -> left == NULL && root -> right == NULL)
    printlist(pathlist);
  pathlist.remove(root);
}

TreeNode leastcommonancestor(TreeNode *root, TreeNode *a, TreeNode *b) {
  if (root == NULL)
    return NULL;
  if (root == a || root == b)
    return root;
  TreeNode *LeftLCA = leastcommonancestor(root -> left, a, b);
  TreeNode *RightLCA = leastcommonancestor(root -> right, a, b);
  if (LeftLCA != NULL && RightLCA != NULL)
    return root;
  if (LeftLCA != NULL)
    return LeftLCA;
  return RightLCA;
}

bool compareBST(TreeNode *a, TreeNode *b) {
  if (a == NULL && b == NULL)
    return true;
  if (a != NULL && b != NULL) { //both not empty
    return (a -> iInfo == b -> iInfo &&
      compareBST(a -> left, b ->left) &&
      compareBST(a -> right, b -> right));
  }
  return false;
}

int BSTheight(TreeNode *root) {
  if (root == NULL)
    return 0;
  return (1 + max(BSTheight(root -> left), BSTheight(root -> right)));
}

bool isBalanced(TreeNode *root) {
  int lh, rh;
  if (root == NULL)
    return true;
  lh = BSTheight(root -> left);
  rh = BSTheight(root -> right);
  if (abs(lh - rh) <= 1 && isBalanced(root -> left) && isBalanced(root -> right))
    return true;
}


int main () {
  BST myBST;
  myBST.add(3);
  myBST.add(5);
  myBST.add(4);
  myBST.add(2);
  myBST.add(1);
  myBST.add(6);

  cout << "Print tree inorder as list: ";
  myBST.inorder();
  cout << endl;

  if (myBST.searchnode(3))
    cout << "Node with value 3 found" << endl;

  myBST.PrintTreebyLevels();
  cout << endl;

  myBST.deleteelem(5);
  cout << "Print tree inorder as list: ";
  myBST.inorder();
  cout << endl;
  myBST.PrintTreebyLevels();
  cout << endl;

  return 0;
}
