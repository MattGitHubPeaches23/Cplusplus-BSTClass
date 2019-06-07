// Copyright (c) 2019, Matthew Chalifoux.
#ifndef BSTCLASS_H
#define BSTCLASS_H
#include <iostream>
#include <iomanip>
using namespace std;
template <typename T>
struct tree_node{
    T _item;
    tree_node<T>* _left;
    tree_node<T>* _right;
    int _height;
    int balance_factor(){
        //balance factor = height of the left subtree
        //                        - the height of the right subtree
        //a NULL child has a height of -1
        //a leaf has a height of 0
        int balance, subleft, subright, leftchild,rightchild;
        if(_left != NULL){
            leftchild = _left->_height;
        }
        if(_right != NULL){
            rightchild = _right->_height;
        }
        if(_left == NULL){
            leftchild = -1;
        }
        if(_right == NULL){
            rightchild = -1;
        }
        balance = leftchild - rightchild;
//        cout << "_item = " << _item << endl;
//        cout << "balance = " << balance << endl;
    }

    int height(){
        // Height of a node is 1 + height of the "taller" child
        //A leaf node has a height of zero: 1 + max(-1,-1)-
        if((_right->_height + 1) < _height){

        }
        else if(_right->_height + 1 > _height){
            _height = _right->_height + 1;
//            cout << "_item = " << _item << endl;
//            cout << "height = " << _height << endl;
        }
    }
    int update_height(){
        //set the _height member variable (call height();)
        //cout << "Anyone home " << endl;
        if((_left->_height + 1) < _height){

        }
        else if(_left->_height + 1 > _height){
            _height = _left->_height + 1;
//            cout << "_item = " << _item << endl;
//            cout << "_height = " << _height << endl;
        }
    }
    tree_node(T item=T(), tree_node* left=NULL,
                              tree_node* right=NULL):
                        _item(item), _left(left), _right(right){
            //don't forget to set the _height.
        _height = 0;
        }
    template<typename U>
    friend ostream& operator <<(ostream& outs,
                                    const tree_node<U>& t_node){
            outs<<"|"<<t_node._item<<"|";
        }
};
template <typename T>
class BST{
public:
 BST();
 BST(const T* sorted_list, int size=-1);

 //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

 BST(const BST<T>& copy_me);
 BST<T>& operator =(const BST<T>& rhs);
 ~BST();

 //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
 void tree_add(tree_node<T>* & dest, const tree_node<T>* src);
 bool tree_erase(tree_node<T>*& root, const & target);
 void erase(const T& target);
 bool PreSearch(const T& target);
 bool search(const T& target, tree_node<T>* & found_ptr);
 void Tree_Clear();
 void clear_tree(tree_node<T>* &root, tree_node<T>* &b4root, char &direction = '\0');
 void tree_insert(tree_node<T>* &root, const T& insert_me);
 void copy(tree_node<T>* &ptr,tree_node<T>* &rtptr);
 void insert(const T& insert_me);
 void print();
 void tree_print(tree_node<T>* root, int level = 0,
                                     ostream& outs = cout);
 void tree_print_debug(tree_node<T>* root, int level = 0,
                                     ostream& outs = cout);
 template<typename U>
 friend ostream& operator <<(ostream& outs, const BST<U>& tree);
 BST<T>& operator +=(const BST<T>& rhs);
private:
 tree_node<T>* root;
};
#endif // BSTCLASS_H
