class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        if (num.empty() || size == 0)
            return vector<int>();
        int n = num.size();
        if (n < size)
            return vector<int>();
        vector<int> res;
        int l = 0, re = 0;
        bool isFirst = true;
        deque<int> maxWindow;
        while (l < n)
        {
            if (isFirst)
            {
                for (l = 0; l < size; l++)
                {
                    while (!maxWindow.empty() && maxWindow.back() < num[l])
                    {
                        maxWindow.pop_back();
                    }
                    maxWindow.push_back(num[l]);
                }
                l = size - 1;
                res.push_back(maxWindow.front());
                isFirst = false;
            }
            else
            {
                // if the largest value is invalid
                if (!maxWindow.empty() && maxWindow.front() == num[l - size])
                {
                    maxWindow.pop_front();
                }
                while (!maxWindow.empty() && maxWindow.back() < num[l])
                {
                    maxWindow.pop_back();
                }
                maxWindow.push_back(num[l]);
                res.push_back(maxWindow.front());
            }
            l++;
            re++;
        }
        return res;
    }
};