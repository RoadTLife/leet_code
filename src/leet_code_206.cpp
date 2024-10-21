/**
 link : https://leetcode.cn/problems/reverse-linked-list/description/
 */

#include <iostream>
#include <vector>
using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 头节点
        ListNode* dummy;

        ListNode* prev = nullptr;
        ListNode* current = head;

        while(current != nullptr) {
            dummy = new ListNode(current->val);
            dummy->next = prev;
            prev = dummy;
            
            current = current->next;
        }
        return dummy;
    }

    ListNode* getListNode(vector<int> inputs) {
        ListNode* head = nullptr;
        ListNode* current;

        for(int item : inputs) {
            if(head == nullptr) {
                head = new ListNode(item);
                current = head;
            } else {
                ListNode* node = new ListNode(item);
                current->next = node;
                current = current->next;
            }
        }

        return head;
    }


    void printListNode(ListNode* head) {

        ListNode* current = head;
        while(current != nullptr) {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;

    }
};

/**
 * [1,2,3,4,5]
 */
int main() {
    vector<int> nums{1, 2, 3, 4, 5};
    Solution s;
    ListNode* input_node = s.getListNode(nums);
    s.printListNode(input_node);

    std::cout << "=== calc " << std::endl;
    ListNode* res = s.reverseList(input_node);
    s.printListNode(res);


    return 0;
}