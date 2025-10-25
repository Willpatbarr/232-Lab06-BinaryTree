/***********************************************************************
 * Header:
 *    BINARY NODE
 * Summary:
 *    One node in a binary tree (and the functions to support them).
 *      __       ____       ____         __
 *     /  |    .'    '.   .'    '.   _  / /
 *     `| |   |  .--.  | |  .--.  | (_)/ /
 *      | |   | |    | | | |    | |   / / _
 *     _| |_  |  `--'  | |  `--'  |  / / (_)
 *    |_____|  '.____.'   '.____.'  /_/
 *
 *
 *    This will contain the class definition of:
 *        BNode         : A class representing a BNode
 *    Additionally, it will contain a few functions working on Node
 * Author
 *    <your names here>
 ************************************************************************/

#pragma once

#include <iostream>  // for OFSTREAM
#include <cassert>

/*****************************************************************
 * BNODE
 * A single node in a binary tree.  Note that the node does not know
 * anything about the properties of the tree so no validation can be done.
 *****************************************************************/
template <class T>
class BNode
{
public:
   //
   // Construct
   //
   BNode() : data(), pLeft(nullptr), pRight(nullptr), pParent(nullptr) {}
   
   BNode(const T& t) : data(t), pLeft(nullptr), pRight(nullptr), pParent(nullptr) {}
   
   BNode(T&& t) : data(std::move(t)), pLeft(nullptr), pRight(nullptr), pParent(nullptr) {}
   
   //
   // Data
   //
   BNode <T>* pLeft;
   BNode <T>* pRight;
   BNode <T>* pParent;
   T data;
};

/*******************************************************************
 * SIZE BTREE
 * Return the size of a b-tree under the current node
 *******************************************************************/
template <class T>
inline size_t size(const BNode <T> * p)
{
   // if the pointer doesn't actually exist then the size of the tree after that node is zero
   if (!p)
   {
      return 0;
   } else {
      // recursively go through each of the nodes in the tree till we hit the bottom
      // start with 1 because of the current node
      size_t treeSize = 1 + size(p->pLeft) + size(p->pRight);
      //start the return stack to send back to top
      return treeSize;
   }
}


/******************************************************
 * ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
template <class T>
inline void addLeft(BNode <T> * pNode, BNode <T> * pAdd)
{
   // if the node doesn't exist just return
   if (!pNode)
   {
      return;
   } else {
      // if homeboy does then make pLeft pAdd
      pNode->pLeft = pAdd;
   }
   if (pAdd) {
      //if pAdd also exists then make it's parent pNode
      pAdd->pParent = pNode;
   }
   
}

/******************************************************
 * ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
template <class T>
inline void addRight (BNode <T> * pNode, BNode <T> * pAdd)
{
   // if the node doesn't exist just return
   if (!pNode)
   {
      return;
   } else {
      // if homeboy does then make pLeft pAdd
      pNode->pRight = pAdd;
   }
   if (pAdd) {
      //if pAdd also exists then make it's parent pNode
      pAdd->pParent = pNode;
   }
   
}

/******************************************************
 * ADD LEFT
 * Add a node to the left of the current node
 ******************************************************/
template <class T>
inline void addLeft (BNode <T> * pNode, const T & t)
{
   //return early if nonexistent
   if (!pNode)
   {
      return;
   }
   // copy the node
   BNode<T>* pNew = new BNode<T>(t);
   // hook the nodes up to each other
   pNode->pLeft = pNew;
   pNew->pParent = pNode;
   
}

template <class T>
inline void addLeft(BNode <T>* pNode, T && t)
{
   //return early if nonexistent
   if (!pNode)
   {
      return;
   }
   // move the node instead of copying it
   BNode<T>* pNew = new BNode<T>(std::move(t));
   // hook the nodes up to each other
   pNode->pLeft = pNew;
   pNew->pParent = pNode;
   
}

/******************************************************
 * ADD RIGHT
 * Add a node to the right of the current node
 ******************************************************/
template <class T>
void addRight (BNode <T> * pNode, const T & t)
{
   //return early if nonexistent
   if (!pNode)
   {
      return;
   }
   // copy the node
   BNode<T>* pNew = new BNode<T>(t);
   // hook the nodes up to each other
   pNode->pRight = pNew;
   pNew->pParent = pNode;
   
}

template <class T>
void addRight(BNode <T>* pNode, T && t)
{
   //return early if nonexistent
   if (!pNode)
   {
      return;
   }
   // move the node instead of copying it
   BNode<T>* pNew = new BNode<T>(std::move(t));
   // hook the nodes up to each other
   pNode->pRight = pNew;
   pNew->pParent = pNode;
   
}

/*****************************************************
 * DELETE BINARY TREE
 * Delete all the nodes below pThis including pThis
 * using postfix traverse: LRV
 ****************************************************/
template <class T>
void clear(BNode <T> * & pThis)
{
   // return early on null
   if(!pThis)
   {
      return;
   }
   
   // clear both hijos of the node
   clear(pThis->pLeft);
   clear(pThis->pRight);
   
   //deconsttruct the object
   delete pThis;
   //set the pointer to null
   pThis = nullptr;

}

/***********************************************
 * SWAP
 * Swap the list from LHS to RHS
 *   COST   : O(1)
 **********************************************/
template <class T>
inline void swap(BNode <T>*& pLHS, BNode <T>*& pRHS)
{
   
}

/**********************************************
 * COPY BINARY TREE
 * Copy pSrc->pRight to pDest->pRight and
 * pSrc->pLeft onto pDest->pLeft
 *********************************************/
template <class T>
BNode <T> * copy(const BNode <T> * pSrc)
{
   return new BNode<T>;
}

/**********************************************
 * assign
 * copy the values from pSrc onto pDest preserving
 * as many of the nodes as possible.
 *********************************************/
template <class T>
void assign(BNode <T> * & pDest, const BNode <T>* pSrc)
{
   
}
