#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string str) {
        string result = "";
        int depth = 0;

        for (char ch : str) {
            if (ch == '(') {
                if (depth > 0) result += '(';
                depth++;
            } else if (ch == ')') {
                depth--;
                if (depth > 0) result += ')';
            }
        }

        return result;
    }
};
