class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> tmp;
		sort(candidates.begin(), candidates.end());
		this->candidates = candidates;
		int flag = 0;
		caculate(candidates, target, tmp, ans, flag);
		return ans;
	}

	void caculate(vector<int>& candidates, int target, vector<int> &tmp, vector<vector<int>> &ans, int flag)
	{
		if (target == 0)
		{
			//叶子的判断
			ans.push_back(tmp);
			return;
		}

		for (int i = flag; i < candidates.size() && target - candidates[i] >= 0; i++)
		{
			if (i > flag && candidates[i] == candidates[i - 1])
			{
				continue;
			}
			tmp.push_back(candidates[i]);
			caculate(candidates, target - candidates[i], tmp, ans, i + 1);
			tmp.pop_back();
		}
	}
};
