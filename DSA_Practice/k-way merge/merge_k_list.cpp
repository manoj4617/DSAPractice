#include "../LL/ll_new_class.h"


/**
 * This function merges two linked lists by comparing the data of each node and 
 * rearranging the list in ascending order.
 * 
 * @param list1 - A pointer to the head of the first linked list.
 * @param list2 - A pointer to the head of the second linked list.
 * 
 * @return - A pointer to the head of the merged linked list.
 * 
 * The function creates a dummy node and a previous node to keep track of the 
 * current merged node. It then iterates through both linked lists until one of 
 * them is empty. For each iteration, it compares the data of the current nodes 
 * of the two linked lists. If the data of the first linked list is less than or 
 * equal to the data of the second linked list, it moves the current node of the 
 * first linked list to the merged list. If the data of the first linked list is 
 * greater than the data of the second linked list, it moves the current node of 
 * the second linked list to the merged list. If one of the linked lists is empty, 
 * it moves the remaining nodes of the other linked list to the merged list. 
 * Finally, it returns the head of the merged list.
 */
LinkedListNode* kMerge(LinkedListNode* list1, LinkedListNode* list2){
    // Create a dummy node and a previous node to keep track of the current merged node.
    LinkedListNode* dummy = new LinkedListNode(0);
    LinkedListNode* prv = new LinkedListNode(0);
    prv = dummy;

    // Iterate through both linked lists until one of them is empty.
    while(list1 != nullptr && list2 != nullptr){
        // Compare the data of the current nodes of the two linked lists.
        if(list1->data <= list2->data){
            // Move the current node of the first linked list to the merged list.
            prv->next = list1;
            list1 = list1->next;
        }
        else if(list1->data > list2->data){
            // Move the current node of the second linked list to the merged list.
            prv->next = list2;
            list2 = list2->next;
        }
        prv = prv->next;
    }

    // If one of the linked lists is empty, move the remaining nodes of the other linked list to the merged list.
    if(list1){
        prv->next = list1;
    } else {
        prv->next = list2;
    }

    // Return the head of the merged list.
    return dummy->next;
}

/**
 * This function merges the linked lists in the given vector.
 * 
 * @param lists - The vector of LinkedList pointers.
 * @return - The merged LinkedList pointer.
 * 
 * The function uses a variation of the merge sort algorithm to merge the linked lists.
 * It starts with a step size of 1 and gradually increases it by multiplying by 2.
 * For each step, it merges the linked lists in pairs.
 * The merge operation is performed by the kMerge function.
 * The merged linked list is assigned to the head of the corresponding LinkedList.
 * The process continues until all the linked lists are merged into a single one.
 * At the end, it returns the merged linked list.
 */
LinkedListNode* MergeLists(std::vector<LinkedList*> lists){
    if(lists.size() > 0){ // Check if the vector is not empty
        int step = 1; // Initialize the step size

        while(step < lists.size()){ // Loop until all the linked lists are merged
            for(int i=0; i < lists.size() - step; i = i +(step * 2)){ // Merge linked lists in pairs
                lists[i]->head = kMerge(lists[i]->head, lists[i+step]->head); // Merge the linked lists and assign the merged list to the head of the corresponding LinkedList
            }
            step  *= 2; // Increase the step size by multiplying by 2
        }
        return lists[0]->head; // Return nullptr since the merged list is stored in the LinkedList pointers
    }
    return nullptr;
}

int main(){

    std::vector<std::vector<std::vector<int>>> inputLists = {
        {{21, 23, 42}, {1, 2, 4}},
        {{11, 41, 51}, {21, 23, 42}},
        {{2}, {1, 2, 4}, {25, 56, 66, 72}},
        {{11, 41, 51}, {2}, {2}, {2}, {1, 2, 4}},
        {{10, 30}, {15, 25}, {1, 7}, {3, 9}, {100, 300}, {115, 125}, {10, 70}, {30, 90}}
    };

    int k = 1;

    // Iterate over the input lists
    for(int i = 0; i< inputLists.size(); i++ ){
        std::cout<<k<<".      Inputs lists:"<<std::endl;
        std::vector<LinkedList*> ll_lists = {} ; 

        // Create linked lists from the input vectors
        for(int j = 0; j< inputLists[i].size(); j++ ){
            LinkedList* obj = new LinkedList();
            obj->CreateLinkedList(inputLists[i][j]);
            ll_lists.push_back(obj);
            std::cout<<"\t";
            PrintListWithForwardArrow(ll_lists[j]->head);
        }

        k = k+1;
        std::cout<<"\n\tMerged list:\t"<<std::endl;
        std::cout<<"\t";
        // Merge the linked lists and print the result
        PrintListWithForwardArrow(MergeLists(ll_lists));
        std::cout << std::string(100, '-') << "\n";
    }

    return 0;
}