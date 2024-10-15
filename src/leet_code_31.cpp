/**
 * link: https://leetcode.cn/problems/OrIXps/description/
*
示例：
输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]
 */

#include <iostream>
#include <unordered_map>
#include <vector>

struct DLinkedNode
{
    int key;
    int value;
    DLinkedNode *pre;
    DLinkedNode *next;

    DLinkedNode(int x, int y) : key(x), value(y), pre(nullptr), next(nullptr) {}
    ~DLinkedNode()
    {
        pre = nullptr;
        next = nullptr;
    }
};

class LRUCache
{
private:
    int capacity;
    int used;
    DLinkedNode *head;
    DLinkedNode *tail;
    std::unordered_map<int, DLinkedNode*> hashTable;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        this->used = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    int get(int key)
    {
        if (hashTable.find(key) != hashTable.end())
        {
            // 修改当前节点的指针
            DLinkedNode *node = hashTable[key];

            removeNode(node);
            moveHead(node);
            return node -> value;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        DLinkedNode *node = nullptr;
        if (hashTable.find(key) != hashTable.end())
        {
            node = hashTable[key];
            //更新值
            node->key = key;
            node->value = value;
            //移除该节点
            removeNode(node);

            //移动头位置
            moveHead(node);
        }
        else
        {
            if (used >= capacity)
            {
                // 删除hash表
                DLinkedNode *node = hashTable[key];
                hashTable.erase(key);
                
                removeNode(node);
                // 更新新节点位置
                moveHead(node);
            }
            else
            {
                node = new DLinkedNode(key, value);
                if (tail == nullptr)
                {
                    tail = node;
                }
                else
                {
                    tail->next = node;
                    node->pre = tail;

                    if (head == nullptr)
                    {
                        head = node;
                    }
                    else
                    {
                        head->pre = node;
                        node->next = head;
                        head = node;
                    }
                }
                used++;
            }
        }

        // 更新 key 的位置
        hashTable[node->key] = head;
    }

    void removeNode(DLinkedNode *node) {
        node->pre->next = node -> next;
        node->next->pre = node -> pre;
        delete node;
    }

    void moveHead(DLinkedNode *node) {
        //移动到头部
        tail->next = node;
        node->pre = tail;

        node->next = head;
        head->pre = node;

        head = node;
    }
};

int main()
{
    std::vector<std::string> input = {"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"};
    std::vector<std::vector<int>> params = {
        {2},
        {1, 1},
        {2, 2},
        {1},
        {3, 3},
        {2},
        {4, 4},
        {1},
        {3},
        {4}};

    LRUCache *obj = nullptr;
    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] == "LRUCache")
        {
            obj = new LRUCache(params[i][0]);
        }
        else if (input[i] == "put")
        {
            obj->put(params[i][0], params[i][1]);
        }
        else if (input[i] == "get")
        {
            std::cout << obj->get(params[i][0]) << std::endl;
        }
        else
        {
            std::cout << "error" << std::endl;
        }
    }

    return 0;
}