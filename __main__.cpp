#include "CircularBuffer.hpp"

int main()
{
    CircularBuffer<int> ew(2);

    for (auto i : ew)
        std::cout << i << std::endl;
}
