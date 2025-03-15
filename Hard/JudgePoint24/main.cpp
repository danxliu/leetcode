#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool dfs(int n, vector<double> cards)
{
    if (cards.size() == 1)
    {
        return abs(cards[0] - n) <= 0.1;
    }

    // Need to combine two different cards at index i and index j
    for (int i = 0; i < cards.size(); i++)
    {
        for (int j = i + 1; j < cards.size(); j++)
        {
            // newCards will contain same cards except two are combined
            vector<double> newCards;
            for (int k = 0; k < cards.size(); k++)
            {
                if (k != i && k != j)
                {
                    // Initially set newCards to have all same cards as cards except at i and j
                    newCards.push_back(cards[k]);
                }
            }

            // next countains all possible combinations of cards[i] and cards[j] together
            vector<double> next = {cards[i] + cards[j], cards[i] - cards[j], cards[j] - cards[i], cards[i] * cards[j]};
            if (cards[i])
                next.push_back({cards[j] / cards[i]});
            if (cards[j])
                next.push_back({cards[i] / cards[j]});

            // Try every combination of next and see if the combination works
            for (int k = 0; k < next.size(); k++)
            {
                newCards.push_back(next[k]);
                if (dfs(n, newCards))
                {
                    return true;
                }
                // backtrack
                newCards.pop_back();
            }
        }
    }
    return false;
}

bool judgePoint24(vector<int> &cards)
{
    vector<double> list(cards.begin(), cards.end());
    return dfs(24, list);
}

int main()
{
    vector<int> cards{1, 2, 1, 2};
    cout << judgePoint24(cards) << endl;
}