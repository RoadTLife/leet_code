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
#include <vector>
#include <unordered_map>
using namespace std;

struct DLinkedNode {
    int key;
    int value;
    DLinkedNode* prev;
    DLinkedNode* next;

    DLinkedNode(int key, int value) : key(key), value(value), prev(nullptr), next(nullptr) {}

};

class LRUCache {
private:
    int capacity;
    int used;
    DLinkedNode* dummpy;
    unordered_map<int, DLinkedNode*> cache;

public:
    LRUCache(int capacity) : capacity(capacity), used(0) {
        dummpy = new DLinkedNode(-1, -1);
        dummpy->prev = dummpy;
        dummpy->next = dummpy;
     }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            DLinkedNode* node = cache[key];
            // 移除节点链接
            removeNode(node);
            // 将节点移到头部
            addNodeToHead(node);

            return node->value;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            //找到原有的
            DLinkedNode* node = cache[key];
            node->value = value;

            removeNode(node);
            addNodeToHead(node);
        } else {
            if(used >= capacity) {
                // 删除尾节点的hash 
                DLinkedNode* node = dummpy->prev;
                cache.erase(node->key);
                removeNode(node);
                delete node;
            } else {
                used++;
            }
            // 创建点并将其移动到头部
            DLinkedNode* node = new DLinkedNode(key, value);
            addNodeToHead(node);
            //添加hash
            cache[key] = node;
        }

    }

    void addNodeToHead(DLinkedNode* node) {
        node->prev = dummpy;
        node->next = dummpy -> next;

        dummpy-> next -> prev = node;
        dummpy-> next = node; 

    }

    void removeNode(DLinkedNode* node) {
        node->prev->next = node -> next;
        node->next->prev = node -> prev;
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
