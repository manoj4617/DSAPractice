#include<iostream>
#include "ll_inserting_last.h"

using namespace std;



int main(){
    // insert_last(10);
    // insert_last(11);
    // insert_last(12);
    // insert_last(14);
    // insert_last(18);
    cout<< "before deleting" << endl;
    //display(head);

    sorted_insert(head,9);
    sorted_insert(head,17);
    sorted_insert(head,12);
    sorted_insert(head,18);
    sorted_insert(head,19);
    sorted_insert(head,20);
    display(head);
    cout << endl;
    //cout << "deleted element " << delete_from_first(head)<<endl;
    cout << "deleted element " << delete_from_anywhere(head,4)<<endl;
    cout << "after delete" << endl;
    display(head);
    return 0;
}