#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution
{
public:
    vector<long long> resVec;

    void getPoints(long long sum, const vector<vector<int>> &questions, int index)
    {
        if (index >= questions.size())
        {
            resVec.push_back(sum);
            return;
        }

        getPoints(sum + questions[index][0], questions, index + questions[index][1] + 1);

        getPoints(sum, questions, index + 1);
    }

    long long mostPoints(vector<vector<int>> &questions)
    {
        resVec.clear();
        getPoints(0, questions, 0);
        sort(resVec.begin(), resVec.end());
        return resVec.back();
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> questions;
    string line;
    int numQuestions;

    cout << "Enter the number of questions: ";
    cin >> numQuestions;
    cin.ignore();

    for (int i = 0; i < numQuestions; ++i)
    {
        cout << "Enter question " << i + 1 << " (points brainpower): ";
        getline(cin, line);
        istringstream iss(line);
        int points, brainpower;
        iss >> points >> brainpower;
        questions.push_back({points, brainpower});
    }

    long long result = solution.mostPoints(questions);
    cout << "Maximum points: " << result << endl;

    return 0;
}

/* 超时
总结规律后代码：

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n,0);
        long long ret=0;
        for(int i=0;i<n;++i){
            auto &point=questions[i][0],&brainpower=questions[i][1];
            if(i>0){
                dp[i]=max(dp[i],dp[i-1]);
            }
            auto totalPoint=dp[i]+point;
            auto next=brainpower+i+1;
            if(next>=n){
                ret=max(ret,totalPoint);
            }else{
                dp[next]=max(dp[next],totalPoint);
            }
        }
        return ret;
    }
};

*/