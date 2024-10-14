/**
 * link : https://leetcode.cn/problems/UHnkqh/description/
 */
#include <iostream>
#include <vector>

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
    /** 第一个粗暴的思路 */
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) {
            return nullptr;
        } else {
            std::vector<int> result = {};
            ListNode* currnt = head;
            while(currnt != nullptr) {
                result.push_back(currnt->val);
                currnt = currnt->next;
             }

            int length = result.size();
            ListNode* head = new ListNode(result[length - 1]);
            currnt = head;
             for(int i = length - 2; i >= 0; i--) {
                 ListNode* node = new ListNode(result[i]);
                 currnt->next = node;
                 currnt = currnt->next;
             }
            return head;
        }
    }

    /** 优化后 */
    ListNode* reverseListNew(ListNode* head) {
        ListNode* prev = nullptr; //保存前一个节点
        ListNode* curr = head; //用于当前节点

        while(curr != nullptr) {
            ListNode* node = curr-> next;
            curr->next = prev; //反转链表
            prev = curr; //前一个节点后移
            curr = node; //当前节点后移
        }

        return prev;
    }
};

// 用于输出链表的辅助函数
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

ListNode* build(std::vector<int> input) {
    ListNode* head = new ListNode(input[0]);
    ListNode* cur = head;
    for(int i = 1, len = input.size(); i < len; i++) {
        ListNode* node = new ListNode(input[i]);
        cur->next = node;
        cur = cur->next;
    }
    return head;
}

int main() {

    std::vector<int> input = {1, 2, 3, 4};
    ListNode* list = build(input);
    printList(list);

    std::cout << "print finish!" << std::endl;
    Solution s;

    printList(s.reverseListNew(list));
    return 0;
}