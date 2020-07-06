class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool* flag = new bool[rows * cols];
        for (int i = 0; i < rows * cols; i++)
        {
            flag[i] = false;
        }
        return moving(threshold, flag, 0, 0, rows, cols);
    }

    int moving(int threshold, bool* flag, int i, int j, int rows, int cols)
    {
        int count = 0;
        if (i >= 0 && j >= 0 && i < rows && j < cols && get_sum(i) + get_sum(j) <= threshold && flag[i * cols + j] == false)
        {
            flag[i * cols + j] = true;
            count = 1 + moving(threshold, flag, i + 1, j, rows, cols)
                + moving(threshold, flag, i - 1, j, rows, cols)
                + moving(threshold, flag, i, j + 1, rows, cols)
                + moving(threshold, flag, i, j - 1, rows, cols);
        }
        return count;
    }
    int get_sum(int x)
    {
        int sum = 0;
        while (x)
        {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
};