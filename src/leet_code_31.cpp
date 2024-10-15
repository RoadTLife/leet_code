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
#include <list>

class LRUCache
{
public:
    // hash 表的value 存储的是堆外的position
    std::unordered_map <int, std::list<std::pair<int, int>>::iterator> cacheMap;
    // 存储的
    std::list<std::pair<int, int>> cacheList;
    int capacity;
    int used;

    // 以正整数作为容量 capacity 初始化 LRU 缓存
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    // 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1
    int get(int key)
    {
        if (cacheMap.find(key) == cacheMap.end())
        {
            return -1;
        }

        std::list<std::pair<int, int>>::iterator it = cacheMap[key];
        // 获取值
        int value = it->second;
        // 删除旧节点
        cacheList.erase(it);
        cacheList.push_front({key, value});
        // 返回第一个元素的迭代器
        cacheMap[key] = cacheList.begin();
        return value;
    }

    // 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
    void put(int key, int value)
    {

        if (cacheMap.find(key) == cacheMap.end())
        {
            if (used >= capacity) {
                // 获取尾部元素
                int key = cacheList.back().first;
                cachemap.erase(key);
                cacheList.pop_back();
            } else {
                used++;
            }
        }
        else // 存在该节点
        {
            // 删除该节点
            cacheList.erase(cacheMap[key]);
        }

        // 插入新节点
        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();
    }

};

int main()
{

    LRUCache *obj = new LRUCache(2);

    return 0;
}