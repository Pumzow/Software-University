#include <iostream>
#include <stack>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool isOpenBracket(char bracket);

bool isBracketMatch(char open, char close);

bool canBeNested(char parent, char child);

bool isExpressionValid(const string& brackets);

int main() {
    string brackets{ };
    cin >> brackets;

    const bool expressionValid = isExpressionValid(brackets);

    cout << (expressionValid ? "valid" : "invalid") << endl;

    return 0;
}

bool isExpressionValid(const string& brackets) {
    stack<char> openBrackets{ };

    bool isValid = true;
    for (const auto bracket : brackets) {
        if (isOpenBracket(bracket) && (openBrackets.empty() || canBeNested(openBrackets.top(), bracket))) {
            openBrackets.push(bracket);
        }
        else if (!openBrackets.empty() && isBracketMatch(openBrackets.top(), bracket)) {
            openBrackets.pop();
        }
        else {
            isValid = false;
            break;
        }
    }

    return isValid && openBrackets.empty();
}

bool canBeNested(char parent, char child) {
    static const unordered_map<char, unordered_set<char>> bracketInner{
        { '{', { '{', '[', '(' }},
        { '[', { '[', '(' }},
        { '(', { '(' }}
    };

    const auto& it = bracketInner.find(parent);
    if (it != bracketInner.end()) {
        return it->second.find(child) != it->second.end();
    }

    return false;
}

bool isBracketMatch(char open, char close) {
    static const set<pair<char, char>> bracketPairs = {
        { '(', ')' },
        { '[', ']' },
        { '{', '}' }
    };

    return bracketPairs.find(make_pair(open, close)) != bracketPairs.end();
}

bool isOpenBracket(char bracket) {
    static const unordered_set<char> openBrackets{ '(', '[', '{' };
    return openBrackets.find(bracket) != openBrackets.end();
}