#include <iostream>
#include <vector>

int getTotalX(std::vector<int> a, std::vector<int> b)
{
    int lowestNum = b[0];
    for (unsigned int i = 0; i < b.size(); i++) {
        if (b[i] < lowestNum) {
            lowestNum = b[i];
        }
    }
    std::vector<int> ourVector;
    for (unsigned int i = 1; i <= lowestNum; i++) {
        if (lowestNum % i == 0) {
            ourVector.push_back(i);
        }
    }
    std::vector<int> ourSecondVector;
    for (unsigned int i = 0; i < ourVector.size(); i++) {
        for (unsigned int j = 0; j < b.size(); j++) {
            if (b[j] % ourVector[i] == 0) {
                if (j == b.size() - 1) {
                    ourSecondVector.push_back(ourVector[i]);
                }
            } else {
                break;
            }
        }
    }
    std::vector<int> willReturn;
    for (unsigned int i = 0; i < ourSecondVector.size(); i++) {
        for (unsigned int j = 0; j < a.size(); j++) {
            if (ourSecondVector[i] % a[j] == 0) {
                if (j == a.size() - 1) {
                    willReturn.push_back(ourSecondVector[i]);
                }
            } else {
                break;
            }
        }
    }
    return willReturn.size();
}
int main()
{
    std::vector<int> a = {3, 4};
    std::vector<int> b = {24, 48};

    getTotalX(a, b);


    return 0;
}