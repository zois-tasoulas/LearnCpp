#include <array>
#include <iostream>
#include <numeric>

enum class Items {
    arrow = 0,
    healthPotion,
    torch
};

int countTotalItems (std::array<int, 3> items) {
    return std::accumulate(items.begin(), items.end(), 0);
}

int main()
{
    std::array<int, 3> itemsHeld {10, 2, 5};

    std::cout << "The player is holding " << countTotalItems(itemsHeld)
              << " items in total. " << itemsHeld[static_cast<int>(Items::torch)]
              << " of the items are torches.\n";
    return 0;
}
