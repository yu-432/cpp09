/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:33:32 by yooshima          #+#    #+#             */
/*   Updated: 2025/03/24 13:07:17 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int RPN::executeRPN(char *inputStr) {
    std::istringstream iss(inputStr);
    std::string token;
    while (iss >> token) {
        std::cout << token << std::endl;
    }
    return 0;
}
