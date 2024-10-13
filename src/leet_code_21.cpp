/**
 * Definition for singly-linked list.
 *
 * link: https://leetcode.cn/problems/merge-two-sorted-lists/
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head;
        ListNode *preNode;
        ListNode *currentNode;

        while (list1->next != nullptr && list2->next != nullptr)
        {
            int val1 = list1->val;
            int val2 = list2->val;

            if (val1 < val2)
            {
                currentNode = new ListNode(val1);
                list1 = list1->next;
                if (preNode != nullptr)
                {
                    preNode->next = currentNode;
                }
            }
            else
            {
                currentNode = new ListNode(val2);
                list2 = list2->next;
                if (preNode != nullptr)
                {
                    preNode->next = currentNode;
                }
            }

            if (head == nullptr)
            {
                head = currentNode;
            }

            preNode = currentNode;
        }
    }
};

int main()
{
    // 输入数据 l1 = [1,2,4], l2 = [1,3,4]

    Solution solution;

    return 0;
}