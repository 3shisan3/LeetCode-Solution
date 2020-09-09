class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> tmp;
		Caculate(candidates, target, ans, tmp, 0);
		return ans;
	}

	void Caculate(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& tmp, int flag)
	{
		if (flag == candidates.size())
		{
			return;
		}
		if (target == 0)
		{
			//当调用push或insert成员函数时，我们将元素类型的对象传递给它们，这些对象被拷贝到容器中。
			//而当我们调用一个emplace成员函数时，则是将参数传递给元素类型的构造函数。
			//emplace成员使用这些参数在容器管理的内存空间中直接构造元素。
			ans.emplace_back(tmp);
			return;
		}
		//回溯
		Caculate(candidates, target, ans, tmp, flag + 1);
		//当前状态
		if (target - candidates[flag] >= 0)
		{
			tmp.push_back(candidates[flag]);
			//重复调用
			Caculate(candidates, target - candidates[flag], ans, tmp, flag);
			tmp.pop_back();
		}
	}
};
