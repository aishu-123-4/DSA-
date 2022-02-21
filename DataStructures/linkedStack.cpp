#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Stack {
	public:
	ListNode *top;
    
    Stack() {
		top = nullptr;
	}
    
    // O(1)
    bool isEmpty() {
        if (top == nullptr) {
            return true;
        }
        else {
            return false;
        } 
    }

    // O(1)
	void push(int x) {
		ListNode* temp = new ListNode(x);
		if (isEmpty()) {
			top = temp;
			return;
		}
		temp->next = top;
		top = temp;
	}

    // O(1)
	void pop() {

		if (isEmpty())
			return;

		ListNode* temp = top;
		top = top->next;

		delete (temp);
	}

    // O(1)
    int peek() {
        if (isEmpty()) {
            cout << "Stack Empty \n";
            return NULL;
        }
        else {
            return top->val;
        }
    }

    // O(n)
    void showStack() {
        if(isEmpty()) {
            cout << "Stack Empty \n";
            return;
        }
        else {
            ListNode* tmp = top;
            while(tmp != nullptr) {
                cout <<  tmp->val << "-> ";
                tmp = tmp->next;
            }
        cout << "NULL\n";
        }
    }
};

int main() {
    
    Stack s;
    int val, ch;
    
    while (1) {
    
        cout << "\n\tMenu\n";
        cout << "1.Push\n";
        cout << "2.Pop\n";
        cout << "3.Display\n\n";
        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
            {
                cout << "\nEnter the value: ";
                cin >> val;
                s.push(val);
                break;
            }
            case 2:
            {
                s.pop();
                break;
            }
            case 3:
            {
                s.showStack();
                break;
            }
            default:
            {
                cout << "Wrong choice... Try Again!\n";
                break;
            }
        }
    }
    return 0;
}