#include <cmath>
#include <iostream>

void divider()
{
        std::cout << "\n"
                  << "======================================================================"
                  << "\n\n";
}

bool double_equals(double value, double target)
{
        if (std::abs(value - target) < 0.0000001)
                return true;

        return false;
}
