#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// Рекурсивная функция проверки возможности полного заполнения веревки
bool canFillRope(vector<int>& items, vector<bool>& used, int index, int currentSum, int totalLength) {
    if (index == items.size()) {
        // Все предметы расставлены, проверим длину
        return currentSum == totalLength;
    }

    for (int i = 0; i < items.size(); ++i) {
        if (!used[i]) {
            used[i] = true;
            if (canFillRope(items, used, index + 1, currentSum + items[i], totalLength)) {
                return true;
            }
            used[i] = false; // backtrack
        }
    }
    return false;
}

int main() {
    int ropeLength, n;
    cout << "Введите длину веревки: ";
    cin >> ropeLength;
    cout << "Введите количество оставшихся предметов: ";
    cin >> n;

    vector<int> items(n);
    cout << "Введите длины " << n << " оставшихся предметов: ";
    for (int i = 0; i < n; ++i) {
        cin >> items[i];
        if (items[i] < 0){
            cout << "Длина не може быть отрицательной!" << endl;
            exit(0);
        }
    }

    vector<bool> used(n, false);

    if (canFillRope(items, used, 0, 0, ropeLength)) {
        cout << "Можно перевесить предметы так, чтобы занять всю веревку.\n";
    } else {
        cout << "Нельзя занять всю веревку оставшимися предметами.\n";
    }

    return 0;
}

