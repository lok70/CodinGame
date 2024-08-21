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
        if (matching.find(c) != matching.end()) { // если закрывающая скобка
            if (!stack.empty() && stack.top() == matching[c]) {
                stack.pop();
            }
            else {
                result.push_back(matching[c]); // добавляем соответсвующую скобку, если не совпадает та, которая лежит на вершине
            }
            result.push_back(c);
        }
        else { // если открывающая скобка
            stack.push(c);
            result.push_back(c);
        }
    }

    // проверяем не остался ли кто-нибудь без пары, и исправляем это если надо  
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

// Функция для расчета биномиального коэффициента
long long binomial(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Функция для расчета количества размещений для заданной длины ряда и длины плитки
long long replaceCount(int n, int x) {
    long long sum = 0;
    for (int a = 1; a <= n / x; ++a) {
        int b = n - a * x;
        sum += binomial(a + b, a);
    }
    return sum;
}

// Общая функция для расчета
long long Finish(int n) {
    long long sum = 0;
    for (int a = 2; a <= 4; ++a) {
        sum += replaceCount(n, a);
    }
    return sum;
}