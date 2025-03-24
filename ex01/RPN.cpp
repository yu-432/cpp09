/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:33:32 by yooshima          #+#    #+#             */
/*   Updated: 2025/03/24 17:45:16 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<std::int64_t> RPN::_stack;

bool isOperator(std::string& token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

long calc(long nb1, long nb2, std::string& token) {
    long res;
    if (token == "+" && !(__builtin_add_overflow(nb2, nb1, &res))) {
        return nb2 + nb1;
    } else if (token == "-" && !(__builtin_sub_overflow(nb2, nb1, &res))) {
        return nb2 - nb1;
    } else if (token == "*" && !(__builtin_mul_overflow(nb2, nb1, &res))) {
        return nb2 * nb1;
    } else if (token == "/") {
        return nb2 / nb1;
    }
    errno = ERANGE;
    return 0;
}

int RPN::executeRPN(const char *inputStr) {
    std::stack<std::int64_t> init;
    errno = 0;
    _stack = init;

    std::istringstream iss(inputStr);
    std::string token;
    while (iss >> token) {
        if (!isOperator(token)) {
            char* endptr;
            long nb = std::strtol(token.c_str(), &endptr, 10);
            if (errno == ERANGE) {
                std::cerr << "Error: overflowed" << std::endl;
                return 1;
            }
            if (endptr != NULL && endptr[0]) {
                std::cerr << "Error: invalid token " << endptr << std::endl;
                return 1;
            }
            _stack.push(nb);
        }
        else {
            if (_stack.size() < 2) {
                std::cerr << "Error: calc stack size under 2" << std::endl;
                return 1;
            }
            long nb1 = _stack.top(); _stack.pop();
            long nb2 = _stack.top(); _stack.pop();
            if (nb1 == 0 && token == "/") {
                std::cerr << "Error: division by zero" << std::endl;
                return 1;
            }
            long result = calc(nb1, nb2, token);
            if (errno == ERANGE) {
                std::cerr << "Error: overflowed" << std::endl;
                return 1;
            }
            _stack.push(result);
        }
    }
    if (_stack.size() != 1) {
        std::cerr << "Error: Not finished calc" << std::endl;
        return 1;
    }
    std::cout << _stack.top() << std::endl;
    return 0;
}

/*
10000000 2000 + 1000  - 100 -

+
2000
100000
        2       1
102000(100000 + 2000)

-
1000
102000
        2       1
101000(102000 - 1000)

-
100
101000
        2       1
100900(101000 - 100)
*/
