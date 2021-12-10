#include <iostream>

using namespace std;
 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* curr = head;
    ListNode* prev = NULL;
    while(curr != NULL) {
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
} 

bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) {
            return true;
        }
    }
    return false;
}

void display(ListNode* head) {
    ListNode* curr = head;
    while(curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

//O(N)
ListNode* searchList(ListNode* head, int val) {
    ListNode* curr = head;
    while(curr != NULL && curr->val != val) {
        curr = curr->next;
    }
    return curr;
}

int main() {
    ListNode* head = new ListNode();
    ListNode* Newnode = new ListNode(4); 
    ListNode* Newnode1 = new ListNode(5, Newnode);
    ListNode* Newnode2 = new ListNode(6, Newnode1);  
    head->next = Newnode2;
    display(head);
    ListNode* head3 = new ListNode(10);
    /*
    ListNode* curr = new ListNode(20, Newnode2); 
    ListNode* head3 = new ListNode(10, curr);
    //Newnode->next = curr;
    //ListNode* head2 = reverseList(head);
    */
    bool has = hasCycle(head3);
    if(!has) cout << "not has" << endl;
    if(has) cout << "has" << endl;
    display(head3);
    return 0;
}

