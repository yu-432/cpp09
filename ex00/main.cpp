/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yooshima <yooshima@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 14:25:19 by yooshima          #+#    #+#             */
/*   Updated: 2025/03/24 00:42:45 by yooshima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Invalid args" << std::endl;
    return EXIT_FAILURE;
  }

  if (BitcoinExchange::executeBtc(argv[1]))
    return EXIT_FAILURE;
  return EXIT_SUCCESS;
}