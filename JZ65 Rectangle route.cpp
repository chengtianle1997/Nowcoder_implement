class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        bool has_path = false;
        // Check the input
        if (str == nullptr || matrix == nullptr)
            return false;
        // Initialize the flag matrix
        bool* flag = new bool[rows * cols];
        for (int m = 0; m < rows; m++)
        {
            for (int n = 0; n < cols; n++)
            {
                flag[m * cols + n] = false;
            }
        }
        // Search the first letter in matrix
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (findWay(matrix, flag, rows, cols, 0, i, j, str))
                    return true;
            }
        }
        return false;
    }

    bool findWay(char* matrix, bool* flag, int rows, int cols, int k, int i, int j, char* str)
    {
        bool has_path = false;
        if (k >= strlen(str))
            return true;
        if (i >= 0 && i < rows && j >= 0 && j < cols && str[k] == matrix[i * cols + j] && !flag[i * cols + j])
        {
            k++;
            flag[i * cols + j] = true;
            has_path = findWay(matrix, flag, rows, cols, k, i + 1, j, str)
                || findWay(matrix, flag, rows, cols, k, i - 1, j, str)
                || findWay(matrix, flag, rows, cols, k, i, j + 1, str)
                || findWay(matrix, flag, rows, cols, k, i, j - 1, str);
            if (has_path)
                return true;
            flag[i * cols + j] = false;
        }

        return has_path;
    }


};