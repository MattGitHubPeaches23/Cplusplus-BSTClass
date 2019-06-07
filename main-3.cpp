// Copyright (c) 2019, Matthew Chalifoux.
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
        //Code to fnd the balance of a node here

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
        //Code to find height if from a right node and pick better height

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
        //Code to find height if from a right node and pick better height

        //set the _height member variable (call height();)
        //cout << "Anyone home " << endl;
        if((_left->_height + 1) < _height){

        }
        else if(_left->_height + 1 > _height){
            _height = _left->_height + 1;
        }
    }
    tree_node(T item=T(), tree_node* left=NULL,
                          tree_node* right=NULL):
                    _item(item), _left(left), _right(right)

    {
        _height = 0;
    }
    friend ostream& operator <<(ostream& outs,
                                const tree_node<T>& t_node){
        outs<<"|"<<t_node._item<<"|";
    }
};
template <typename T>
void tree_insert(tree_node<T>* &root, const T& insert_me);
template<typename T>
void tree_print(tree_node<T>* root, int level=0,
                                    ostream& outs=cout);

template<typename T>       //prints detailes info about each node
void tree_print_debug(tree_node<T>* root, int level=0,
                                          ostream& outs=cout);
template <typename T>       //clear the tree
void tree_clear(tree_node<T>* &root);
template <typename T>       //erase target from the tree
bool tree_erase(tree_node<T>*& root, const T& target);
template <typename T>       //return copy of tree pointed to by root
tree_node<T>* tree_copy(tree_node<T>* root);
template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target);
template <typename T>
bool tree_search(tree_node<T>* root, const T& target,
                 tree_node<T>* &found_ptr);
template <typename T>       //erase rightmost node from the tree
                            // store the item in max_value
void tree_remove_max(tree_node<T>* &root, T& max_value);
template <typename T>       //Add tree src to dest
void tree_add(tree_node<T>* & dest, const tree_node<T>* src);
template <typename T>       // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int size = -1);

int main(int argc, char *argv[])
{
    tree_node<int> *test, *test2, *test3;
    test3 = NULL;
    test = NULL;
    tree_insert(test,25);
    tree_insert(test,15);
    //Testing tree_remove_max on root node
//    int maxy = 0;
//    tree_remove_max(test,maxy);
//    cout << "maxy " << maxy << endl;
    //tree_print(test);
    tree_insert(test,35);
    tree_insert(test,7);
    tree_insert(test,21);
    tree_insert(test,44);
    tree_insert(test,46);
    tree_insert(test,76);
    tree_insert(test,14);
    tree_insert(test,17);
    tree_insert(test,46);
    tree_insert(test,31);
    tree_insert(test,37);
    //Scene1 - testing tree_insert/tree_print/tree_print debug
    cout<<"Scene1 - testing tree_insert/tree_print/tree_print debug"<<endl;
    tree_print(test);
    tree_print_debug(test);
    //Scene2 - testing tree_erase
    cout << "Scene2 - testing tree_erase" << endl;
    tree_erase(test,44);
    tree_erase(test,15);
    tree_erase(test,31);
    tree_print(test);
    tree_print_debug(test);
    //Scene3 - testing tree_copy
    cout << "Scene3 - testing tree_copy" << endl;
    test2 = tree_copy(test);
    tree_print(test2);
    tree_print_debug(test2);
    //Scene4 - testing tree_node tree_seach
    cout << "Scene4 - testing tree_node tree_seach" << endl;
    tree_node<int> *sub, *sub2;
    sub = tree_search(test2,14);
    cout << "sub->item = " << sub->_item << endl;
    tree_print(sub);
    tree_print_debug(sub);
    //Scene5 - testing bool tree_seach
    cout << "Scene5 - testing bool tree_seach" << endl;
    if(tree_search(test2,46,sub2)){
        cout << "46 found " << endl;
        tree_print(sub2);
        tree_print_debug(sub2);
     }
    //Scene6 - testing tree_remove_max
    cout << "Scene6 - testing tree_remove_max" << endl;
    cout << "TEST2" << endl;
    tree_print(test2);
    tree_print_debug(test2);
    int max = 0;
    tree_remove_max(test2,max);
    cout << "max = " << max << endl;
    tree_print(test2);
    tree_print_debug(test2);
    //Scene7 - testing tree_add
    cout << "Scene7 - testing tree_add" << endl;
    tree_insert(test3,19);
    tree_insert(test3,6);
    tree_insert(test3,73);
    tree_insert(test3,101);
    tree_insert(test3,44);
    tree_insert(test3,18);
    cout << "test3*****" << endl;
    tree_print(test3);
    tree_print_debug(test3);
    cout << "test 2 + test 3 " << endl;
    tree_add(test2,test3);
    tree_print(test2);
    tree_print_debug(test2);
    //Scene8 - testing tree_from_sorted_list
    cout << "Scene8 - testing tree_from_sorted_list" << endl;
    int *list;
    //int size = 7;
    list = new int[11];
    list[0]= 1;
    list[1]= 2;
    list[2]= 6;
    list[3]= 8;
    list[4]= 13;
    list[5]= 23;
    list[6]= 32;
    list[7]= 45;
    list[8]= 67;
    list[9]= 76;
    list[10]= 87;
    tree_node<int> *klp;
    klp = tree_from_sorted_list(list);
    cout << "Tree from sorted list:" << endl;
    tree_print(klp);
    //Last Scene - testing tree_clear
    cout << "Last Scene - testing tree_clear" << endl;
    tree_clear(test);
    tree_print(test);
    tree_print_debug(test);

    return 0;
}
template <typename T>       // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int size){
    //Finds how many numbers are in the list then finds the middle
    //  of the list.  Then it enters the numbers in backwards and forwards
    int *klp;
    int i = 0;
    while(a[i] != NULL){
        //cout << "a[i] = " << a[i] << endl;
        ++i;
    }
    //cout << "i = " << i << endl;
    int middle = i/2;
    //cout << "middle = " << middle << endl;

    tree_node<T> *ptr, *head, *follow, *follow2;
    ptr = new tree_node<T>(a[middle]);
    head = ptr;
    follow = ptr;
    follow2 = ptr;
    //cout << "ptr->item = " << ptr->_item << endl;
    for(int j = middle - 1; j >= 0; --j){
        follow->_left = new tree_node<T>(a[j]);
        follow = follow->_left;
    }
    for(int j = middle + 1; j < i; ++j){
        follow2->_right = new tree_node<T>(a[j]);
        follow2 = follow2->_right;
    }
    return ptr;
}
template <typename T>
void tree_insert(tree_node<T>* &root, const T& insert_me){
    if(root == NULL){
        //If root is null, add new tree_node
        root = new tree_node<T>(insert_me);
        return;//0
    }
    tree_node<T> *ptr;
    ptr = root;
    if(insert_me < ptr->_item){
        //If insert_me is less than ptr-item, recurse tree_insert
        tree_insert(ptr->_left,insert_me);
        //Update height and balance
        root->update_height();
        root->balance_factor();
    }
    else if(insert_me > ptr->_item){
        //If insert_me is greater than ptr-item, recurse tree_insert
        tree_insert(ptr->_right,insert_me);
        //Update height and balance
        root->height();
        root->balance_factor();
    }
}
template <typename T>       //Add tree src to dest
void tree_add(tree_node<T>* & dest, const tree_node<T>* src){
    //Preorder Traversal algorithm

    //cout << "scr->item = " << src->_item << endl;
    tree_insert(dest,src->_item);
    if(src->_left != NULL){
        tree_add(dest,src->_left);
    }
    if(src->_right != NULL){
        tree_add(dest,src->_right);
    }
}
template <typename T>       //erase rightmost node from the tree
                            // store the item in max_value
