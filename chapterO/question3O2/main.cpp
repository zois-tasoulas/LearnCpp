#include <iostream>
#include <bitset>

std::bitset<4> rotl(std::bitset<4> bits)
{
    std::bitset<4> mask{ bits >> 3 };

    bits <<= 1;
    bits |= mask;
    return bits;
}

int main()
{
	std::bitset<4> bits1{ 0b0001 };
	std::cout << rotl(bits1) << '\n';

	std::bitset<4> bits2{ 0b1001 };
	std::cout << rotl(bits2) << '\n';

	return 0;
}
