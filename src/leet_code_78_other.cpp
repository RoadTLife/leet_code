/**
 * @file leet_code_78.cpp
 * @author tampopo (you@domain.com)
 * @brief https://leetcode.cn/problems/vvXgSW/description/ 采用小根堆的方式实现
 * @version 0.1
 * @date 2024-10-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <vector>
#include <queue>

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

struct MyCompare{
    bool operator()(ListNode* right, ListNode* left) const {
        return right->val > left->val;
    }
};

private:
    priority_queue<ListNode*, vector<ListNode*>, MyCompare> pq;

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(ListNode* item : lists) {
            if(item != nullptr) {
                pq.push(item); 
            }
            
        }

        ListNode* head = nullptr;
        ListNode* current;

        while(! pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            if(node -> next != nullptr) {
                pq.push(node->next);
            }

            if(head == nullptr) {
                head = node;
                current = head;
            } else {
                current -> next = node;
                current = current -> next;
            }
            
        }

        return head;
        
    }


    ListNode* printNode(ListNode* head) {
        while(head != nullptr) {
            std::cout << head->val << " ";
            head = head ->next;
        }
        std::cout << std::endl;
        return head; // 修正返回类型以匹配函数签名
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