void tree_remove_max(tree_node<T>* &root, T& max_value){
    //Deletes the maximum value in the tree
    if(root->_right != NULL){
        if(root->_right->_right != NULL){
            tree_remove_max(root->_right,max_value);
        }
        else if(root->_right->_right == NULL){
            max_value = root->_right->_item;
            delete root->_right;
            root->_right = NULL;
            return;
        }
    }
    else if(root->_right == NULL){
        max_value = root->_item;
        tree_node<T> *ptr;
        ptr = root;
        root = root->_left;
        delete ptr;
    }
}
template <typename T>
bool tree_search(tree_node<T>* root, const T& target,
                 tree_node<T>* &found_ptr){
    //Removes the maximum value in the tree and returns
    //  the pointer holding the node
    tree_node<T> *ptr;
    ptr = root;
    if(ptr == NULL){
        //cout << "target not found" << endl;
        return false;
    }
    if(target == ptr->_item){
        //cout << "target found " << *ptr << endl;
        found_ptr = ptr;
        return true;
    }
    if(target < ptr->_item){
        return tree_search(ptr->_left,target,found_ptr);
    }
    if(target > ptr->_item){
        return tree_search(ptr->_right,target,found_ptr);
    }
}
template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target){
    //Searches for a target and returns a tree_node pointer
    tree_node<T> *ptr;
    ptr = root;
    if(ptr == NULL){
        //cout << "target not found" << endl;
        return NULL;
    }
    if(target == ptr->_item){
        //cout << "target found " << *ptr << endl;
        return ptr;
    }
    if(target < ptr->_item){
        return tree_search(ptr->_left,target);
    }
    if(target > ptr->_item){
        return tree_search(ptr->_right,target);
    }
}
template <typename T>       //return copy of tree pointed to by root
tree_node<T>* tree_copy(tree_node<T>* root){
    //cout << "root->item = " << root->_item << endl;
    if(root->_left != NULL){
        tree_copy(root->_left);
    }
    if(root->_right != NULL){
        tree_copy(root->_right);
    }
    return root;
}
template <typename T>       //erase target from the tree
bool tree_erase(tree_node<T>*& root, const T& target){
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
            //cout << "erasing " << ptr->_item << endl;
            delete ptr;
            return true;
        }
        if(root->_left != NULL)
        // Current node has a left subtree
        {
            if(root->_left->_left == NULL && root->_left->_right == NULL)
            // If roots leftnode has nothing underneath it, works
            {
                //cout << "erasing " << root->_item << endl;
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
                //cout << "erasing " << ptr->_item << endl;
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
                    //cout << "erasing " << ptr->_item << endl;
                    delete ptr;
                    return true;
                }
            }
        }
    }
}
template <typename T>       //clear the tree
void tree_clear(tree_node<T>* &root){
    if(root->_left != NULL || root->_right != NULL){
        if(root->_left != NULL){
            tree_clear(root->_left);
        }
        if(root->_right != NULL){
            tree_clear(root->_right);
        }
    }
    tree_node<T> *ptr;
    ptr = root;
    //cout << "root->item = " << root->_item << endl;
    delete ptr;
    root = NULL;
}
template<typename T>
void tree_print(tree_node<T>* root, int level,
                                    ostream& outs){
    if(root == NULL){
        //cout << "here" << endl;
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
template<typename T>       //prints detailes info about each node
void tree_print_debug(tree_node<T>* root, int level,
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
