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
    DLinkedNode* dummy;
    std::unordered_map<int, DLinkedNode*> cacheMap;

public:
    LRUCache(int capacity):capacity(capacity), used(0)
    {
        dummy = new DLinkedNode(0, 0);
        //即是头也是尾
        dummy -> next = dummy;
        dummy -> pre = dummy;
    }

    /**
     * 获取缓存
     * 根据key获取value
     * 通过hash表判断是否存在该key 存在就获取该点
     *  1.获取hash表的节点
     *  2.断开原来节点的pre和next
     *  3.将该点移动到head位置
     * 
     * 不存在就返回-1
     */
    int get(int key)
    {
        if (cacheMap.find(key) != cacheMap.end())
        {
            // 修改当前节点的指针
            DLinkedNode* node = cacheMap[key];
            //断开原来节点的pre和next
            removeNode(node);
            //将该点移动到head位置
            addToHead(node);

            return node -> value;
        }
        return -1;
    }

    /**
     * 传入key和value 更新缓存
     * 
     * 判断是否存在该key
     * 1.不存在就添加
     * 1.1 判断是否已满
     *  1.1.1 未满
     *  直接添加该点到头部
     *  更新hash表
     * 
     *  1.1.2 已满
     *  上述尾节点，从hash表中移除
     *  添加新节点到头部，添加hash表
     * 
     * 2. 存在就更新值 移动头位置
     * 断开该节点原有链接
     * 添加节点到头部
     * 
     */
    void put(int key, int value)
    {
        if (cacheMap.find(key) != cacheMap.end())
        {
            DLinkedNode* node = cacheMap[key];
            //断开原来节点的pre和next
            removeNode(node);
            //将该点移动到head位置
            addToHead(node);
        }
        else
        {
            if (used >= capacity)
            {
                // 删除hash表 和 尾部点
                DLinkedNode *tail = dummy->pre;
                cacheMap.erase(tail->key);
                delete tail;

                //尾部移除
                DLinkedNode* node = new DLinkedNode(key, value);
                // 更新新节点位置
                cacheMap[key] = node;
                addToHead(node);
            }
            else
            {
                DLinkedNode* node = new DLinkedNode(key, value);
                cacheMap[key] = node;
                addToHead(node);
                used++;
            }
        }
    }

    /**
     * 断开节点链路
     */
    void removeNode(DLinkedNode *node) {
        node->pre->next = node -> next;
        node->next->pre = node -> pre;
    }


    void addToHead(DLinkedNode *node) {
        //移动到头部
        DLinkedNode* temp = dummy->next;
        temp->pre = node;
        dummy->next = node;

        node->next = temp;
        node->pre = dummy;
        
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
