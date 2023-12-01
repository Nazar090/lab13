#include <iostream>

using namespace std;

void fillMatrix(vector<vector<int>>& matrix) {
    srand(time(0));
    for (auto& row : matrix) {
        for (int& num : row) {
            num = rand() % 201 - 100;
        }
    }
}

int findMaxInRow(const vector<int>& row) {
    int maxElement = INT_MIN;
    for (int num : row) {
        if (num > maxElement) {
            maxElement = num;
        }
    }
    return maxElement;
}

int countNegativeElements(const vector<vector<int>>& matrix) {
    int count = 0;
    for (const auto& row : matrix) {
        for (int num : row) {
            if (num < 0) {
                count++;
            }
        }
    }
    return count;
}

int findMaxInArray(const vector<int>& array) {
    int maxElement = INT_MIN;
    for (int num : array) {
        if (num > maxElement) {
            maxElement = num;
        }
    }
    return maxElement;
}


void fillArrayWithMinMax(const vector<vector<int>>& matrix, vector<int>& resultArray) {
    int maxInMatrix = findMaxInArray(matrix[0]);

    for (const auto& row : matrix) {
        int maxInRow = findMaxInRow(row);
        if (maxInRow > maxInMatrix) {
            maxInMatrix = maxInRow;
        }
    }

    int minInMatrix = findMinInArray(matrix[0]); 

    for (const auto& row : matrix) {
        int minInRow = findMinInArray(row);
        if (minInRow < minInMatrix) {
            minInMatrix = minInRow;
        }
    }

    resultArray = {maxInMatrix, minInMatrix};
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

void printArray(const vector<int>& array) {
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n, m;
    cout << "Введіть кількість рядків матриці: ";
    cin >> n;
    cout << "Введіть кількість стовпців матриці: ";
    cin >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    fillMatrix(matrix);

    cout << "Вихідна матриця:\n";
    printMatrix(matrix);

    cout << "\nМаксимальні елементи у кожному рядку:\n";
    for (const auto& row : matrix) {
        cout << findMaxInRow(row) << " ";
    }
    cout << endl;

    cout << "\nКількість від'ємних елементів у матриці: " << countNegativeElements(matrix) << endl;

    vector<int> resultArray;
    fillArrayWithMinMax(matrix, resultArray);

    cout << "\nОдновимірний масив з найбільшим і найменшим елементами матриці:\n";
    printArray(resultArray);

    return 0;
}