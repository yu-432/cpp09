/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:35:04 by yooshima          #+#    #+#             */
/*   Updated: 2025/03/24 17:37:06 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc > 2) {
        std::cout << "Error: invalid arguments" << std::endl;
        return 1;
    }
    else if (argc == 2) {
        return RPN::executeRPN(argv[1]);
    }
    std::cout << "subject sample: 42" << std::endl;
    RPN::executeRPN("8 9 * 9 - 9 - 9 - 4 - 1 +");
    std::cout << "subject sample: 42" << std::endl;
    RPN::executeRPN("7 7 * 7 -");
    std::cout << "subject sample: 0" << std::endl;
    RPN::executeRPN("1 2 * 2 / 2 * 2 4 - +");
    std::cout << "subject sample: Error invalid token" << std::endl;
    RPN::executeRPN("(1 + 1)");
    std::cout << "sample: 29" << std::endl;
    RPN::executeRPN("3 4 + 5 * 6 -");
    std::cout << "sample: 14" << std::endl;
    RPN::executeRPN("5 1 2 + 4 * + 3 -");
    std::cout << "sample: 2" << std::endl;
    RPN::executeRPN("2 3 4 + * 5 /");
    std::cout << "sample: Error zero by division" << std::endl;
    RPN::executeRPN("9 0 /");
    std::cout << "sample: Error too many operator" << std::endl;
    RPN::executeRPN("1 2 + +");
    std::cout << "sample: Error missing operator" << std::endl;
    RPN::executeRPN("1 2");
    std::cout << "sample: Error overflow" << std::endl;
    RPN::executeRPN("1 9223372036854775807 +");
    std::cout << "sample: Error overflow" << std::endl;
    RPN::executeRPN("1 9223372036854775800 - 1000 -");
    std::cout << "sample: Error overflow" << std::endl;
    RPN::executeRPN("10 9223372036854775800 *");



}