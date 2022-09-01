

/*
Find the  maximum candies Rohan will get:
money: 10 rupees
price: 2 rupees / candy
wrap: 2 rapper = 1 candy
*/

#include <iostream>
using namespace std;

int maxCandies(int wrapperCandy, int noOfWrappers) {
    if(noOfWrappers < wrapperCandy)
        return 0;
    
    return (noOfWrappers / wrapperCandy) + maxCandies(wrapperCandy, (noOfWrappers % wrapperCandy) +  (noOfWrappers / wrapperCandy)); 
}

int main()
{
    int money = 10;
    int pricePerCandy = 2;
    int wrapperCandy = 2;

    cin >> money >> pricePerCandy >> wrapperCandy;
    // 20 3 4

    // money, pricePerCandy, wrapperPrice, noOfWrappers, noOfCandies
    int noOfCandies = (money / pricePerCandy) + maxCandies(wrapperCandy, money / pricePerCandy);
    cout << noOfCandies << endl;
}

// 20, 3, 3