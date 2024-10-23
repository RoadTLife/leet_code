/**
 * @file leet_code_19.cpp
 * @author your name (you@domain.com)
 * @brief  https://leetcode.cn/problems/remove-nth-node-from-end-of-list
 * @version 0.1
 * @date 2024-10-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* result;

        int length = 0;
        ListNode* current = head;
        while (current != nullptr)
        {
            length++;
            current = current->next;
        }
        
        int index = length - n;
        ListNode* preDelNode;
        if(index == 0) {
            result = head->next;
        } else {
            current = head;
            int i = 0;
            while (i++ < index)
            {
                preDelNode = current;
                current = current->next;
            }

            preDelNode->next = preDelNode->next->next;
            result = head;
        }
        
        return result;
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

int main() {
    vector<int> nums{1, 2, 3, 4, 5};
    // vector<int> nums{1};
    Solution s;
    ListNode* input_node = s.getListNode(nums);
    ListNode* result = s.removeNthFromEnd(input_node, 5);
    s.printListNode(result);
    return 0;
}