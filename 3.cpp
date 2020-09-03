//最长子串(连续性),不是子序列
#include<unordered_set>
#include <string>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		//哈希集合,记录每个字符是否出现过
		unordered_set<char> m;
		int n = s.size();
		//定义一个右指针,初始值为-1,即在最左侧还未开始移动
		int right = -1, length = 0;
		//从最左侧开始枚举左指针的位置
		for (int i = 0; i < n; ++i)
		{
			if (i != 0)
			{
				//左指针向右移动一格,移除一个字符
				m.erase(s[i - 1]);
			}
			while (right + 1 < n && !m.count(s[right + 1]))
			{
				//不断地移动有指针
				m.insert(s[right + 1]);
				++right;
			}
			//第i到right个字符是一个极长的无重复字符子串
			length = max(length, right - i + 1);
		}
		return length;
	}
};
