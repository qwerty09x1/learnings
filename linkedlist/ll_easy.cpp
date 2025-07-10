#include<bits/stdc++.h>
using namespace std;
//Standard LeetCode like definintion of the linked list 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Utility: Build list from vector
ListNode* buildList(const vector<int>& arr) {if (arr.empty()) return nullptr;ListNode* head = new ListNode(arr[0]);ListNode* current = head;for (int i = 1; i < arr.size(); i++) {current->next = new ListNode(arr[i]);current = current->next; }return head;}

// Utility: Convert list to vector
vector<int> listToVector(ListNode* head) {vector<int> result;while (head) { result.push_back(head->val);head = head->next;}return result;}
//Reverse Linked List 
ListNode* solvereverseLL(ListNode* head) {
    ListNode* prev = nullptr;      // initially nothing is before head
    ListNode* current = head;      // start from head
    ListNode* nextNode = nullptr;  // to store the next node temporarily
    while (current != nullptr) {
        nextNode = current->next;  // save next
        current->next = prev;      // reverse the link
        prev = current;            // move prev forward
        current = nextNode;        // move current forward
    }
    return prev; // prev is the new head
}
//Remove Nth Node From End of List (Medium) > Given the head of a linked list, remove the nth node from the end and return its head.
ListNode* removefromend(ListNode* head, int n){
    ListNode* curr = head;
    int size=1;
    if(head->next==nullptr){return head;}
    while(curr!=nullptr){
        size+=1;
        curr=curr->next;
    }
    int l=size-n+1;
    ListNode* temp = head;
    while(l-1){
        temp=temp->next;
        l--;
    }
    ListNode* temp2= temp->next->next;
        temp->next=temp2;
    return head;
    
}
ListNode* addtwonumbers(ListNode* head){


}
//Swap nodes in pairs
ListNode* swappairs(ListNode* head){

}

//Reorder List 
void reorderList(ListNode* head){

}

//Rotate List to the right by k places(Assuming k is not more than length)
ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0)
        return head;
    // Step 1: Advance the 'first' pointer k steps
    ListNode* first = head;
    for (int i = 0; i < k; ++i) {
        first = first->next;
    }
    // Step 2: Move both 'first' and 'second' until first->next == nullptr
    ListNode* second = head;
    while (first->next) {
        first = first->next;
        second = second->next;
    }
    // Step 3: Rotate
    ListNode* newHead = second->next;
    second->next = nullptr;
    first->next = head;
    return newHead;
}

//Partition List
ListNode* partition(ListNode* head, int x){
    ListNode* second=head;
    ListNode* first=head;
    // while(!curr->next)


}
void solver() {
    vector<int> inputVals;
    string line;
    
    // Read first line (the list)
    getline(cin, line);
    stringstream ss(line);
    int val;
    while (ss >> val) {
        inputVals.push_back(val);
    }

    // Read second line (k)
    int k;
    cin >> k;

    ListNode* head = buildList(inputVals);
    ListNode* result = rotateRight(head, k);
    vector<int> output = listToVector(result);
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }
    cout << endl;
}


// void solve() {
//     vector<int> inputVals; int val;while (cin >> val) { inputVals.push_back(val);}
//     ListNode* head = buildList(inputVals);
//     ListNode* result = solve();  // Replace this with any logic
//     vector<int> output = listToVector(result);
//     for (int i = 0; i < output.size(); i++) {cout << output[i]<< " ";}
// }

// Main
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solver();}
    return 0;
}