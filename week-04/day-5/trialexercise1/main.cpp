#include <iostream>
#include <vector>

std::vector<std::vector<int>> returnedMatrix(const std::vector<std::vector<int>>& a,const std::vector<std::vector<int>>& b)
{
    std::vector<std::vector<int>> goodMatrix = a;
    for (unsigned int i = 0; i < a.size(); i++) {
        for (unsigned int j = 0; j < b.size(); j++) {
            if (goodMatrix[i][j] < b[i][j]) {
                goodMatrix[i][j] = b[i][j];
            }
        }
    }
    return goodMatrix;
}
int main()
{
    std::vector<std::vector<int>> matrix =
            { {-1, 1, 0},
              {0, 1, 0},
              {0, 1, 0}
            };
    std::vector<std::vector<int>> matrix2 =
            { {0, 0, 0},
              {0, 1, 0},
              {0, 1, 0}
            };
    std::vector<std::vector<int>> good = returnedMatrix(matrix, matrix2);
    for (unsigned int i = 0; i < good.size(); i++) {
        for (unsigned int j = 0; j < good.size(); j++) {
            std::cout << good[i][j] << " ";
        }
    }

    return 0;
}