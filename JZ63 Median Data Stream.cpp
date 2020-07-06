class Solution {
public:
    // min_q < (q) < max_q
    priority_queue<int, vector<int>, less<int> > min_q;
    priority_queue<int, vector<int>, greater<int> > max_q;

    void Insert(int num)
    {
        // push into max_q
        min_q.push(num);
        // push into min_q
        max_q.push(min_q.top());
        min_q.pop();

        if (max_q.size() > min_q.size() + 1)
        {
            min_q.push(max_q.top());
            max_q.pop();
        }
    }

    double GetMedian()
    {
        if (max_q.size() == 0)
        {
            return 0.0;
        }
        if (max_q.size() == min_q.size() + 1)
        {
            return static_cast<double> (max_q.top());
        }
        if (max_q.size() == min_q.size() && max_q.size() > 0)
        {
            return static_cast<double>(min_q.top() + max_q.top()) / 2;
        }

    }

};