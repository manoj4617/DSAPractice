#include <iostream>
#include <string>
#include <vector>

struct LinkedListNode {
	int data;
	LinkedListNode * next;
	LinkedListNode * arbitrary_pointer;
	LinkedListNode(int d) {
		data = d;
		next = nullptr;
		arbitrary_pointer = nullptr;
	}
};
void PrintListWithForwardArrow(LinkedListNode* head) {
		LinkedListNode* temp = head;
		while (temp != nullptr) {
			std::cout<<temp->data;
			temp = temp->next;
			if (temp != nullptr) {
			    std::cout<< " -> ";
			}
			else{
			    std::cout<<" -> null"<<std::endl;
			}
		}
	}

class LinkedList {
public:
	LinkedListNode* head;

	LinkedList() { head = nullptr; }

	void InsertAtHead(int data) {
		if (head == nullptr) {
			head = new LinkedListNode(data);
		} else {
			LinkedListNode* new_node = new LinkedListNode(data);
			new_node->next = head;
			head = new_node;
		}
	}

	void InsertAtTail(int data) {
		if (head == nullptr) {
			head = new LinkedListNode(data);
		} else {
			LinkedListNode* new_node = new LinkedListNode(data);
			LinkedListNode* temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = new_node;
		}
	}

	void CreateLinkedList(std::vector<int>& vec) {
		for (int i = vec.size() - 1; i >= 0; i--) {
			InsertAtHead(vec[i]);
		}
	}
	
};