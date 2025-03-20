#include <iostream>
#include <vector>
#include <map>
#include <algorithm> // for binary_search
using namespace std;

class Solution
{
public:
    map<int, int> hasUsedImp;

    void onceReverseOperations(int n, int p, vector<int> &banned, int k, int times, map<int, int> &sucReveres)
    {
        // 回溯退出条件
        if (times > n || (hasUsedImp.count(p) && hasUsedImp[p] <= times))
        {
            return;
        }

        // 获得子数组下标的取值范围
        int minIndex = (p - k + 1) >= 0 ? (p - k + 1) : 0;
        int maxIndex = (p + k - 1) >= n ? (n - 1) : (p + k - 1);
        hasUsedImp.insert({p, times});

        // 遍历不同子数组下的翻转场景
        for (int i = minIndex; i + k <= maxIndex + 1; ++i)
        {
            // 获取位置p下的1翻转后下标
            int index = (i + k - 1) - (p - i);  // 不简化计算公式，方便理解
            if (index < i || index >= i + k)    // 超出当前子数组范围
            {
                continue;
            }

            if (!binary_search(banned.begin(), banned.end(), index))
            {
                if (sucReveres.count(index) && times < sucReveres[index])
                {
                    sucReveres[index] = times;
                }
                else
                {
                    sucReveres.insert({index, times});
                }

                onceReverseOperations(n, index, banned, k, times + 1, sucReveres);
            }
        }
    }

    vector<int> minReverseOperations(int n, int p, vector<int> &banned, int k)
    {
        map<int, int> sucReveres;

        // 对 banned 数组进行排序，以便使用 binary_search
        sort(banned.begin(), banned.end());

        onceReverseOperations(n, p, banned, k, 1, sucReveres);

        vector<int> res;            // 可先初始化，再依据map修改数据
        for (int i = 0; i < n; ++i)
        {
            if (i == p)
            {
                res.push_back(0);
            }
            else if (sucReveres.count(i))
            {
                res.push_back(sucReveres[i]);
            }
            else
            {
                res.push_back(-1);
            }
        }

        return res;
    }
};

int main()
{
    Solution solution;
    int n, p, k;
    vector<int> banned;

    cout << "Enter the size of the array (n): ";
    cin >> n;

    cout << "Enter the initial position of 1 (p): ";
    cin >> p;

    cout << "Enter the size of the banned indices array: ";
    int bannedSize;
    cin >> bannedSize;

    if (bannedSize > 0)
    {
        cout << "Enter the banned indices: ";
        for (int i = 0; i < bannedSize; ++i)
        {
            int temp;
            cin >> temp;
            banned.push_back(temp);
        }
    }

    cout << "Enter the size of the subarray (k): ";
    cin >> k;

    vector<int> result = solution.minReverseOperations(n, p, banned, k);

    cout << "The minimum number of reverse operations for each index is:" << endl;
    for (int i = 0; i < result.size(); ++i)
    {
        cout << "Index " << i << ": " << result[i] << endl;
    }

    return 0;
}


/* 回溯超时，方便理解；优化广度优先搜索 统计规律，将分次回溯的代码，合并到一次循环中*/