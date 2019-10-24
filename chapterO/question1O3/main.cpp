#include <iostream>
#include <bitset>

int main()
{
    constexpr unsigned char option_viewed { 0x01 };
    //constexpr unsigned char option_edited { 0x02 };
    constexpr unsigned char option_favorited { 0x04 };
    //constexpr unsigned char option_shared { 0x08 };
    constexpr unsigned char option_deleted { 0x80 };

    unsigned char myArticleFlags {0b1000'0100};

    myArticleFlags |= option_viewed;
    std::cout << static_cast<std::bitset<8>>(myArticleFlags) << '\n';
    if (myArticleFlags & option_deleted) {
        std::cout << static_cast<std::bitset<8>>(myArticleFlags) << '\n';
    }
    myArticleFlags &= ~option_favorited;
    std::cout << static_cast<std::bitset<8>>(myArticleFlags) << '\n';

    return 0;
}
