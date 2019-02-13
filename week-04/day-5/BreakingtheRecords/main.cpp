#include <iostream>
#include <vector>

std::vector<int> breakingRecords(const std::vector<int>& scores)
{
    int minimumRecord = scores[0];
    int maximumRecord = scores[0];
    std::vector<int> occurencies;
    for (unsigned int i = 0; i < scores.size(); i++) {
        int count = 0;
        if (minimumRecord > scores[i]) {
            count++;
            minimumRecord = scores[i];
            occurencies.push_back(count);
        } else if (maximumRecord < scores[i]) {
            count ++;
            maximumRecord = scores[i];
            occurencies.push_back(count);
        }
    }
    return occurencies;
}
int main()
{
    std::vector<int> scores = {10, 5, 20, 20, 4, 5, 2, 25, 1};

    return 0;
}