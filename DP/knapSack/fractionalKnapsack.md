# Fractional Knapsack Problem

### Problem Statement:

Given the weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Unlike the 0/1 knapsack problem, you can break the items for maximizing the total value of knapsack.

#### Intuition:

1. Use a greedy approach to solve the problem.
2. Calculate the ratio of value to weight for each item and sort the items based on this ratio.
3. Take the items with the highest ratio first until the knapsack is full.

#### Approach:

-   Sort items by value-to-weight ratio.
-   Take items fully if possible, otherwise take the fractional part.

#### Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);

    int curWeight = 0;
    double finalValue = 0.0;

    for(auto item : items) {
        if(curWeight + item.weight <= W) {
            curWeight += item.weight;
            finalValue += item.value;
        } else {
            int remain = W - curWeight;
            finalValue += item.value * ((double) remain / item.weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    cout << "Maximum value in Knapsack = " << fractionalKnapsack(W, items) << endl;
    return 0;
}

```
