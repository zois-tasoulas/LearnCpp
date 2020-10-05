#include <iostream>
#include <cassert>

struct Advertisement
{
    int numOfAds {0};
    double clickedAdsPercentage {0.0};
    double averageEarningsPerAd {0.0};
};

void printAdvertisement (Advertisement ad)
{
    std::cout << "Number of ads shown to users: " << ad.numOfAds << std::endl;
    std::cout << "Percentage of ads clicked by users: " << ad.clickedAdsPercentage << std::endl;
    std::cout << "Average earnings per clicked ad: " << ad.averageEarningsPerAd << std::endl;

    std::cout << "\nTotal earnings for the day: " << ad.numOfAds * ad.clickedAdsPercentage *
              ad.averageEarningsPerAd << std::endl;
}

int main()
{
    Advertisement ad;

    std::cout << "Please enter the following numbers for the day:\n"
              << "Number of ads shown to readers: ";
    std::cin >> ad.numOfAds;

    std::cout << "Percentage of ads clicked by users: ";
    std::cin >> ad.clickedAdsPercentage;

    assert(ad.clickedAdsPercentage <= 1.0);

    std::cout << "Average earnings per clicked ad: ";
    std::cin >> ad.averageEarningsPerAd;
    std::cout << std::endl;

    printAdvertisement(ad);

    return 0;
}
