/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 00:28:35 by yooshima          #+#    #+#             */
/*   Updated: 2025/03/24 16:09:03 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <sstream>
#include <string>
#include <iostream>

class RPN {
    public:
        static int executeRPN(const char *inputStr);

    private:
        RPN();
        RPN(const RPN& src);
        RPN& operator=(const RPN& src);
        ~RPN();

        static std::stack<std::int64_t> _stack;
};
