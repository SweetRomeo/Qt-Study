#include "arrayutil.h"

Arrayutil::Arrayutil() {}

std::vector<int> Arrayutil::plusOne(std::vector<int> digits)
{
    for (int idx = digits.size() - 1; 0 <= idx; --idx)
    {
        if (digits[idx] == 9)
        {
            digits[idx] = 0;
        }
        else
        {
            digits[idx]++;
            return digits;
        }
    }
    digits.insert(digits.begin(), 1);
    return digits;
}
