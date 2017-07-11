#include <iostream>

class Node
{
  public:
    Node*next;
    int iInfo;

    Node () {
      next = NULL;
    }
    Node (int iD) {
      iInfo = iD;
      next = NULL;
    }
    Node (int iD, Node*pNextNode) {
      iInfo = iD;
      next = pNextNode;
    }
};
