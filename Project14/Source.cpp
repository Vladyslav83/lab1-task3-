#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter m: ";
    cin >> m;

    vector<vector<double>> A(n, vector<double>(m));
    // Зчитування масиву
  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    // Сортування кожного рядка масиву
    for (int i = 0; i < n; i++) {
        sort(A[i].begin(), A[i].end());
    }

    // Знаходження мінімального значення максимальних елементів 
    //перших m рядків та максимального значення мінімальних елементів останніх (n-m) рядків
    double min_max = A[0][m - 1];
    for (int i = 1; i < m; i++) {
        min_max = min(min_max, A[i][m - 1]);
    }

    double max_min = A[m][0];
    for (int i = m + 1; i < n; i++) {
        max_min = max(max_min, A[i][0]);
    }

    double V = min_max > max_min ? max_min : min_max;

    cout << "V = " << V << endl;

    return 0;
}