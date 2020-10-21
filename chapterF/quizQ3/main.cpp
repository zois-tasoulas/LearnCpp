#include <iostream>
#include <iterator>

int binarySearchIterative(const int *array, int target, int min, int max)
{
    int result {-1};

    while (min <= max) {
        int index {min + (max - min) / 2};
        if (array[index] == target) {
            result = index;
            break;
        } else if (array[index] > target) {
            max = index -1;
        } else {
            min = index + 1;
        }
    }

    return result;
}

int binarySearchRecursive(const int *array, int target, int min, int max)
{
    const int index {min + (max - min) / 2};

    if (min > max) {
        return -1;
    } else if (array[index] == target) {
       return index;
    } else if (array[index] > target) {
       return binarySearchRecursive(array, target, min, index - 1);
    } else {
       return binarySearchRecursive(array, target, index + 1, max);
    }
}

void checkIndex (const int index, const int expected, const int testVal)
{
    // If it matches our expected value, then great!
    if (index == expected)
         std::cout << "test value " << testVal << " passed!\n";
    else // otherwise, our binarySearch() function must be broken
         std::cout << "test value " << testVal << " failed.  There's something"
                   << " wrong with your code!\n";
}

int main()
{
    constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

    // We're going to test a bunch of values to see if they produce the expected results
    constexpr int numTestValues{ 9 };
    // Here are the test values
    constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
    // And here are the expected results for each value
    int expectedValues[numTestValues]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };

    // Loop through all of the test values
    for (int count{ 0 }; count < numTestValues; ++count)
    {
        // See if our test value is in the array
        int index{binarySearchIterative(array, testValues[count], 0,
                                        static_cast<int>(sizeof(array) / sizeof(*array)) - 1)};

        checkIndex(index, expectedValues[count], testValues[count]);
        index = binarySearchRecursive(array, testValues[count], 0,
                                      static_cast<int>(sizeof(array) / sizeof(*array)) - 1);
        checkIndex(index, expectedValues[count], testValues[count]);
    }

    return 0;
}
