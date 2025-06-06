#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> diffWaysToCompute(const string& expression) {
    vector<int> result;

    for (int i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        if (c == '+' || c == '-' || c == '*') {
            string left = expression.substr(0, i);
            string right = expression.substr(i + 1);

            vector<int> leftResults = diffWaysToCompute(left);
            vector<int> rightResults = diffWaysToCompute(right);

            for (int l : leftResults) {
                for (int r : rightResults) {
                    if (c == '+') result.push_back(l + r);
                    else if (c == '-') result.push_back(l - r);
                    else if (c == '*') result.push_back(l * r);
                }
            }
        }
    }

    if (result.empty()) {
        result.push_back(stoi(expression));
    }

    return result;
}

int main() {
    string expression;
    cout << "Введите выражение: ";
    cin >> expression;

    vector<int> results = diffWaysToCompute(expression);

    cout << "Все возможные результаты: ";
    for (int res : results) {
        cout << res << " ";
    }
    cout << endl;

    return 0;
}

