/**
 * @file leet_code_78.cpp
 * @author tampopo (you@domain.com)
 * @brief https://leetcode.cn/problems/vvXgSW/description/
 * @version 0.1
 * @date 2024-10-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();

        ListNode* head = nullptr;
        ListNode* current;
        while(true) {
            ListNode* minNode = nullptr;
            int minVal;
            int minI;
            for(int i = 0; i < len; i++) {
                ListNode* node = lists[i];
                if(node != nullptr) {
                    if(minNode == nullptr) {
                        minNode = node;
                        minVal = node->val;
                        minI = i;
                    } else {
                        int value = node->val;
                        if(value < minVal) {
                            minNode = node;
                            minVal = node->val;
                            minI = i;
                        }
                    }
                }
            }

            // 元素都为空 可以跳出了
            if(minNode == nullptr) {
                break;
            }

            if(head == nullptr) {
                head = minNode;
                current = head;
            } else {
                current-> next = minNode;
                current = current -> next;
            }

            //更新node 下标
            lists[minI] = lists[minI] -> next;
        }
        
        return head;
    }


    ListNode* printNode(ListNode* head) {
        while(head != nullptr) {
            std::cout << head->val << " ";
            head = head ->next;
        }
        std::cout << std::endl;
    }

    vector<ListNode*> changeLinkNode(vector<vector<int>> input) {
        vector<ListNode*> res(input.size(), nullptr);
        for(int i = 0, len = input.size(); i < len; i++) {
            vector<int> item = input[i];
            int jLen = item.size();
            if(jLen >= 1) {
                ListNode* head = new ListNode(item[0]);
                ListNode* current = head;
                for(int j = 1; j < jLen; j++) {
                    ListNode* node = new ListNode(item[j]);
                    current -> next = node;
                    current = current -> next;
                }

                // 放入到结果集合中
                res[i] = head;
            } else {
                // 没有集合的返回nullptr
                res[i] = nullptr;
            }
        }

        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> nums = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    vector<ListNode*> res = s.changeLinkNode(nums);
    s.printNode(s.mergeKLists(res));

    return 0;
}
