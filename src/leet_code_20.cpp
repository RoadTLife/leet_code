#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

class Solution
{
public:
    // 20241010 leetcode 020 自己实现的
    int countSubstrings(string s)
    {
        int result = s.length();
        for (int i = 0, len = s.length(); i < len; i++)
        {
            for (int j = i + 1; j <= len; j++)
            {
                if (j != i + 1)
                {
                    string item = s.substr(i, j - i);
                    std::cout << " string is " << item << " i " << i << " j " << j << std::endl;
                    bool isPalind = true;
                    for (int k = 0, itemLen = item.length(); k < itemLen / 2; k++)
                    {
                        if (item[k] != item[itemLen - k - 1])
                        {
                            isPalind = false;
                            break;
                        }
                    }

                    if (isPalind)
                    {
                        result++;
                    }
                }
            }
        }
        return result;
    }

    // 20241010 leetcode 020 中间折中法
    int countSubstringsNew(string s)
    {
        int result = 0;
        for (int i = 0,len = s.length(); i < 2 * len; i++)
        {
            int left = i / 2;
            int right = i / 2 + i % 2;
            while (left >= 0 && right < len && s[left] == s[right]) {
                left--;
                right++;
                result++;
            }
        }

        return result;

    }
};