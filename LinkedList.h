#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList {
  public:
      Node* pHead;

  public:
      LinkedList() {
        pHead = NULL;
      }

      bool EmptyList () {
        return (pHead == NULL);
      }

      Node getHead() {
        return *pHead;
      }

      void setHead(int iData) {
        pHead = new Node(iData);
      }

      void AddStart (int iData) {
        Node*pNew = new Node (iData, pHead);
        pHead = pNew;
      }

      void AddLast(int iData) {
        if (EmptyList())
          setHead(iData);
        else {
          Node*pN = pHead;
          while (pN != NULL) {
            pN = pN -> next;
          }
          pN -> next = new Node(iData);
        }
      }

      int countNodes() {
        int icount = 0;
        Node*pN = pHead;
        while (pN != NULL) {
          icount++;
          pN = pN -> next;
        }
        return icount;
      }

      ~LinkedList() {
        while (pHead != NULL) {
          Node*pN = pHead;
          pHead = pHead -> next;
          delete pN;
        }
      }

      bool LinkedListfind(int iData) {
        Node*pN = pHead;
        while (pN != NULL && pN -> iInfo != iData) {
          pN = pN -> next;
        }
        return pN != NULL;
      }

      void DeleteFirst() {
        Node*pN = pHead;
        pHead = pHead -> next;
        delete pN;
      }

      void DeleteLast() {
        Node*pBefore = NULL;
        Node*pActual = pHead;
        while (pActual -> next != NULL) {
          pBefore = pActual;
          pActual = pActual -> next;
        }
        if (pBefore == NULL) {
          pHead = NULL;
        }
        else {
          pBefore -> next = NULL;
        }
        delete pActual;
      }

      void Deleteinfo(int iData) {
        Node*pBefore = NULL;
        Node*pActual = pHead;
        while (pActual != NULL && pActual -> iInfo != iData) {
          pBefore = pActual;
          pActual = pActual -> next;
        }
        if (pActual != NULL) {
          if (pBefore == NULL) {
            pHead = pHead -> next;
          } else {
            pBefore -> next = pActual -> next;
          }
          delete pActual;
        }
      }

      void printLinkedList() {
        Node*pN = pHead;
        while (pN != NULL){
          cout << pN -> iInfo << " ";
          pN = pN -> next;
        } cout << endl;
      }
};
