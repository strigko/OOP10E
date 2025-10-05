#include <iostream>
#include <string>
using namespace std;
bool checkRec(const string &s, int &i) {
    while (i < s.size()) {
        char c = s[i++];

        if (c == '(') {
            if (!checkRec(s, i) || s[i - 1] != ')') return false;
        }
        else if (c == '[') {
            if (!checkRec(s, i) || s[i - 1] != ']') return false;
        }
        else if (c == '{') {
            if (!checkRec(s, i) || s[i - 1] != '}') return false;
        }
        else if (c == ')' || c == ']' || c == '}') {
            return true;
        }
    }
    return true;
}

bool isCorrect(const string& s) {
    int i = 0;
    bool ok = checkRec(s, i);
    return ok && i == s.size();
}

int main() {
    string s;
    cout << "Enter row: ";
    getline(cin, s);

    int pos = 0;
    if (isCorrect(s))
        cout << "The row is fine\n";
    else
        cout << "An error occurred\n";
}