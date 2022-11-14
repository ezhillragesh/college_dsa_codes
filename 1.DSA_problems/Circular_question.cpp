/*
Create a circular doubly linked list to store the following details of students – 
name and state. Start from the first node and traverse the list both in the forward
 and backward direction until a student from the same state is found and delete that
  node. Delete only one node that comes first in the forward or backward direction. 
  Now move to the next node from the currently deleted node. Continue traversing and
   deleting in a similar way until all the duplicates are removed. Print the final list.
*/
#include <iostream>
#include <string.h>
using namespace std;

class Node {
	Node *prev;
	string name;
	string state;
	Node *succ;
	public:
		Node *head;
		void init() {
			head = NULL;
		}
		void b_insert(string n, string s) {
			Node *current = new Node();
			current->prev = NULL;
			current->name = n;
			current->state = s;
			current->succ = NULL;
			if (head == NULL) {
				head = current;
				current->prev = head;
				current->succ = head;
			}
			else {
				if (head->succ == head) {
					head->succ = current;
					head->prev = current;
					current->succ = head;
					current->prev = head;
				}
				else {
					Node *temp = head->prev;
					temp->succ = current;
					current->prev = temp;
					current->succ = head;
					head->prev = current;
				}
			}
		}
		void display() {
			Node *temp = head;
			if (temp == NULL) {
				cout << "The list is empty." << endl;
			}
			else {
				cout << temp->name << " " << temp->state << endl;
				temp = temp->succ;
				while (temp != head) {
					cout << temp->name << " " << temp->state << endl;
					temp = temp->succ;
				}
			}
		}
		string b_delete() {
			if (head == NULL) {
				cout << "The list is empty." << endl;
			}
			else {
				Node *temp = head;
				if (temp->succ == head) {
					string n = temp->name;
					string s = temp->state;
					delete temp;
					head = NULL;
					return n, s;
				}
				else {
					while (temp->succ != head) {
						temp = temp->succ;
					}
					string n = temp->name;
					string s = temp->state;
					delete temp;
					head = NULL;
					return n, s;
				}
			}
		}
		Node* del_val(Node *ptr) {
			Node *temp = head;
			while (temp != ptr) {
				temp = temp->succ;
			}
			temp->prev->succ = temp->succ;
			temp->succ->prev = temp->prev;
			Node *other=temp->succ;
			delete temp;
			return other;
			
		}
		void del_duplicate() {
			Node *val = head;
			Node *ftemp;
			Node *btemp;
			do {
				ftemp = val->succ;
				btemp = val->prev;
				while (ftemp != val|| btemp!=val) {
						if (ftemp->state == val->state) {
							val=del_val(ftemp);
							break;
						
					}
					if (btemp->state == val->state) {
							val=del_val(btemp);
							break;
						
					}
					else {
						ftemp = ftemp->succ;
						btemp = btemp->prev;
						if(ftemp==val || btemp==val)
						  break;
						
					}
				}
				val = val->succ;
			} while (val != head);
		}
};

int main() {
	Node obj;
	obj.init();
	obj.b_insert("PPP", "Tamil Nadu");
	obj.b_insert("QQQ", "Oman");
	obj.b_insert("RRR", "Karnataka");
	obj.b_insert("SSS", "Oman");
	obj.b_insert("TTT", "Africa");
	obj.b_insert("VVV", "Oman");
	obj.b_insert("AAA", "Africa");
	obj.b_insert("BBB", "Tamil Nadu");
	obj.b_insert("CCC", "Oman");
	obj.b_insert("DDD", "Karnataka");
	obj.b_insert("EEE", "Oman");
	obj.b_insert("FFF", "Africa");
    obj.display();
    cout<<"*************************";
	obj.del_duplicate();
	obj.display();
}