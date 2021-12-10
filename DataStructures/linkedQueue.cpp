#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Queue {
	public:
	ListNode *front, *rear;
    
    Queue() {
		front = rear = nullptr;
	}
    
    // O(1)
    bool isEmpty() {
        if (front == nullptr) {
            return true;
        }
        else {
            return false;
        } 
    }

    // O(1)
	void enQueue(int x) {
		ListNode* temp = new ListNode(x);
		if (isEmpty()) {
			front = rear = temp;
			return;
		}
		rear->next = temp;
		rear = temp;
	}

    // O(1)
	void deQueue() {

		if (isEmpty())
			return;

		ListNode* temp = front;
		front = front->next;

		if (front == nullptr)
			rear = nullptr;

		delete (temp);
	}

    // O(1)
    int peek() {
        if (isEmpty()) {
            cout << "Queue Empty \n";
            return NULL;
        }
        else {
            return front->val;
        }
    }

    // O(n)
    void showQueue() {
        if(isEmpty()) {
            cout << "Queue Empty \n";
            return;
        }
        else {
            ListNode* tmp = front;
            while(tmp != nullptr) {
                cout <<  tmp->val << "-> ";
                tmp = tmp->next;
            }
        cout << "NULL\n";
        }
    }
};

int main() {
    
    Queue q;
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
                q.enQueue(val);
                break;
            }
            case 2:
            {
                q.deQueue();
                break;
            }
            case 3:
            {
                q.showQueue();
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