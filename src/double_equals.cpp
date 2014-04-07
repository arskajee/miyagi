#include <cmath>

bool double_equals(double value, double target)
{
        if (std::abs(value - target) < 0.0000001)
                return true;

        return false;
}
