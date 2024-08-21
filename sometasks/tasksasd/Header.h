#pragma once
#include "iostream"
#include <stack>
#include <string>
#include <unordered_map>

std::string makeValidSequence(const std::string& s) {
    std::stack<char> stack;
    std::string result;
    std::unordered_map<char, char> matching = {
        {')', '('}, {']', '['}, {'}', '{'}, {'>', '<'}
    };
    std::unordered_map<char, char> reverseMatching = {
        {'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'}
    };
    
    for (char c : s) {
        if (matching.find(c) != matching.end()) { // ���� ����������� ������
            if (!stack.empty() && stack.top() == matching[c]) {
                stack.pop();
            }
            else {
                result.push_back(matching[c]); // ��������� �������������� ������, ���� �� ��������� ��, ������� ����� �� �������
            }
            result.push_back(c);
        }
        else { // ���� ����������� ������
            stack.push(c);
            result.push_back(c);
        }
    }

    // ��������� �� ������� �� ���-������ ��� ����, � ���������� ��� ���� ����  
    while (!stack.empty()) {
        result.push_back(reverseMatching[stack.top()]);
        stack.pop();
    }

    return result;
}

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// ������� ��� ������� ������������� ������������
long long binomial(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// ������� ��� ������� ���������� ���������� ��� �������� ����� ���� � ����� ������
long long replaceCount(int n, int x) {
    long long sum = 0;
    for (int a = 1; a <= n / x; ++a) {
        int b = n - a * x;
        sum += binomial(a + b, a);
    }
    return sum;
}

// ����� ������� ��� �������
long long Finish(int n) {
    long long sum = 0;
    for (int a = 2; a <= 4; ++a) {
        sum += replaceCount(n, a);
    }
    return sum;
}