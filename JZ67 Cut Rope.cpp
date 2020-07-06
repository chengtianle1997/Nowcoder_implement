class Solution {
public:
    int cutRope(int number) {

        if (number < 2 || number > 60) {
            return -1;
        }
        else if (number == 2) {
            return 1;
        }
        else if (number == 3) {
            return 2;
        }

        int* mul_k = new int[number + 1];
        mul_k[0] = 1;
        mul_k[1] = 1;
        mul_k[2] = 2;
        mul_k[3] = 3;

        for (int i = 4; i < number + 1; i++) {
            mul_k[i] = 0;
        }

        for (int i = 4; i < number + 1; i++) {
            for (int j = 1; j <= i / 2; j++) {
                int mul = mul_k[j] * mul_k[i - j];
                mul_k[i] = max(mul, mul_k[i]);
            }
        }

        int res = mul_k[number];
        delete[] mul_k;
        return res;
    }
};