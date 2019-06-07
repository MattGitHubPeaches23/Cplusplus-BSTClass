// Copyright (c) 2019, Matthew Chalifoux.
#include "bstclass.cpp"


int main()
{
    srand (time(NULL));
    BST<int> test2, test3;
    test2.insert(44);
    test2.insert(34);
    test2.insert(24);
    test2.insert(74);
    test2.insert(64);
    test2.insert(54);
    test2.insert(4);
    cout << test2;
    test3.insert(36);
    test3.insert(35);
    test3.insert(78);
    test3.insert(12);
    test3.insert(24);
    test3.insert(9);
    test3.insert(87);
    cout << test3;
    //Testing += operator
    test2 += test3;
    //cout << "Combine" << endl;
    cout << test2;
    //Testing copy and assignment constructor
    BST<int> test4(test3);
    //cout << "test4" << endl;
    cout << test4;
    test3 = test2;
    //cout << "test3" << endl;
    cout << test3;
    //Testing sorted list to constructor
    int *list;
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
    BST<int> test5(list);
    cout << test5;



    BST<int> test;
    char ans = '\0';
    do{
        cout << "[R]andom  [I]nsert  [C]clear  [S]earch  [E]rase   e[X]it: " << endl;
        cin >> ans;
        if(ans == 'R' || ans == 'r'){
            int num = 0;
            num = rand()%100;
            cout << "Entering number " << num << endl;
            test.insert(num);
            cout << test;
        }
        else if(ans == 'I' || ans == 'i'){
            int num;
            cout << "Enter number to insert : ";
            cin >> num;
            test.insert(num);
            cout << test;
        }
        else if(ans == 'C' || ans == 'c'){
            test.Tree_Clear();
            cout << test;
        }
        else if(ans == 'S' || ans == 's'){
            int num;
            cout << "?";
            cin >> num;
            test.PreSearch(num);
            cout << test;
        }
        else if(ans == 'E' || ans == 'e'){
            int num;
            cout << "Enter number to erase : ";
            cin >> num;
            if(test.PreSearch(num)){
                test.erase(num);
            }
            cout << test;
        }
        else if(ans == 'X' || ans == 'x'){
            exit(1);
        }
    }while(ans != 'X' || ans != 'x');

    return 0;
}
