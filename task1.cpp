#include <iostream>

using namespace std;

void replaceRepeatedNumbers(vector<vector<int>>& matrix) {
    unordered_map<int, int> countMap;

    for (const auto& row : matrix) {
        for (int num : row) {
            countMap[num]++;
        }
    }

    for (auto& row : matrix) {
        for (int& num : row) {
            if (countMap[num] > 2) {
                num = 0;
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Введіть кількість рядків матриці: ";
    cin >> n;
    cout << "Введіть кількість стовпців матриці: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    cout << "Введіть матрицю " << n << " x " << m << ":\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    replaceRepeatedNumbers(matrix);

    cout << "Результат:\n";
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << "\n";
    }

    return 0;
}
