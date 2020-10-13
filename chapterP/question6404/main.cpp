#include <algorithm>
#include <iostream>

int main()
{
    int myArray[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    int arraySize {static_cast<int>(sizeof(myArray) / sizeof(myArray[0]))};
    int iteration {};

    for (int ii {0}; ii < arraySize; ++ii) {
        bool swapFlag{false};
        for (int jj {1}; jj < arraySize - ii; ++jj) {
            if (myArray[jj - 1] > myArray[jj] ) {
                std::swap(myArray[jj - 1], myArray[jj]);
                swapFlag = true;
            }
        }
        if (!swapFlag) {
            iteration = ii + 1;
            break;
        }
    }

    std::cout << "Early termination on iteration " << iteration << ".\n";
    for (int ii {0}; ii < arraySize; ++ii) {
        std::cout << myArray[ii] << ' ';
    }
    return 0;
}
