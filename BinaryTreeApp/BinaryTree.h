#pragma once
#include "BinaryTreeNode.h"
#include "Data.h"
template <class T>
class BinaryTree : public BinaryTreeNode<T>
{
private:
BinaryTreeNode<T>* root;
BinaryTreeNode<T> recursiveInsert(Data<T>& a, BinaryTreeNode<T>& current);
public:
BinaryTree<T>();
BinaryTree<T>(const BinaryTreeNode<T>& a);
BinaryTree<T>(const BinaryTree<T>& a);
~BinaryTree<T>();
BinaryTreeNode<T> getRoot();
void setRoot(BinaryTreeNode<T>& a);
void insert(Data<T>& a);
BinaryTreeNode<T> search(Data<T>& a);
BinaryTreeNode<T> recursiveSearch(Data<T>& a, BinaryTreeNode<T>& current);
bool deleteTree(Data<T>& a);
bool recursiveDelete(Data<T>& a, BinaryTreeNode<T>& current);
void Traverse();
void ReverseTraverse();
void InOrderTraverse(BinaryTreeNode<T>& current);
void ReverseInOrderTraverse(BinaryTreeNode<T>& current);
};
template<class T>
inline BinaryTree<T>::BinaryTree()
{
this->root = nullptr;
}
template<class T>
inline BinaryTree<T>::BinaryTree(const BinaryTreeNode<T>& a)
{
root->setData(a->getData());
}
template<class T>
inline BinaryTree<T>::BinaryTree(const BinaryTree<T>& a)
{
root->setData(a->getRoot()->getData());
}
template<class T>
inline BinaryTree<T>::~BinaryTree()
{
}
template<class T>
inline BinaryTreeNode<T> BinaryTree<T>::recursiveInsert(Data<T>& a, BinaryTreeNode<T>&
current)
{
if (current == nullptr)
{
current = new BinaryTreeNode<T>(a);
}
else
{
if (a < current->getData())
{
current->lst = recursiveInsert(a, current->lst);
}
else
{
current->rst = recursiveInsert(a, current->rst);
}
}
return current;
}
template<class T>
inline BinaryTreeNode<T> BinaryTree<T>::getRoot()
{
return root;
}
template<class T>
inline void BinaryTree<T>::setRoot(BinaryTreeNode<T>& a)
{
root = a;
}
template<class T>
inline void BinaryTree<T>::insert(Data<T>& a)
{
if (root == nullptr)
{
root = new BinaryTreeNode<T>(a);
}
else
{
root = recursiveInsert(a, &root);
}
}
template<class T>
inline BinaryTreeNode<T> BinaryTree<T>::search(Data<T>& a)
{
if (root == nullptr)
{
return 0;
}
else
{
return recursiveSearch(a, &root);
}
}
template<class T>
inline BinaryTreeNode<T> BinaryTree<T>::recursiveSearch(Data<T>& a, BinaryTreeNode<T>&
current)
{
if (current == nulptr)
{
return 0;
}
else if (current == a;)
{
return current;
}
else
{
if (a < current->getData())
{
return recursiveSearch(a, current->lst);
}
else
{
return recursiveSearch(a, current->rst);
}
}
}
template<class T>
inline bool BinaryTree<T>::deleteTree(Data<T>& a)
{
if (root == nullptr)
{
return false;
}
else
{
return recursiveDelete(a, &root);
}
}
template<class T>
inline bool BinaryTree<T>::recursiveDelete(Data<T>& a, BinaryTreeNode<T>& current)
{
if (current == nullptr)
{
return false;
}
else if (current->lst != nullptr && current->lst == a)
{
if (current->lst->lst != nullptr)
{
current->lst = current->lst->lst;
}
else
{
current->lst = current->lst->rst;
}
else
{
BinaryTreeNode<T> right = current->lst->rst;
BinaryTreeNode<T> left = current->lst->lst;
current->lst = nullptr;
insert(left->getData());
insert(right->getData());
}
return true;
}
else if (current->rst != nullptr && current->rst == a)
{
if (current->rst->lst == nullptr && current->rst->rst == nullptr)
{
current->rst == nullptr;
}
else if (current->rst->lst || current->rst->rst == nullptr)
{
if (current->rst->lst != nullptr)
{
current->rst = current->rst->lst;
}
else
{
current->rst = current->rst->rst;
}
}
else
{
BinaryTreeNode<T> right = current->rst->rst;
BinaryTreeNode<T> left = current->rst->lst;
current->rst = nullptr;
insert(left.getData());
insert(right.getData());
}
return true;
}
if (a < current->getData())
{
return recursiveDelete(a, current->lst);
}
else
{
return recursiveDelete(a, current->rst);
}
}
template<class T>
inline void BinaryTree<T>::Traverse()
{
if (root == nullptr)
{
return;
}
else
{
InOrderTraverse(root);
}
}
template<class T>
inline void BinaryTree<T>::ReverseTraverse()
{
if (root == nullptr)
{
return;
}
else
{
ReverseInOrderTraverse(root);
}
}
template<class T>
inline void BinaryTree<T>::InOrderTraverse(BinaryTreeNode<T>& current)
{
if (current == null)
{
return;
}
else
{
InOrderTraverse(current->lst);
std::cout << current->getData();
InOrderTraverse(current->rst);
}
}
template<class T>
inline void BinaryTree<T>::ReverseInOrderTraverse(BinaryTreeNode<T>& current)
{
if (current == nullptr)
return;
else
{
ReverseInOrderTraverse(current->rst);
}
std::cout << current->getData();
ReverseInOrderTraverse(current->lst);
}
