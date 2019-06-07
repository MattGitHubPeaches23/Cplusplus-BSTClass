// Copyright (c) 2019, Matthew Chalifoux.
#include "bstclass.h"
template<typename T>
BST<T>::BST(const T *sorted_list, int size){
    //cout << "got here" << endl;
    int *klp;
    int i = 0;
    while(sorted_list[i] != NULL){
        //cout << "a[i] = " << sorted_list[i] << endl;
        ++i;
    }
    //cout << "i = " << i << endl;
    int middle = i/2;
    //cout << "middle = " << middle << endl;

    tree_node<T> *ptr, *head, *follow, *follow2;
    ptr = new tree_node<T>(sorted_list[middle]);
    head = ptr;
    follow = ptr;
    follow2 = ptr;
    //cout << "ptr->item = " << ptr->_item << endl;
    for(int j = middle - 1; j >= 0; --j){
        follow->_left = new tree_node<T>(sorted_list[j]);
        follow = follow->_left;
    }
    for(int j = middle + 1; j < i; ++j){
        follow2->_right = new tree_node<T>(sorted_list[j]);
        follow2 = follow2->_right;
    }
    root = ptr;
}
template<typename T>
BST<T>& BST<T>::operator +=(const BST<T>& rhs){
    tree_add(root,rhs.root);
}
template<typename T>
void BST<T>::tree_add(tree_node<T>* & dest, const tree_node<T>* src){
    //cout << "scr->item = " << src->_item << endl;
    tree_insert(dest,src->_item);
    if(src->_left != NULL){
        tree_add(dest,src->_left);
    }
    if(src->_right != NULL){
        tree_add(dest,src->_right);
    }
}
template<typename T>
BST<T>::~BST(){
    if(root != NULL){
        Tree_Clear();
    }
}
template<typename T>
BST<T>::BST(){
    root = NULL;
}
template<typename T>
BST<T>::BST(const BST<T>& copy_me){
    if(copy_me.root == NULL){
        root = NULL;
    }
    else if(copy_me.root != NULL){
        BST<T> *sub;
        sub = new BST<T>;
        tree_node<T> *ptr, *rtptr;
        ptr = new tree_node<T>;
        ptr->_item = copy_me.root->_item;
        rtptr = copy_me.root;
    //    sub->root = tester;
    //    ptr = sub;
        copy(ptr,rtptr);
        root = ptr;
    }
}
template<typename T>
BST<T>& BST<T>::operator =(const BST<T>& rhs){
    if(rhs.root == NULL){
        //cout << "follow" << endl;
        root = NULL;
    }
    else if(rhs.root != NULL){
        //cout << "follow2" << endl;
        BST<T> *sub;
        sub = new BST<T>;
        tree_node<T> *ptr, *rtptr;
        ptr = new tree_node<T>;
        ptr->_item = rhs.root->_item;
        rtptr = rhs.root;
    //    sub->root = tester;
    //    ptr = sub;
//        cout << "follow3" << endl;
//        cout << "rhs.root->item = " << rhs.root->_item << endl;
        copy(ptr,rtptr);
        //cout << "Follow4" << endl;
        root = ptr;
    }
}
template<typename T>
void BST<T>::copy(tree_node<T>* &ptr,tree_node<T>* &rtptr){
    //Makes a copy of a tree_node
    if(rtptr->_left == NULL){

        if(rtptr->_right != NULL){
            tree_node<T> *test;
            test = new tree_node<T>;
            ptr->_right = test;
            copy(ptr->_right,rtptr->_right);
        }
        if(rtptr->_right == NULL){
        //make a copy of a node here
            ptr->_item = rtptr->_item;
            return;
        }
    }
    if(rtptr->_left != NULL){
        tree_node<T> *test;
        test = new tree_node<T>;
        ptr->_left = test;
        copy(ptr->_left,rtptr->_left);
    }
    //in middle, copy middle node, or root node
    ptr->_item = rtptr->_item;
    if(rtptr->_right == NULL){

        if(rtptr->_left != NULL){
            tree_node<T> *test;
            test = new tree_node<T>;
            ptr->_left = test;
            copy(ptr->_left,rtptr->_left);
        }
        if(rtptr->_left == NULL){
        ptr->_item = rtptr->_item;
            return;
        }
    }
    if(rtptr->_right != NULL){
        tree_node<T> *test;
        test = new tree_node<T>;
        ptr->_right = test;
        copy(ptr->_right,rtptr->_right);
    }
}
template<typename T>
void BST<T>::print(){
    tree_print(root);
}
template<typename U>
ostream& operator <<(ostream& outs, const BST<U>& tree){
    BST<U> test;
    test = tree;
    test.tree_print(test.root);
    cout << "*********************************" << endl;
//    tree_print_debug(tree.root);
}
template<typename T>
void BST<T>::tree_print(tree_node<T>* root, int level,
                                    ostream& outs){
    if(root == NULL){
        return;
    }
    if(root->_right != NULL){
        tree_print(root->_right,level + 1);
    }
    outs << setw(level * 4) << *root << endl;
    if(root->_left != NULL){
        tree_print(root->_left,level + 1);
    }
}
template<typename T>
void BST<T>::tree_print_debug(tree_node<T>* root, int level,
                                    ostream& outs){
    if(root == NULL){
        return;
    }
    if(root->_right != NULL){
        tree_print_debug(root->_right,level + 1);
    }
    outs << setw(level * 4) << "|" << root << "|" << endl;
    if(root->_left != NULL){
        tree_print_debug(root->_left,level + 1);
    }
}
template<typename T>
void BST<T>::clear_tree(tree_node<T>* &root, tree_node<T>* &b4root, char &direction){
    //Clears the Tree
    if(root->_left != NULL || root->_right != NULL){
        if(root->_left != NULL){
            direction = 'L';
            clear_tree(root->_left,root,direction);
        }
        if(root->_right != NULL){
            direction = 'R';
            clear_tree(root->_right,root,direction);
        }
    }
    tree_node<T> *ptr;
    ptr = root;
    //cout << "root->item = " << root->_item << endl;
    delete ptr;
    root = NULL;
}
template<typename T>
void BST<T>::Tree_Clear(){
    if(root != NULL){
        tree_node<T> *ptr, *b4ptr, *thrd;
        thrd = root;
        ptr = root;
        b4ptr = root;
        char direction = '\0';
        clear_tree(ptr,b4ptr,direction);
        //cout << "YU555" << endl;
        //tree_print(ptr);
        //tree_print_debug(ptr);
        //cout << "YU555" << endl;
        root = ptr;
    }
}
template<typename T>
bool BST<T>::search(const T& target, tree_node<T>* & found_ptr){
    tree_node<T> *ptr;
    ptr = found_ptr;
    if(ptr == NULL){
        cout << "target not found" << endl;
        return false;
    }
    if(target == ptr->_item){
        cout << "target found " << *ptr << endl;
        return true;
    }
    if(target < ptr->_item){
        return search(target,ptr->_left);
    }
    if(target > ptr->_item){
        return search(target, ptr->_right);
    }
}
template<typename T>
bool BST<T>::PreSearch(const T& target){
    tree_node<T>*sub;
    sub = root;
    if(search(target,sub)){
        return true;
    }
}
template<typename T>
void BST<T>::erase(const T& target){
    tree_erase(root,target);
}
template<typename T>
bool BST<T>::tree_erase(tree_node<T>*& root, const & target){
    if(root == NULL){
        return false;
    }
    if(target > root->_item){
        return tree_erase(root->_right,target);
    }
    if(target < root->_item){
        return tree_erase(root->_left, target);
    }
    if(target == root->_item){
        if(root->_left == NULL){
            tree_node<T> *ptr;
            ptr = root;
            root = root->_right;
            cout << "erasing " << ptr->_item << endl;
            delete ptr;
            return true;
        }
        if(root->_left != NULL)
        // Current node has a left subtree
        {
            if(root->_left->_left == NULL && root->_left->_right == NULL)
            // If roots leftnode has nothing underneath it, works
            {
                cout << "erasing " << root->_item << endl;
                root->_item = root->_left->_item;
                tree_node<T> *ptr;
                ptr = root->_left;
                delete ptr;
                root->_left = NULL;
                return true;
            }
            if(root->_left->_right == NULL && root->_left->_left != NULL)
            // If roots leftnode has something under leftnode, works
            {
                tree_node<T> *ptr;
                ptr = root->_left;
                root->_item = root->_left->_item;
                root->_left = root->_left->_left;
                cout << "erasing " << ptr->_item << endl;
                delete ptr;
                return true;
            }
            if(root->_left->_right != NULL){
                tree_node<T> *prev, *here, *ptr;
                prev = root->_left;
                here = root->_left->_right;
                while(here->_right != NULL){
                    here = here->_right;
                    prev = prev->_right;
                }
                if(here->_right == NULL){
                    root->_item = here->_item;
                    prev->_right = here->_left;
                    ptr = here;
                    cout << "erasing " << ptr->_item << endl;
                    delete ptr;
                    return true;
                }
            }
        }
    }
}
template<typename T>
void BST<T>::insert(const T &insert_me){
    tree_insert(root,insert_me);
}
template <typename T>
void BST<T>::tree_insert(tree_node<T>* &root, const T& insert_me){
    if(root == NULL){
        root = new tree_node<T>(insert_me);

        return;//0
    }
    tree_node<T> *ptr;
    ptr = root;
    if(insert_me < ptr->_item){
        tree_insert(ptr->_left,insert_me);
        root->update_height();
        root->balance_factor();
    }
    else if(insert_me > ptr->_item){
        tree_insert(ptr->_right,insert_me);
        root->height();
        root->balance_factor();
    }
}
